/*

def fibonacci(n):
    if n == 0:
        return 0
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

print(fibonacci(10))  # 55

*/

#include <iostream>
#include <vector>

long long fibonachi(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    std::vector<long long> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i -2];
    } 
    return dp[n];
}

int main() {
    int n = 10;
    std::cout << "Fibonacci(" << n << ") = " << fibonachi(n) << std::endl;
    return 0;
}