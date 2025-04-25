#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sum_of_digits(int x) {
    int sum = 0;
    string str_x = to_string(x);
    for (char digit : str_x) {
        sum += digit - '0';
    }
    return sum;
}

int main(void) {
    const int max_n = 200000;
    vector<long long> digit_sum(max_n + 1, 0);
    for (int i = 1; i <= max_n; ++i) {
        digit_sum[i] = digit_sum[i - 1] + sum_of_digits(i);
    }

    int t;
    cin >> t;
    vector<long long> results;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        results.push_back(digit_sum[n]);
    }
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}