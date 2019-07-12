#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#include "utils.hpp"

int main() {
    std::set<std::vector<uint8_t>> set; // 100 is small, and set is adequate
    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            set.insert(pow(integer(a), b).digits());
        }
    }
    std::cout << set.size() << std::endl;
}
