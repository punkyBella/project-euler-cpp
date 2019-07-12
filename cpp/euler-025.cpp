#include <iostream>

#include "utils.hpp"

int main() {
    int b = 2;
    integer fa(1), fb(1);
    while (fb.digits().size() < 1000) {
        integer fc = fa + fb;
        fa = fb;
        fb = fc;
        ++b;
    }
    std::cout << b << std::endl;
}
