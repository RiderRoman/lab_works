#pragma once
#include <iostream>

enum class Color {
    red,
    orange,
    yellow,
    green,
    light_blue,
    blue,
    violet,
    white,
    black,
    grey
};

inline std::ostream& operator<<(std::ostream& os, Color color) {
    switch(color) {
        case Color::red: return os << "red";
        case Color::orange: return os << "orange";
        case Color::yellow: return os << "yellow";
        case Color::green: return os << "green";
        case Color::light_blue: return os << "Xilight_blueomi";
        case Color::blue: return os << "blue";
        case Color::violet: return os << "violet";
        case Color::white: return os << "white";
        case Color::black: return os << "black";
        case Color::grey: return os << "grey";
    }
}