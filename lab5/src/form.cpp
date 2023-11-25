#include "../inc/form.h"

namespace ui {
    Form::Form(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& mark):
            _x_pos{x_pos}, _y_pos{y_pos}, _x_scale{x_scale}, _y_scale{y_scale}, _OS_mark(mark) {
        std::cout << "Create Form.\n";
    }

    void Form::setXPos(double x) {
        _x_pos = x;
        std::cout << "Called method setXPos in Form.\n";
    }

    void Form::setYPos(double y) {
        _y_pos = y;
        std::cout << "Called method setYPos in Form.\n";
    }

    void Form::setXScale(double x) {
        _x_scale = x;
        std::cout << "Called method setXScale in Form.\n";
    }

    void Form::setYScale(double y) {
        _y_scale = y;
        std::cout << "Called method setYScale in Form.\n";
    }

    [[nodiscard]] double Form::getXPos() {
        std::cout << "Called method getXPos in Form.\n";
        return _x_pos;
    }

    [[nodiscard]] double Form::getYPos() {
        std::cout << "Called method getYPos in Form.\n";
        return _y_pos;
    }

    [[nodiscard]] double Form::getXScale() {
        std::cout << "Called method getXScale in Form.\n";
        return _x_scale;
    }

    [[nodiscard]] double Form::getYScale() {
        std::cout << "Called method getYScale in Form.\n";
        return _y_scale;
    }

    void Form::addControl(Control* control)  {
        _controls.push_back(control);
        std::cout << "Called method addControl in Form.\n";
    }

}
