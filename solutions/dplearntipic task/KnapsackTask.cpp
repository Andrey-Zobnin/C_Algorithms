#include <iostream>
#include <vector>

int main() {
    
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> w(n), c(n);

    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i]; 
    }
    std::vector<long long> dp(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    
    std::cout << dp[m] << std::endl;
    return 0;
}