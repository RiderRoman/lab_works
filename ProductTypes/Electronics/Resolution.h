#pragma once
#include <cstddef>
#include <string>

class Resolution {
    int width;
    int height;
public:
    Resolution(int w, int h);

    int get_width() const { return this->width; }
    int get_height() const { return this->height; }
    std::string get_screen_resolution() const
        { return std::to_string(get_width()) + "x" + std::to_string(get_height()); }

    void set_width(int width);
    void set_height(int height);
};