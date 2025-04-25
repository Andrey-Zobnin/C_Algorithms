#include <iostream>

class PrimeChecker {
public:
    static bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;

        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
};

class SemiPrimeChecker {
public:
    static bool checkSemiPrime(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int j = n / i;
                if (PrimeChecker::isPrime(i) && PrimeChecker::isPrime(j) && i != j) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
};

int main() {
    int number;
    std::cin >> number;

    if (SemiPrimeChecker::checkSemiPrime(number)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}