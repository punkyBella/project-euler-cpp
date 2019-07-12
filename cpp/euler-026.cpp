#include <iostream>
#include <unordered_map>

int circle_len(int n) {
    std::unordered_map<int, int> map{};
    int d = 1;  // denominator
    int i = 0;  // position after dot
    while (map.find(d) == map.end()) {
        if (d % n == 0)
            return 0;
        map[d] = i;
        // int q = d / n;
        d = d % n * 10;
        ++i;
    }
    return i - map[d];
}

int main() {
    int max_len = 0, n = 1;
    for (int i = 2; i < 1000; ++i) {
        if (circle_len(i) > max_len) {
            max_len = circle_len(i);
            n = i;
        }
    }
    std::cout << n << std::endl;
}
