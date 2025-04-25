#include <iostream>
#include <cmath>
#include <utility>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
 
#define LongLong long long
 
using namespace std;
 
LongLong gcd(LongLong a, LongLong b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
LongLong fast_pow(LongLong num, LongLong s, LongLong mod) {
    if (s == 0)
        return 1;
    if (s % 2 == 0) {
        LongLong t = fast_pow(num, s / 2, mod) % mod;
        return (t * t) % mod;
    }
    else {
        return ((num % mod) * fast_pow(num, s - 1, mod) % mod) % mod;
    }
}
 
void factorization(LongLong n, map<LongLong,LongLong>& p) {
    for (int d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            p[d]++;
            n /= d;
        }
    }
    if (n > 1)
        p[n]++;
}
 
vector<LongLong> MOD = { 1000000007 , 1000000009 };
 
LongLong Take_hash(int l, int r, vector<LongLong>& ph, vector<LongLong>& b, const LongLong mod) {
    if (l == 0)
        return ph[r];
    return ((ph[r] - ph[l - 1] * b[r - l + 1] % mod) % mod+ mod) % mod;
}
 
pair<LongLong, LongLong> Take_hash(int l, int r, vector<vector<LongLong>>& ph, vector<vector<LongLong>>& b, int n) {
    if (l == 0)
        return make_pair(ph[0][r], ph[1][r]);
    return make_pair(Take_hash(l, r, ph[0], b[0], MOD[0]), Take_hash(l, r, ph[1], b[1], MOD[1]));
}
 
int main() {
 
    int q;
    cin >> q;
 
    while (q > 0) {
 
        string a;
        int n;
        cin >> n >> a;
 
        vector<vector<LongLong>> ph(2, vector<LongLong>(n));
        vector<vector<LongLong>> b(2, vector<LongLong>(n + 1));
 
        b[0][0] = b[1][0] = 1;
        b[0][1] = 27, b[1][1] = 337;
 
        for (int q = 0; q < 2; ++q) {
            for (int i = 1; i <= n; i++) {
                b[q][i] = b[q][i - 1] * b[q][1];
                b[q][i] %= MOD[q];
            }
        }
 
        ph[0][0] = a[0];
        ph[1][0] = a[0];
        for (int q = 0; q < 2; ++q) {
            for (int i = 1; i < n; i++) {
                ph[q][i] = ph[q][i - 1] * b[q][1] + a[i];
                ph[q][i] %= MOD[q];
            }
        }
 
        set<pair<LongLong,LongLong>> res;
 
 
        auto start = Take_hash(2, n - 1, ph, b, n);
        auto end = Take_hash(0, n - 3, ph, b, n);
 
        res.emplace(start);
        res.emplace(end);
 
        for (int i = 2; i < a.size() - 1; i++) {
            auto pref = Take_hash(0, i - 2, ph, b, n);
            pref.first *= b[0][n - 1 - i] % MOD[0];
            pref.second *= b[1][n - 1 - i] % MOD[1];
 
            auto suff = Take_hash(i + 1, n - 1, ph, b, n);
            res.emplace(make_pair((pref.first + suff.first) % MOD[0], (pref.second + suff.second) % MOD[1]));
        }
 
        cout << res.size() << '\n';
 
        q--;
    }
}
 
