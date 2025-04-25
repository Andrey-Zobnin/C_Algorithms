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

#define ll long long

using namespace std;

ll calculateGcd(ll firstNumber, ll secondNumber) {
    if (secondNumber == 0)
        return firstNumber;
    return calculateGcd(secondNumber, firstNumber % secondNumber);
}

ll calculateFastPower(ll baseNumber, ll exponent, ll modulus) {
    if (exponent == 0)
        return 1;
    if (exponent % 2 == 0) {
        ll temp = calculateFastPower(baseNumber, exponent / 2, modulus) % modulus;
        return (temp * temp) % modulus;
    }
    else {
        return ((baseNumber % modulus) * calculateFastPower(baseNumber, exponent - 1, modulus) % modulus) % modulus;
    }
}

void calculatePrimeFactors(ll number, map<ll,ll>& primeFactors) {
    for (int divisor = 2; divisor * divisor <= number; ++divisor) {
        while (number % divisor == 0) {
            primeFactors[divisor]++;
            number /= divisor;
        }
    }
    if (number > 1)
        primeFactors[number]++;
}

ll calculateHashSubstring(int leftIndex, int rightIndex, vector<ll>& prefixHashes, vector<ll>& basePowers, int stringLength) {
    if (leftIndex == 0) {
        return (((prefixHashes[rightIndex] + 1000000007) % 1000000007) * basePowers[stringLength]) % 1000000007;
    }
    return (((prefixHashes[rightIndex] - prefixHashes[leftIndex - 1] + 1000000007) % 1000000007) * basePowers[stringLength - leftIndex]) % 1000000007;
}

int main() {
    string inputString;
    cin >> inputString;

    int stringLength = inputString.size();

    vector<ll> prefixHashes(stringLength);
    vector<ll> basePowers(stringLength + 1);

    basePowers[0] = 1;

    for (int i = 1; i <= stringLength; i++) {
        basePowers[i] = basePowers[i - 1] * 27;
        basePowers[i] %= 1000000007;
    }

    prefixHashes[0] = inputString[0] * basePowers[0];

    for (int i = 1; i < stringLength; i++) {
        prefixHashes[i] = prefixHashes[i - 1] + inputString[i] * basePowers[i];
        prefixHashes[i] %= 1000000007;
    }

    vector<pair<int, int>> matchingLengths;

    for (int i = 0; i < stringLength - 2; i++) {
        ll startHash = calculateHashSubstring(0, i, prefixHashes, basePowers, stringLength);
        ll endHash = calculateHashSubstring(stringLength - i - 1, stringLength - 1, prefixHashes, basePowers, stringLength);
        if (startHash == endHash)
            matchingLengths.push_back({ i + 1, startHash });
    }

    int leftIndex = -1;
    int rightIndex = matchingLengths.size();

    int resultLeft = -1;
    int resultRight = stringLength;

    while (rightIndex - leftIndex > 1) {
        int midIndex = (rightIndex + leftIndex) / 2;
        bool foundMatch = false;
        for (int i = 1; i < stringLength - matchingLengths[midIndex].first; i++) {
            ll midHash = calculateHashSubstring(i, i + matchingLengths[midIndex].first - 1, prefixHashes, basePowers, stringLength);
            if (midHash == matchingLengths[midIndex].second) {
                foundMatch = true;
                resultLeft = i;
                resultRight = i + matchingLengths[midIndex].first - 1;
            }
        }
        if (foundMatch)
            leftIndex = midIndex;
        else
            rightIndex = midIndex;
    }

    if (leftIndex == -1) {
        cout << "Just a legend";
    }
    else {
        for (int i = resultLeft; i <= resultRight; i++)
            cout << inputString[i];
    }
}