#include <iostream>
#include <vector>
using namespace std;

void sieve_of_eratosthenes(vector<bool>& primes, int upper_limit) {
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= upper_limit; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= upper_limit; j += i) {
                primes[j] = false;
            }
        }
    }
}

void print_primes_in_range(const vector<bool>& primes, int lower, int upper) {
    for (int num = lower; num <= upper; ++num) {
        if (primes[num]) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main() {
    int lower_bound, upper_bound;
    cin >> lower_bound >> upper_bound;
    
    vector<bool> is_prime(upper_bound + 1, true);
    sieve_of_eratosthenes(is_prime, upper_bound);
    print_primes_in_range(is_prime, lower_bound, upper_bound);
    
    return 0;
}