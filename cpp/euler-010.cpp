#include <iostream>
#include <vector>
#include <cassert>

class PrimeSieve {
    std::vector<bool> bitset;   // bitset[k] == is_prime(2*k + 1)
public:
    PrimeSieve() = default;

    explicit PrimeSieve(uint32_t size) : bitset((size + 1) / 2, true) {
        bitset[0] = false;  // 1 is not prime
        for (int j = 1; (2 * j + 1) * (2 * j + 1) <= 2 * bitset.size() + 1; ++j) {
            for (int k = (2 * j + 1) * (2 * j + 1) / 2; k < bitset.size(); k += 2 * j + 1) {
                bitset[k] = false;
            }
        }
    }

    bool is_prime(uint32_t n) const {
        if (n % 2 == 0) return n == 2;
        if (n < 2 * bitset.size()) return bitset[n / 2];
        for (int k = 3; k * k <= n; k += 2) {
            if (n % k == 0)return false;
        }
        return true;
    }
};

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
