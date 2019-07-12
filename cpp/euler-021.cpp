#include <iostream>

#include "utils.hpp"

int main() {
    uint64_t sum = 0;
    for (int n = 1; n < 10000; ++n) {
        uint64_t s = divisor_sum(n) - n;
        if (s != n && divisor_sum(s) - s == n) {
            sum += n;
        }
    }
    std::cout << sum << std::endl;
}
