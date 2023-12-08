#include <iostream>
#include "inc/factories.h"
#include <cstring>

int main() {
    std::string os_mark;
    char *ostype = getenv("OSTYPE");
    if (ostype == NULL) {
        ostype = getenv("windir");
        if (ostype != NULL) {
            os_mark = "windows";
        }
    } else {
        if (strcmp(ostype, "linux") == 0) {
            os_mark = "linux";
        } else {
            os_mark = "macos";
        }
    }
    ui::ControlFactory* factory;
    if (os_mark == "windows") {
        factory = new ui::WindowsControlFactory;
    } else {
        if (os_mark == "linux") {
            factory = new ui::LinuxControlFactory;
        } else {
            factory = new ui::MacOSControlFactory;
        }
    }
    ui::Form* form = factory->createForm(0, 0, 100, 100);
    ui::TextBox* textBox = factory->createTextBox(0, 0, 10, 20, "text");
    ui::Button* button = factory->createButton(0, 0, 30, 20, "text");
    ui::Label* label = factory->createLabel(0, 0, 10, 30, "text");
    label->setText("some text");
    form->addControl(textBox);
    form->addControl(button);
    form->addControl(label);
}
