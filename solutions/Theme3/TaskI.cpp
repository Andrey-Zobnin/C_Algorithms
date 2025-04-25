#include <iostream>
#include <vector>
#include <string>

class StringHasher {
private:
    const long long prime = 137;
    const long long mod = 1e9 + 7;
    std::vector<long long> power;
    std::vector<long long> hashes;
    size_t string_length;

public:
    StringHasher(const std::string& s) : string_length(s.size()) {
        computePowerArray();
        computeHashArray(s);
    }

    void computePowerArray() {
        power.resize(string_length);
        power[0] = 1;
        for (size_t i = 1; i < string_length; ++i) {
            power[i] = (power[i - 1] * prime) % mod;
        }
    }

    void computeHashArray(const std::string& s) {
        hashes.resize(string_length + 1);
        hashes[0] = 0;
        for (size_t i = 1; i <= string_length; ++i) {
            hashes[i] = (hashes[i - 1] + (s[i - 1] - 'a' + 1) * power[string_length - i]) % mod;
        }
    }

    long long getHash(size_t l, size_t r) const {
        // Adjust for 1-based indexing in the original code
        return (hashes[r] - hashes[l - 1] + mod) % mod * power[l - 1] % mod;
    }

    size_t length() const {
        return string_length;
    }
};

class BorderFinder {
public:
    static std::string findLongestBorder(const std::string& s) {
        StringHasher hasher(s);
        size_t n = hasher.length();
        size_t max_border = 0;

        for (size_t i = 1; i <= n - 2; ++i) {
            long long prefix_hash = hasher.getHash(1, i);
            long long suffix_hash = hasher.getHash(n - i + 1, n);

            if (prefix_hash == suffix_hash) {
                for (size_t j = 2; j <= n - i; ++j) {
                    long long middle_hash = hasher.getHash(j, j + i - 1);
                    if (middle_hash == prefix_hash) {
                        max_border = i;
                        break;
                    }
                }
            }
        }

        if (max_border > 0) {
            return s.substr(0, max_border);
        }
        return "Just a legend";
    }
};

int main() {
    std::string input;
    std::cin >> input;
    std::cout << BorderFinder::findLongestBorder(input) << std::endl;
    return 0;
}