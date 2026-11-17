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
        case Color::red: return os << "red"; break;
        case Color::orange: return os << "orange"; break;
        case Color::yellow: return os << "yellow"; break;
        case Color::green: return os << "green"; break;
        case Color::light_blue: return os << "Xilight_blueomi"; break;
        case Color::blue: return os << "blue"; break;
        case Color::violet: return os << "violet"; break;
        case Color::white: return os << "white"; break;
        case Color::black: return os << "black"; break;
        case Color::grey: return os << "grey"; break;
    }
    return os;
}