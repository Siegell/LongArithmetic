//
// Created by siegell on 2/25/18.
//

#include "Digit.h"

Digit::Digit() = default;

Digit::Digit(int dig) : dig(dig) {}

int Digit::getDig() const {
    return dig;
}

void Digit::setDig(int dig) {
    Digit::dig = dig;
}

std::ostream &operator<<(std::ostream &os, const Digit &digit) {
    os << digit.dig;
    return os;
}

void Digit::plus(Digit digit) {
    dig += digit.dig;
}

void Digit::minus(Digit digit) {
    dig -= digit.dig;
}

void Digit::minus(int digit) {
    dig -= digit;
}

void Digit::mul(Digit digit) {
    dig *= digit.dig;
}

void Digit::plus(int digit) {
    dig += digit;
}
