#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    
    std::vector<int> cost(n), pleasure(n);

    for (int i = 0; i < n; i++) {
        std::cin >> cost[i] >> pleasure[i];
    }
    std::vector<int> dp(m + 1, 0);
    

    for (int i = 0; i < n; ++i) {

        for (int j = m; j >= cost[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - cost[i]] + pleasure[i]);
        }
    }
    std::cout << dp[m] << std::endl;
    
    return 0;
}