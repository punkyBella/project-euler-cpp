#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> primes{2};
    int n = 3;
    while (primes.size() < 10001) {
        if (std::all_of(primes.begin(), primes.end(), [n](int d) { return n % d != 0; })) {
            primes.push_back(n);
        }
        n += 2;
    }
    std::cout << primes.back() << std::endl;
}
