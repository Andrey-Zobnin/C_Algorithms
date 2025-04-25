#include <iostream>
#include <vector>
#include <string>

class StringHasher {
private:
    const int prime = 41;
    const int mod = 1e9 + 7;
    std::vector<int> prefix_hashes;
    std::vector<int> powers;

public:
    StringHasher(const std::string& s) {
        computePowers(s.length());
        computePrefixHashes(s);
    }

    void computePowers(size_t length) {
        powers.push_back(1);
        for (size_t i = 0; i < length; ++i) {
            powers.push_back((powers[i] * prime) % mod);
        }
    }

    void computePrefixHashes(const std::string& s) {
        prefix_hashes.push_back(0);
        prefix_hashes.push_back(s[0] - 'a' + 1);
        for (size_t i = 1; i < s.length(); ++i) {
            long long hash = (prefix_hashes[i] * prime) % mod;
            hash = (hash + (s[i] - 'a' + 1)) % mod;
            prefix_hashes.push_back(hash);
        }
    }

    int getHash(int a, int b) const {
        long long hash = prefix_hashes[b + 1] - prefix_hashes[a] * powers[b - a + 1] % mod;
        return (hash + mod) % mod;
    }
};

class BorderFinder {
public:
    static std::string findLongestBorder(const std::string& s) {
        StringHasher hasher(s);
        int n = s.length();

        for (int i = n - 1; i > 0; --i) {
            if (hasher.getHash(0, i - 1) == hasher.getHash(n - i, n - 1)) {
                for (int j = 1; j < n - i; ++j) {
                    if (hasher.getHash(0, i - 1) == hasher.getHash(j, j + i - 1)) {
                        return s.substr(0, i);
                    }
                }
            }
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