#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int kadane(const vector<int>& arr) {
    int maxEndingHere = arr[0], maxSoFar = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

vector<int> minCost(int t, const vector<pair<int, vector<int>>>& testCases) {
    vector<int> results;
    for (const auto& caseData : testCases) {
        int n = caseData.first;
        const vector<int>& arr = caseData.second;
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int maxSubarraySum = kadane(arr);
        int minCostValue = min(maxSubarraySum, totalSum - maxSubarraySum);
        results.push_back(minCostValue);
    }
    return results;
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, vector<int>>> testCases(t);
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        testCases[i] = {n, arr};
    }
    vector<int> results = minCost(t, testCases);
    for (int result : results) {
        cout << result << endl;
    }
    return 0;
}