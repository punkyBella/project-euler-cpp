#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

int main() {
    std::ifstream in("files/p022_names.txt");
    std::string all;
    in >> all;
    std::vector<std::string> names;
    auto pos = all.find_first_not_of('"');
    while (pos != std::string::npos) {
        auto end = all.find('"', pos);
        names.push_back(all.substr(pos, end - pos));
        std::cout << pos << "\t" << end << "\t" << names.back() << "\n";
        pos = all.find_first_not_of('"', all.find('"', end + 1));
    }

    std::sort(names.begin(), names.end());
    uint64_t sum = 0;
    for (int i = 0; i < names.size(); ++i) {
        uint64_t value = std::accumulate(names[i].begin(), names[i].end(), uint64_t(0),
                                         [](uint64_t partial_sum, char c) { return partial_sum + (c - 'A' + 1); });
        sum += value * (i + 1);
    }
    std::cout << sum << std::endl;
}
