/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ASTARPATH.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         A* path finder.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#pragma once

#include "always.h"
#include "foot.h"
#include "priorityqueue.h"
#include "tibsun_defines.h"


typedef struct WorkingPathNodeData
{
    CellClass **Cells;
    int CellLevel;
    WorkingPathNodeData *Prev;
} WorkingPathNodeData;


typedef struct WorkingPathNode
{
    WorkingPathNodeData *Data;
    float MovementCost;
    float PathCost;
    int PathLength;
} WorkingPathNode;


typedef struct QueueNodeHierarchical
{
    int BufferDelta;
    int Index;
    float Score;
    int Number;
} QueueNodeRegular;


class AStarPathFinderClass
{
    public:
        AStarPathFinderClass();
        ~AStarPathFinderClass();

        // AStarClass_Get_Adj_Cell_41A570 // 0041A570
        float Get_Movement_Cost(CellClass **from, CellClass **to, bool use_alt, MoveType move, FootClass *object);
        PathType * Find_Path_Regular(Cell *from, Cell *to, FootClass *object, FacingType *final_moves, int max_loops, bool a6 = false);
        // AStarClass_Process_Working_Path_41B250 // 0041B250
        // AStarClass_clear?_41B3A0 // 0041B3A0
        // AStarClass_operator_eq_?_41B480 // 0041B480
        // AStarClass_41B830 // 0041B830
        PathType * Build_Final_Path(WorkingPathNode *nodes, FacingType *moves);
        // AStarClass_Reset?_41B9F0 // 0041B9F0
        // AStarClass_Process_Paths_41BAE0 // 0041BAE0
        // AStarClass_Get_Occupier_41BE60 // 0041BE60
        // AStarClass_41BFA0 // 0041BFA0
        // AStarClass_41BFD0 // 0041BFD0
        // AStarClass_Process_Moves_41BFF0 // 0041BFF0
        int Fixup_Path(FootClass *object, FacingType *final_moves, int *overlap, int number1, int number2, Cell *a7);
        void Optimize_Final_Path(PathType *path, FootClass *object);
        void Adjacent_Cell(FacingType *moves, int a2, int a3, int *a4, Cell *cell_out);
        // AStarClass_Generate_Moves_41CC00 // 0041CC00
        // AStarClass_Reinit_Buffers_41CFA0 // 0041CFA0
        bool Find_Path_Hierarchical(Cell *from, Cell *to, MZoneType mzone, FootClass *object);
        PathType * Find_Path(Cell *from, Cell *to, FootClass *object, FacingType *final_moves, int max_loops, MZoneType mzone, bool a7 = false);
        // AStarClass_Fill_DVector_41DAA0 // 0041DAA0
        // AStarClass_Is_Cell_In_Vector_41DC80 // 0041DC80
        // AStarClass_Add_Cell_To_Vector_41DCE0 // 0041DCE0
        // AStarClass_41DD50 // 0041DD50
        // AStarClass_Attempt_41DF40 // 0041DF40
        // AStarClass_Get_Tunnel_Coords?_41E260 // 0041E260

    public:
        enum PathEnum {
            PATH_0,
            PATH_1,
            PATH_2,
        };

        bool bool_0;                                            // always false
        bool bool_1;                                            // skips 004299D2 if false
        bool bool_2;                                            // always false
        bool boolchar_3;                                        // blocks Process_Paths if false
        float float_4;                                          // used only by "Regular"
        char bool_8;                                            // used as last arg in Can_Enter_Cell call
        void *WorkPathDataHeap;                                 // used only by "Regular"
        void *WorkPathHeap;                                     // used only by "Regular"
        PriorityQueueClass<WorkingPathNode> * RegularQueue;    // confirmish
        void *celllevel_pvoid18;                                // used only by "Regular"
        void *celllevel_pvoid1C;                                // used only by "Regular"
        void *celllevel_costarray1;                             // used only by "Regular"
        void *celllevel_costarray2;                             // used only by "Regular"
        int initedcount;                                        // used by both
        int Speed;                                              // confirmish, used only by "Regular"
        int StartCellLevel;                                     // confirmish, used only by "Regular"
        int EndCellLevel;                                       // confirmish, used only by "Regular"
        bool boolpathfind_38;                                   // 0042D170 was called
        PathEnum __PathsNeedProcessing;                         // used only by "Regular"
        int *pointers_40[3];                                    // used by both
        int *pointers_4C[3];                                    // used only by "Hierarchical"
        float *pointers_58[3];                                  // used only by "Hierarchical"
        void *BufferForHierarchicalQueue;                       // some index, used only by "Hierarchical"
        PriorityQueueClass<QueueNodeHierarchical> * HierarchicalQueue; // confirmish
        int dword_6C;                                           // some index, used only by "Regular"
        Cell __OriginCell;                                      // some index, used only by "Regular"
        DynamicVectorClass<Cell> CellIndexesVector[3];          // some index, used only by "Hierarchical"
        short somearray_BC[1500];                               // some indexes, used by both
        int maxvalues_field_C74[3];                             // some index, used only by "Hierarchical"
};
