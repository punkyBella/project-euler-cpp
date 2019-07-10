#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int s = 1;
    for (int n = 1; n <= 20; ++n) {
        s *= n / gcd(s, n);
        // now s is divisible by all numbers in [1..n]
    }
    std::cout << s << std::endl;
}
