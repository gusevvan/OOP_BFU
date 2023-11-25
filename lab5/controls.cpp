#include "controls.h"

namespace ui {
    Control::Control(double x_pos, double y_pos, double x_scale, double y_scale, const std::string &mark):
            _x_pos{x_pos}, _y_pos{y_pos}, _x_scale{x_scale}, _y_scale{y_scale}, _OS_mark{mark} {
        std::cout << "Create Control.\n";
    }

    void Control::setXPos(double x) {
        _x_pos = x;
        std::cout << "Called method setXPos in base control.\n";
    }

    void Control::setYPos(double y) {
        _y_pos = y;
        std::cout << "Called method setYPos in base control.\n";
    }

    void Control::setXScale(double x) {
        _x_scale = x;
        std::cout << "Called method setXScale in base control.\n";
    }

    void Control::setYScale(double y) {
        _y_scale = y;
        std::cout << "Called method setYScale in base control.\n";
    }

    [[nodiscard]] double Control::getXPos() {
        std::cout << "Called method getXPos in base control.\n";
        return _x_pos;
    }

    [[nodiscard]] double Control::getYPos() {
        std::cout << "Called method getYPos in base control.\n";
        return _y_pos;
    }

    [[nodiscard]] double Control::getXScale() {
        std::cout << "Called method setXScale in base control.\n";
        return _x_scale;
    }

    [[nodiscard]] double Control::getYScale() {
        std::cout << "Called method setYScale in base control.\n";
        return _y_scale;
    }

    Label::Label(double x_pos, double y_pos, double x_scale, double y_scale, const std::string &mark,
                 const std::string &text) :
            Control{x_pos, y_pos, x_scale, y_scale, mark}, _text{text} {
        std::cout << "Create Label.\n";
    }

    void Label::setXPos(double x) {
        _x_pos = x;
        std::cout << "Called method setXPos in Label control.\n";
    }

    void Label::setYPos(double y) {
        _y_pos = y;
        std::cout << "Called method setYPos in Label control.\n";
    }

    void Label::setXScale(double x) {
        _x_scale = x;
        std::cout << "Called method setXScale in Label control.\n";
    }

    void Label::setYScale(double y) {
        _y_scale = y;
        std::cout << "Called method setYScale in Label control.\n";
    }

    [[nodiscard]] double Label::getXPos() {
        std::cout << "Called method getXPos in Label control.\n";
        return _x_pos;
    }

    [[nodiscard]] double Label::getYPos() {
        std::cout << "Called method getYPos in Label control.\n";
        return _y_pos;
    }

    [[nodiscard]] double Label::getXScale() {
        std::cout << "Called method setXScale in Label control.\n";
        return _x_scale;
    }

    [[nodiscard]] double Label::getYScale() {
        std::cout << "Called method setYScale in Label control.\n";
        return _y_scale;
    }

    void Label::setText(const std::string &text) {
        std::cout << "Called method setText in Label control.\n";
        _text = text;
    }

    [[nodiscard]] std::string Label::getText() {
        std::cout << "Called method getText in Label control.\n";
        return _text;
    }

    Button::Button(double x_pos, double y_pos, double x_scale, double y_scale, const std::string &mark,
                   const std::string &text):
            Control{x_pos, y_pos, x_scale, y_scale, mark}, _text{text} {
        std::cout << "Create Button.\n";
    }

    void Button::setXPos(double x) {
        _x_pos = x;
        std::cout << "Called method setXPos in Button control.\n";
    }

    void Button::setYPos(double y) {
        _y_pos = y;
        std::cout << "Called method setYPos in Button control.\n";
    }

    void Button::setXScale(double x) {
        _x_scale = x;
        std::cout << "Called method setXScale in Button control.\n";
    }

    void Button::setYScale(double y) {
        _y_scale = y;
        std::cout << "Called method setYScale in Button control.\n";
    }

    [[nodiscard]] double Button::getXPos() {
        std::cout << "Called method getXPos in Button control.\n";
        return _x_pos;
    }

    [[nodiscard]] double Button::getYPos() {
        std::cout << "Called method getYPos in Button control.\n";
        return _y_pos;
    }

    [[nodiscard]] double Button::getXScale() {
        std::cout << "Called method setXScale in Button control.\n";
        return _x_scale;
    }

    [[nodiscard]] double Button::getYScale() {
        std::cout << "Called method setYScale in Button control.\n";
        return _y_scale;
    }

    void Button::setText(const std::string &text) {
        std::cout << "Called method setText in Button control.\n";
        _text = text;
    }

    [[nodiscard]] std::string Button::getText() {
        std::cout << "Called method getText in Button control.\n";
        return _text;
    }

    void Button::click() {
        std::cout << "Called method click in Button control.\n";
    }

    TextBox::TextBox(double x_pos, double y_pos, double x_scale, double y_scale, const std::string &mark,
                     const std::string &text):
            Control{x_pos, y_pos, x_scale, y_scale, mark}, _text{text} {
        std::cout << "Create TextBox.\n";
    }

    void TextBox::setXPos(double x) {
        _x_pos = x;
        std::cout << "Called method setXPos in TextBox control.\n";
    }

    void TextBox::setYPos(double y) {
        _y_pos = y;
        std::cout << "Called method setYPos in TextBox control.\n";
    }

    void TextBox::setXScale(double x) {
        _x_scale = x;
        std::cout << "Called method setXScale in TextBox control.\n";
    }

    void TextBox::setYScale(double y) {
        _y_scale = y;
        std::cout << "Called method setYScale in TextBox control.\n";
    }

    [[nodiscard]] double TextBox::getXPos() {
        std::cout << "Called method getXPos in TextBox control.\n";
        return _x_pos;
    }

    [[nodiscard]] double TextBox::getYPos() {
        std::cout << "Called method getYPos in TextBox control.\n";
        return _y_pos;
    }

    [[nodiscard]] double TextBox::getXScale() {
        std::cout << "Called method setXScale in TextBox control.\n";
        return _x_scale;
    }

    [[nodiscard]] double TextBox::getYScale() {
        std::cout << "Called method setYScale in TextBox control.\n";
        return _y_scale;
    }

    void TextBox::setText(const std::string &text) {
        std::cout << "Called method setText in TextBox control.\n";
        _text = text;
    }

    [[nodiscard]] std::string TextBox::getText() {
        std::cout << "Called method getText in TextBox control.\n";
        return _text;
    }

    void TextBox::onValueChanged() {
        std::cout << "Called method onValueChanged in TextBox control.\n";
    }

}
