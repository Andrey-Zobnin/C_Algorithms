#include <iostream>
#include <vector> 

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> dp(n + k + 1);
    dp[0] = 1;
    // base dp[0] = 1
    for (int j = 0;  j < n; j++) {
        for (int i = 1; i <= k + 1; i++) {
            dp[i + j] += dp[j];
            dp[i + j] %= 998244353;
    }
    }
    std::cout << dp[n] % 998244353 << std::endl;                                            
    // dp[0] = {1};
}
