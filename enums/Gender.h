#pragma once
#include <iostream>

enum class Gender {
    male,
    female
};

inline std::ostream& operator<<(std::ostream& os, Gender gender) {
    switch(gender) {
        case Gender::male: return os << "male"; break;
        case Gender::female: return os << "female"; break;
    }
    return os;
}