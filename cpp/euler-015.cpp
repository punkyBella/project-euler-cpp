#include <iostream>
#include <vector>

int main() {
    const int n = 20;
    std::vector<std::vector<uint64_t>> grid(n + 1, std::vector<uint64_t>(n + 1));
    for (int i = 0; i <= n; ++i) {
        // can only wlk straight along axis
        grid[i][0] = grid[0][i] = 1;

    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // can either walk from upper or left
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }

    std::cout << grid[n][n] << "\t";
}
