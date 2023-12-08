#pragma once
#include <vector>
#include "controls.h"

namespace ui {

    class Form {
    private:
        std::vector<Control*> _controls;
        double _x_pos, _y_pos, _x_scale, _y_scale;
        std::string _OS_mark;
    public:
        Form(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& mark);
        void setXPos(double x);
        void setYPos(double y);
        void setXScale(double x);
        void setYScale(double y);
        [[nodiscard]] double getXPos();
        [[nodiscard]] double getYPos();
        [[nodiscard]] double getXScale();
        [[nodiscard]] double getYScale();
        void addControl(Control* control);
    };
}
