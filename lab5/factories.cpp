#include "factories.h"

namespace ui {
    Form* WindowsControlFactory::createForm(double x_pos, double y_pos, double x_scale, double y_scale) {
        Form* form = new Form{x_pos, y_pos, x_scale, y_scale, "windows"};
        return form;
    }

    Label* WindowsControlFactory::createLabel(double x_pos, double y_pos, double x_scale, double y_scale,
                                              const std::string &text) {
        Label* label = new Label{x_pos, y_pos, x_scale, y_scale, "windows", text};
        return label;
    }

    Button* WindowsControlFactory::createButton(double x_pos, double y_pos, double x_scale, double y_scale,
                                                const std::string &text) {
        Button* button = new Button{x_pos, y_pos, x_scale, y_scale, "windows", text};
        return button;
    }

    TextBox* WindowsControlFactory::createTextBox(double x_pos, double y_pos, double x_scale, double y_scale,
                                                  const std::string &text) {
        TextBox* textBox = new TextBox{x_pos, y_pos, x_scale, y_scale, "windows", text};
        return textBox;
    }

    Form* MacOSControlFactory::createForm(double x_pos, double y_pos, double x_scale, double y_scale) {
        Form* form = new Form{x_pos, y_pos, x_scale, y_scale, "macos"};
        return form;
    }

    Label* MacOSControlFactory::createLabel(double x_pos, double y_pos, double x_scale, double y_scale,
                                              const std::string &text) {
        Label* label = new Label{x_pos, y_pos, x_scale, y_scale, "macos", text};
        return label;
    }

    Button* MacOSControlFactory::createButton(double x_pos, double y_pos, double x_scale, double y_scale,
                                                const std::string &text) {
        Button* button = new Button{x_pos, y_pos, x_scale, y_scale, "macos", text};
        return button;
    }

    TextBox* MacOSControlFactory::createTextBox(double x_pos, double y_pos, double x_scale, double y_scale,
                                                  const std::string &text) {
        TextBox* textBox = new TextBox{x_pos, y_pos, x_scale, y_scale, "macos", text};
        return textBox;
    }

    Form* LinuxControlFactory::createForm(double x_pos, double y_pos, double x_scale, double y_scale) {
        Form* form = new Form{x_pos, y_pos, x_scale, y_scale, "linux"};
        return form;
    }

    Label* LinuxControlFactory::createLabel(double x_pos, double y_pos, double x_scale, double y_scale,
                                            const std::string &text) {
        Label* label = new Label{x_pos, y_pos, x_scale, y_scale, "linux", text};
        return label;
    }

    Button* LinuxControlFactory::createButton(double x_pos, double y_pos, double x_scale, double y_scale,
                                              const std::string &text) {
        Button* button = new Button{x_pos, y_pos, x_scale, y_scale, "linux", text};
        return button;
    }

    TextBox* LinuxControlFactory::createTextBox(double x_pos, double y_pos, double x_scale, double y_scale,
                                                const std::string &text) {
        TextBox* textBox = new TextBox{x_pos, y_pos, x_scale, y_scale, "linux", text};
        return textBox;
    }
}