#pragma once

namespace ui {
    struct Point {
        double position_x = 0, position_y = 0;
        Point(double x, double y): position_x{x}, position_y{y} {};
    };

}
