#include <iostream>

class PrimeChecker {
public:
    static bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
};

class PrimeFactorizer {
public:
    static void factorize(int n) {
        if (PrimeChecker::isPrime(n)) {
            std::cout << n;
            return;
        }

        for (int i = 2; i <= n; ++i) {
            if (n % i == 0 && PrimeChecker::isPrime(i)) {
                while (n % i == 0) {
                    std::cout << i << ' ';
                    n /= i;
                }
            }
        }
    }
};

int main() {
    int number;
    std::cin >> number;
    PrimeFactorizer::factorize(number);
    return 0;
}