#include <iostream>

bool is_leap_year(int y) {
    if (y % 100 == 0) return y % 400 == 0;
    else return y % 4 == 0;
}

int days_in_month(int y, int m) {
    static int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap_year(y)) return 29;
    else return days[m];
}

int main() {
    int next = 1;    // monday
    int current;
    int count = 0;
    for (int y = 1900; y <= 2000; ++y) {
        for (int m = 1; m <= 12; ++m) {
            current = next;
            next = (current + days_in_month(y, m)) % 7;
            if (y >= 1901 && current == 0) ++count;
        }
    }
    std::cout << count << std::endl;
}
