#include <iostream>
#include <numeric>
#include <vector>

#include "utils.hpp"

int main() {
    integer prod(100);
    for (int n = 99; n > 0; --n) {
        prod = prod*integer(n);        
    }
    const std::vector<uint8_t> &digits = prod.digits();
    std::cout << std::accumulate(digits.begin(), digits.end(), 0) << std::endl;
}
