#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>

int main() {
    std::stack<int> stack;
    std::vector<int> elements{0};
    int s = 1;
    for (int i = 1; i < 10; ++i) {
        s *= i;
        stack.push(s);
        elements.push_back(i);
    }

    int n = 1000000 - 1;
    std::vector<int> result;
    while (!stack.empty()) {
        int idx = n / stack.top();
        result.push_back(elements[idx]);
        n %= stack.top();
        stack.pop();
        elements.erase(elements.begin() + idx);
    }
    result.push_back(elements[0]);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << std::endl;
}
