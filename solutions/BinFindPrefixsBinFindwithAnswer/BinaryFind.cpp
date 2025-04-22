#include <iostream> 
#include <vector>



bool ok(vector<int> &vec, int k, int d) {
    int cnt = 1;
    int last = vec.front();
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] - last >= d) {
            ++cnt;
            last = vec[i];
        }
    }

    return cnt >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    int l = 1;
    int r = vec.back() - vec.front();
    int ans = r;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (ok(vec, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    freopen("cows.in", "r", stdin);
    freopen("cows.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int ttest = 1;
//    cin >> ttest;
    while(ttest--) solve();
    return 0;
}