/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  LZW compression engine.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "lzw.h"
#include "buffpipe.h"
#include "buffstraw.h"


LZWEngine::LZWEngine()
{
    Reset();
}


void LZWEngine::Reset()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        Dict[i].Make_Unused();
    }
}


int LZWEngine::Compress(Buffer const& input, Buffer const& output)
{
    BufferStraw instraw(input);
    BufferPipe outpipe(output);

    int outcount = 0;
    CodeType string_code = END_OF_STREAM;
    CodeType next_code = FIRST_CODE;

    string_code = 0;
    if (instraw.Get(&string_code, sizeof(char)) == 0) {
        string_code = END_OF_STREAM;
    }

    for (;;) {

        unsigned char character;
        if (instraw.Get(&character, sizeof(character)) == 0) break;

        int index = Find_Child_Node(string_code, character);

        if (index != -1 && Dict[index].CodeValue != -1) {
            string_code = Dict[index].CodeValue;
        } else {

            if (index != -1 && next_code <= MAX_CODE) {
                Dict[index] = CodeClass(next_code, string_code, character);
                next_code++;
            }

            outcount += outpipe.Put(&string_code, sizeof(string_code));
            string_code = character;
        }
    }

    outcount += outpipe.Put(&string_code, sizeof(string_code));
    if (string_code != END_OF_STREAM) {
        string_code = END_OF_STREAM;
        outcount += outpipe.Put(&string_code, sizeof(string_code));
    }

    return outcount;
}


int LZWEngine::Uncompress(Buffer const& input, Buffer const& output)
{
    int outcount = 0;
    BufferStraw instraw(input);
    BufferPipe outpipe(output);

    CodeType old_code;
    if (instraw.Get(&old_code, sizeof(old_code)) == 0) {
        return outcount;
    }

    unsigned char character = (unsigned char)old_code;
    outcount += outpipe.Put(&character, sizeof(character));

    unsigned int count;
    CodeType new_code;
    CodeType next_code = FIRST_CODE;
    for (;;) {

        if (instraw.Get(&new_code, sizeof(new_code)) == 0) break;

        if (new_code == END_OF_STREAM) break;

        if (new_code >= next_code) {
            Decode_Stack[0] = character;
            count = 1;
            count += Decode_String(&Decode_Stack[1], old_code);
        } else {
            count = Decode_String(Decode_Stack, new_code);
        }

        character = Decode_Stack[count - 1];
        while (count > 0) {
            --count;
            outcount += outpipe.Put(&Decode_Stack[count], sizeof(Decode_Stack[0]));
        }

        if (next_code <= MAX_CODE) {
            Dict[next_code] = CodeClass(next_code, old_code, character);
            next_code++;
        }
        old_code = new_code;
    }

    return outcount;
}


int LZWEngine::Make_LZW_Hash(CodeType code, char character)
{
    return ((((int)(unsigned char)character) << (BITS - 8)) ^ (int)code);
}


int LZWEngine::Find_Child_Node(CodeType parent_code, char child_character)
{
    int hash_index = Make_LZW_Hash(parent_code, child_character);

    int offset = 1;
    if (hash_index != 0) {
        offset = TABLE_SIZE - hash_index;
    }

    int initial = hash_index;
    while (!Dict[hash_index].Is_Matching(parent_code, child_character)) {

        if (Dict[hash_index].Is_Unused()) break;

        hash_index -= offset;
        if (hash_index < 0) {
            hash_index += TABLE_SIZE;
        }

        if (initial == hash_index) {
            hash_index = -1;
            break;
        }
    }
    return hash_index;
}


int LZWEngine::Decode_String(char* ptr, CodeType code)
{
    int count = 0;
    while (code > 255) {
        *ptr++ = Dict[code].CharValue;
        count++;
        code = Dict[code].ParentCode;
    }
    *ptr = (char)code;
    count++;
    return count;
}
