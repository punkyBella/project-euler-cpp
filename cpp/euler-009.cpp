#include <iostream>

int main() {
    for (int a = 1; 3 * a < 1000; ++a) {  // since a < b < c && a + b + c == 1000
        for (int b = a + 1; a + 2 * b < 1000; ++b) {
            int c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                std::cout << a * b * c << std::endl;
                return 0;
            }
        }
    }
}
