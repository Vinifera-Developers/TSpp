/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for the game mouse interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "scroll.h"
#include "ttimer.h"


class MouseClass : public ScrollClass
{
public:
    MouseClass();
    MouseClass(const NoInitClass& x);
    ~MouseClass();

    /**
     *  GScreenClass
     */
    virtual void One_Time() override;
    virtual void Init_Clear() override;
    virtual void AI(KeyNumType& input, Point2D& xy) override;
    virtual void Set_Default_Mouse(MouseType mouse, bool wsmall = false) override;
    virtual bool Override_Mouse_Shape(MouseType mouse, bool wsmall = false) override;
    virtual void Revert_Mouse_Shape() override;
    virtual void Mouse_Small(bool wsmall = true) override;

    /**
     *  DisplayClass
     */
    virtual HRESULT Load(IStream* pStm) override;
    virtual HRESULT Save(IStream* pStm) override;
    virtual MouseType Get_Mouse_Shape() const override;

    int Get_Mouse_Current_Frame(MouseType mouse, bool wsmall = false) const; // 005622D0
    Point2D Get_Mouse_Hotspot(MouseType mouse) const;                        // 00562310
    int Get_Mouse_Start_Frame(MouseType mouse) const;                        // 00563220
    int Get_Mouse_Frame_Count(MouseType mouse) const;                        // 00563240

    int Get_Mouse_First_Frame(MouseType mouse, bool wsmall) const
    {
        MouseStruct const* control = &MouseControl[mouse];

        if (wsmall) {
            if (control->SmallFrame != -1) {
                return control->SmallFrame;
            }
        }

        return control->StartFrame;
    }

public:
    bool IsSmall;
    MouseType CurrentMouseShape;
    MouseType NormalMouseShape;
    int Frame;

public:
    typedef struct MouseStruct {
        int StartFrame; // Starting frame number.
        int FrameCount; // Number of animation frames.
        int FrameRate;  // Frame delay between changing frames.
        int SmallFrame; // Start frame number for small version (if any).
        int X, Y;       // Hotspot X and Y offset.
    } MouseStruct;

    static MouseStruct* MouseControl;

    static ShapeSet const*& MouseShapes;
    static CDTimerClass<SystemTimerClass>& Timer;
};
