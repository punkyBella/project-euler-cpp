#include <iostream>
#include <vector>
#include <cassert>

#include "utils.hpp"

int main() {
    const int n = 2000000;
    PrimeSieve sieve(n);
    uint64_t sum = 2;
    for (int i = 3; i < n; i += 2) {
        if (sieve.is_prime(i)) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}
