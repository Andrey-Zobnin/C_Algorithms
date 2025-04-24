#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<long long> sizeArray(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sizeArray[i];
    }

    std::unordered_map<long long, int> sizeCount;
    std::unordered_map<long long, std::vector<int>> sizeToPositions;

    for (int i = 0; i < n; ++i) {
        sizeCount[sizeArray[i]]++;
        sizeToPositions[sizeArray[i]].push_back(i + 1);
    }

    std::vector<long long> uniqueSizes;

    for (const auto& entry : sizeCount) {
        if (entry.second == 1) {
            uniqueSizes.push_back(entry.first);
        }
    }

    if (uniqueSizes.size() != 3) {
        std::cout << "Meow meow meow..." << std::endl;
        return 0;
    }

    std::vector<int> positions;
    for (const auto& size : uniqueSizes) {
        positions.insert(positions.end(), sizeToPositions[size].begin(), sizeToPositions[size].end());
    }

    std::sort(positions.begin(), positions.end());

    for (int pos : positions) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    return 0;
}