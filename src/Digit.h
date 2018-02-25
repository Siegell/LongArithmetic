//
// Created by siegell on 2/25/18.
//

#ifndef LONGARITHMETIC_DIGIT_H
#define LONGARITHMETIC_DIGIT_H


#include <iostream>

class Digit {
    int dig;
public:
    Digit();

    Digit(int dig);

    int getDig() const;

    void setDig(int dig);

    void plus(Digit digit);

    void plus(int digit);

    void minus(Digit digit);

    void minus(int digit);

    void mul(Digit digit);

    friend std::ostream &operator<<(std::ostream &os, const Digit &digit);
};


#endif //LONGARITHMETIC_DIGIT_H
