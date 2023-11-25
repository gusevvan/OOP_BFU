#pragma once
#include <iostream>
#include <string>

namespace ui {
    class Control {
    protected:
        double _x_pos, _y_pos, _x_scale, _y_scale;
        std::string _OS_mark;
    public:
        Control(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& mark);
        virtual void setXPos(double x);
        virtual void setYPos(double y);
        virtual void setXScale(double x);
        virtual void setYScale(double y);
        [[nodiscard]] virtual double getXPos();
        [[nodiscard]] virtual double getYPos();
        [[nodiscard]] virtual double getXScale();
        [[nodiscard]] virtual double getYScale();
        virtual ~Control() = default;
    };

    class Label : public Control {
    private:
        std::string _text;
    public:
        Label(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& mark, const std::string& text);
        void setXPos(double x) override;
        void setYPos(double y) override;
        void setXScale(double x) override;
        void setYScale(double y) override;
        [[nodiscard]] double getXPos() override;
        [[nodiscard]] double getYPos() override;
        [[nodiscard]] double getXScale() override;
        [[nodiscard]] double getYScale() override;
        void setText(const std::string& text);
        [[nodiscard]] std::string getText();
    };

    class Button : public Control {
    private:
        std::string _text;
    public:
        Button(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& mark, const std::string& text);
        void setXPos(double x) override;
        void setYPos(double y) override;
        void setXScale(double x) override;
        void setYScale(double y) override;
        [[nodiscard]] double getXPos() override;
        [[nodiscard]] double getYPos() override;
        [[nodiscard]] double getXScale() override;
        [[nodiscard]] double getYScale() override;
        void setText(const std::string& text);
        [[nodiscard]] std::string getText();
        void click();
    };

    class TextBox : public Control {
    private:
        std::string _text;
    public:
        TextBox(double x_pos, double y_pos, double x_scale, double y_scale, const std::string& mark, const std::string& text);
        void setXPos(double x) override;
        void setYPos(double y) override;
        void setXScale(double x) override;
        void setYScale(double y) override;
        [[nodiscard]] double getXPos() override;
        [[nodiscard]] double getYPos() override;
        [[nodiscard]] double getXScale() override;
        [[nodiscard]] double getYScale() override;
        void setText(const std::string& text);
        [[nodiscard]] std::string getText();
        void onValueChanged();
    };
}