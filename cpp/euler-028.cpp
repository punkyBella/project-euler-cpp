#include <iostream>

int main() {
    const int n = 1001;
    int sum = 1;
    int k = 1;
    for (int i = 2; i < n; i += 2) {
        for (int j = 0; j < 4; ++j) {
            k += i;
            sum += k;
        }
    }
    std::cout << sum << std::endl;
}
