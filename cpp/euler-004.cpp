#include <iostream>

bool is_palindrome(int n) {
    int origin = n;
    int rev = 0;
    while (n != 0) {
        rev = 10 * rev + n % 10;
        n /= 10;
    }
    return rev == origin;
}

int main() {
    int max = 100 * 100;
    for (int i = 999; i >= 100; --i) {
        for (int j = 999; j >= 100; --j) {
            if (i * j < max) break;
            if (is_palindrome(i * j)) max = i * j;
        }
    }
    std::cout << max << std::endl;
}
