#include <iostream>

#include "utils.hpp"

int main() {
    PrimeSieve sieve(1000 * 1000);
    int prod = 0, len = 0;
    for (int a = -999; a < 1000; ++a) {
        for (int b = 0; b <= 1000; ++b) {   // let n = 0
            int n = 0, p;
            while ((p = n * n + a * n + b) > 0 && sieve.is_prime(p)) {
                ++n;
            }
            if (n > len) {
                len = n;
                prod = a * b;
            }
        }
    }
    std::cout << prod << std::endl;
}
