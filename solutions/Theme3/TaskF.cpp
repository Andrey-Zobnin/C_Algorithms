#include <iostream>
#include <map>
#include <set>

class PrimeFactorizer {
public:
    static void factorize(int number, std::map<int, int>& factors, std::set<int>& unique_factors) {
        int m = number;
        for (int i = 2; i * i <= m; i++) {
            while (m % i == 0) {
                factors[i]++;
                unique_factors.insert(i);
                m /= i;
            }
        }
        if (m > 1) {
            factors[m]++;
            unique_factors.insert(m);
        }
    }
};

class SolutionCalculator {
public:
    static int calculateSolution(const std::map<int, int>& factors, const std::set<int>& unique_factors) {
        int pairs = 0;
        int remainders = 0;
        
        for (int factor : unique_factors) {
            pairs += factors.at(factor) / 2;
            remainders += factors.at(factor) % 2;
        }
        
        return pairs + remainders / 3;
    }
};

int main() {
    int test_cases;
    std::cin >> test_cases;
    
    for (int t = 0; t < test_cases; t++) {
        int n;
        std::cin >> n;
        
        std::map<int, int> prime_factors;
        std::set<int> unique_prime_factors;
        
        for (int i = 0; i < n; i++) {
            int number;
            std::cin >> number;
            PrimeFactorizer::factorize(number, prime_factors, unique_prime_factors);
        }
        
        int result = SolutionCalculator::calculateSolution(prime_factors, unique_prime_factors);
        std::cout << result << std::endl;
    }
    
    return 0;
}