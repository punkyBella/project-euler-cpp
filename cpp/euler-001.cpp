#include <iostream>

int main() {
    int n = 1000;
    int sum = 0;

    // brute force, since 1000 is small
    for (int i = 1; i < n; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}
