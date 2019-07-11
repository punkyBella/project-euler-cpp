#include <iostream>

int divisor_count(int n) {
    int count = 1;
    while (n % 2 == 0) {
        n /= 2;
        ++count;
    }
    for (int k = 3; k <= n; k += 2) {
        int c = 1;
        while (n % k == 0) {
            n /= k;
            ++c;
        }
        count *= c;
    }
    return count;
}

int main() {
    int k = 1, tri = 1;
    while (divisor_count(tri) <= 500) {
        ++k;
        tri += k;
    }
    std::cout << tri << std::endl;
}
