//
// Created by siegell on 2/25/18.
//

#include "Number.h"

Number::Number() = default;

void Number::print() {
    for (auto i = num.end() - 1; i >= num.begin(); --i) {
        cout << *i;
    }
}

Number::Number(int number) {
    while (number > 10) {
        Digit dig(number % 10);
        num.push_back(dig);
        number /= 10;
    }
    Digit dig(number);
    num.push_back(dig);
}

void Number::plus(Number number) {
    extend(number);
    for (int i = 0; i < num.size(); ++i) {
        num[i].plus(number.num[i]);
    }
    check();
    number.check();
}

void Number::extend(Number &number) {
    while (num.size() < number.num.size()) {
        Digit digit(0);
        this->num.push_back(digit);
    }
    while (num.size() > number.num.size()) {
        Digit digit(0);
        number.num.push_back(digit);
    }
}

void Number::check() {
    for (auto i = num.begin(); i < num.end() - 1; i++) {
        (*(i + 1)).plus((*i).getDig() / 10);
        (*i).setDig((*i).getDig() % 10);
    }
    if ((*(num.end() - 1)).getDig() > 9) {
        Digit digit((*(num.end() - 1)).getDig() / 10);
        (*(num.end() - 1)).setDig((*(num.end() - 1)).getDig() % 10);
        num.push_back(digit);
    }
    for (auto i = num.end() - 1; (i >= num.begin()) && ((*i).getDig() == 0); --i) {
        num.erase(i);
    }
}

void Number::minus(Number number) {
    extend(number);
    for (int i = 0; i < num.size(); ++i) {
        num[i].minus(number.num[i]);
        if (num[i].getDig() < 0) {
            num[i + 1].minus(1);
            num[i].plus(10);
        }
    }
    check();
    number.check();
}

void Number::multiply(Number number) {
    Number outNumber(0);
    for (int i = 0; i < num.size(); ++i) {
        Number tempNumber;
        tempNumber.num = number.num;
        for (auto j = tempNumber.num.begin(); j < tempNumber.num.end(); ++j) {
            j->mul(num[i]);
        }
        tempNumber.check();
        for (int j = 0; j < i; ++j) {
            tempNumber.num.insert(tempNumber.num.begin(), Digit(0));
        }
        outNumber.plus(tempNumber);
    }
    num = outNumber.num;
    check();
}

void Number::pow(int n) {
    Number outNumber(1);
    while (n > 0) {
        if (n % 2 == 1) {
            outNumber.multiply(*this);
        }
        this->multiply(*this);
        n /= 2;
    }
    this->num = outNumber.num;
    check();
}
