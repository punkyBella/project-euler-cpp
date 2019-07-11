#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<std::vector<int>> grid;
    std::ifstream in("files/p067_triangle.txt");
    std::string line;
    while (std::getline(in, line)) {
        grid.emplace_back();
        std::istringstream line_in(line);
        std::copy(std::istream_iterator<int>(line_in), std::istream_iterator<int>(), std::back_inserter(grid.back()));
    }
    for (int i = grid.size() - 2; i >= 0; --i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            grid[i][j] += std::max(grid[i + 1][j], grid[i + 1][j + 1]);
        }
    }
    std::cout << grid[0][0] << std::endl;
}
