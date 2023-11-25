#pragma once
#include "controls.h"
#include "form.h"

namespace ui {

    class ControlFactory {
    public:
        ControlFactory() = default;
        virtual Form* createForm(double x_pos, double y_pos, double x_scale, double y_scale) = 0;
        virtual Label* createLabel(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) = 0;
        virtual Button* createButton(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) = 0;
        virtual TextBox* createTextBox(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) = 0;
        virtual ~ControlFactory() = default;
    };

    class WindowsControlFactory: public ControlFactory {
    public:
        WindowsControlFactory(): ControlFactory() {};
        Form* createForm(double x_pos, double y_pos, double x_scale, double y_scale) override;
        Label* createLabel(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
        Button* createButton(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
        TextBox* createTextBox(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
    };

    class MacOSControlFactory: public ControlFactory {
    public:
        MacOSControlFactory(): ControlFactory() {};
        Form* createForm(double x_pos, double y_pos, double x_scale, double y_scale) override;
        Label* createLabel(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
        Button* createButton(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
        TextBox* createTextBox(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
    };

    class LinuxControlFactory: public ControlFactory {
    public:
        LinuxControlFactory(): ControlFactory() {};
        Form* createForm(double x_pos, double y_pos, double x_scale, double y_scale) override;
        Label* createLabel(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
        Button* createButton(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
        TextBox* createTextBox(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& text) override;
    };
}
