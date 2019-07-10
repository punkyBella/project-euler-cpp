#include <iostream>
#include <vector>

int main() {
    std::vector<int> fib{1, 1};
    int n;
    while ((n = fib[fib.size() - 1] + fib[fib.size() - 2]) < 4000000) {
        fib.push_back(n);
    }

    int sum = 0;
    for (int n : fib) {
        if (n % 2 == 0) {
            sum += n;
        }
    }
    std::cout << sum << std::endl;
}
