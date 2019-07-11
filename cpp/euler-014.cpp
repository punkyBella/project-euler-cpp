#include <iostream>

int collatz_len(uint64_t n) {
    int k = 1;
    while (n != 1) {
        if (n % 2 == 0) n = n / 2;
        else n = 3 * n + 1;
        ++k;
    }
    return k;
}

int main() {
    int n = 1, max_len = 1;
    const int bound = 1000000;
    // since collen(n) == collen(2*n) - 1, max cannot be in lower half
    for (int k = bound / 2; k < bound; ++k) {
        int len = collatz_len(k);
        if (len > max_len) {
            max_len = len;
            n = k;
        }
    }
    std::cout << n << std::endl;
}
