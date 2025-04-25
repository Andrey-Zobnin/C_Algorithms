#include <iostream>
#include <vector>
#include <algorithm>

class MinimumCostCalculator {
private:
    std::vector<int> sorted_elements;
    std::vector<std::vector<int>> dp_table;

    void initialize(const std::vector<int>& elements) {
        sorted_elements = elements;
        std::sort(sorted_elements.begin(), sorted_elements.end());
        int n = sorted_elements.size();
        dp_table.resize(n, std::vector<int>(n, 0));
    }

    void computeMinimumCost() {
        int n = sorted_elements.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp_table[i][j] = std::min(dp_table[i + 1][j], dp_table[i][j - 1]) + 
                                 sorted_elements[j] - sorted_elements[i];
            }
        }
    }

public:
    MinimumCostCalculator(const std::vector<int>& elements) {
        initialize(elements);
        computeMinimumCost();
    }

    int getResult() const {
        if (sorted_elements.empty()) return 0;
        return dp_table[0][sorted_elements.size() - 1];
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> elements(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }
    
    MinimumCostCalculator calculator(elements);
    std::cout << calculator.getResult() << std::endl;
    
    return 0;
}