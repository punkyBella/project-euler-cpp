#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>

#include "utils.hpp"

int main() {
    integer a(2);
    integer p = pow(a, 1000);
    const std::vector<uint8_t> &digits = p.digits();
    std::cout << std::accumulate(digits.begin(), digits.end(), 0) << std::endl;
}
