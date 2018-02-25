#include "Number.h"

using namespace std;

int main() {
    Number a(20);
    Number b(50);
    Number c(11);

    a.plus(b);
    a.print();
    cout << endl;

    a.minus(b);
    a.print();
    cout << endl;

    a.multiply(b);
    a.print();
    cout << endl;

    a.pow(13);
    a.print();
    cout << endl;

    return 0;
}