#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using ll = long long;
using ull = unsigned long long;
using ld = long double;

class MathUtils {
public:
    // Вычисление a^n mod m
    static ll binpow(ll a, ll n, ll m = 998244353) {
        ll res = 1;
        a %= m;
        
        while (n > 0) {
            if (n & 1) {
                res = (res * a) % m;
            }
            a = (a * a) % m;
            n >>= 1;
        }
        
        return res;
    }
};

class Solution {
public:
    void solve() {
        ll n, p, mod;
        std::cin >> n >> p >> mod;
        std::cout << MathUtils::binpow(n, p, mod) << std::endl;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Solution solver;
    int ttest = 1;
    // std::cin >> ttest;
    
    while (ttest--) {
        solver.solve();
    }
    
    return 0;
}