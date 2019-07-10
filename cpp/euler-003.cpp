#include <iostream>

int main() {
    uint64_t n = 600851475143ULL;
    int max_factor = 1;
    for (int k = 2; k < n; ++k) {
        while (n % k == 0) {
            // k must be prime, because all primes < k has been iterated
            max_factor = k;
            n /= k;
        }
    }
    std::cout << max_factor << std::endl;
}
