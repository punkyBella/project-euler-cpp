#include <iostream>

#include "utils.hpp"


bool is_abundant(int n) {
    return divisor_sum(n) - n > n;
}

bool can_be_as_sum(int n) {
    static std::vector<bool> abundant;
    if (abundant.empty()) {
        abundant.resize(28123);
        for (int k = 1; k < abundant.size(); ++k) {
            abundant[k] = is_abundant(k);
        }
    }
    for (int a = 1; a <= n / 2; ++a) {
        if (abundant[a] && abundant[n - a]) return true;
    }
    return false;
}

int main() {
    int sum = 0;
    for (int n = 1; n <= 28123; ++n) {
        if (!can_be_as_sum(n)) sum += n;
    }
    std::cout << sum;
}
