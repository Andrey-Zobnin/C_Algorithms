#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class SquareRootFinder {
private:
    static long long findSquareRoot(long long x) {
        long long sq = std::sqrt(x);
        while (sq * sq > x) {
            --sq;
        }
        while ((sq + 1) * (sq + 1) <= x) {
            ++sq;
        }
        
        return sq;
    }

public:
    static long long findMinNumber(long long n) {
        long long left = 1;
        long long right = 2e18;
        long long answer = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sq = findSquareRoot(mid);
            
            if (mid - sq >= n) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return answer;
    }
};

class Solution {
public:
    void solve() {
        long long n;
        std::cin >> n;
        std::cout << SquareRootFinder::findMinNumber(n) << '\n';
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Solution solver;
    int test_cases;
    std::cin >> test_cases;
    
    for (int i = 0; i < test_cases; ++i) {
        solver.solve();
    }
    
    return 0;
}