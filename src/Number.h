//
// Created by siegell on 2/25/18.
//

#ifndef LONGARITHMETIC_NUMBER_H
#define LONGARITHMETIC_NUMBER_H

#include "Digit.h"
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class Number {
    vector<Digit> num;

    void check();

    void extend(Number &number);

public:
    Number();

    Number(int number);

    void print();

    void plus(Number number);

    void minus(Number number);

    void multiply(Number number);

    void pow(int n);
};


#endif //LONGARITHMETIC_NUMBER_H
