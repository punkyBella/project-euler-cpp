#include <iostream>

int main() {
    int n = 100;
    int s1 = 0, s2 = 0;
    // brute force, since 100 is small
    for (int k = 1; k <= n; ++k) {
        s1 += k;
        s2 += k * k;
    }
    int diff = s1 * s1 - s2;
    std::cout << diff << std::endl;
}
