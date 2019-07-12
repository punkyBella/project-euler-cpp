#include <iostream>

#include "utils.hpp"

template<typename F>
void dfs(int num, int sum, int e, F f) {
    if (num > sum + pow(9, e))
        return;  // if num > sum + 9^e, then 10*num > sum + 9^e && 100*num > sum + 2*9^e && ...
    if (num == sum) f(num);
    for (int d = 0; d < 10; ++d) {
        dfs(10 * num + d, sum + pow(d, e), e, f);
    }
}

template<typename F>
void search(int e, F f) {
    for (int d = 1; d < 10; ++d) {
        dfs(d, pow(d, e), e, f);
    }
}

int main() {
    int sum = -1;   // subtract 1
    search(5, [&sum](int n) { sum += n; });
    std::cout << sum << std::endl;
}
