#include <iostream>
#include <cassert>
#include <cstring>

const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
                      "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *hundred = "hundred";
const char *thousand = "thousand";

// optimize: pre-compute strlen values
int letter_count_helper(uint32_t n) {
    if (n >= 1000) return strlen(ones[n / 1000]) + strlen(thousand) + letter_count_helper(n % 1000);
    if (n >= 100)
        return strlen(ones[n / 100]) + strlen(hundred)
               + ((n % 100 == 0) ? 0 : (strlen("and") + letter_count_helper(n % 100)));
    if (n >= 20) return strlen(tens[n / 10]) + strlen(ones[n % 10]);
    return strlen(ones[n]);
}

int letter_count(uint32_t n) {
    assert(n < 10000);
    if (n == 0) return strlen("zero");
    return letter_count_helper(n);
}

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        sum += letter_count(i);
    }
    std::cout << sum << std::endl;
}
