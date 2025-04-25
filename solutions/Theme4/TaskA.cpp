#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream input("stdin");
    std::ofstream output("ancestor.out");
    std::string line;

    // Read number of nodes
    std::getline(input, line);
    int n = std::stoi(line);

    // Read ancestors
    std::getline(input, line);
    std::istringstream iss(line);
    std::vector<int> ancestors(n);
    for (int i = 0; i < n; ++i) {
        iss >> ancestors[i];
    }

    // Read number of queries
    std::getline(input, line);
    int q = std::stoi(line);

    // Read queries
    std::vector<std::pair<int, int>> queries;
    for (int i = 0; i < q; ++i) {
        std::getline(input, line);
        std::istringstream iss(line);
        int a, b;
        iss >> a >> b;
        queries.emplace_back(a, b);
    }

    std::vector<int> results;

    for (const auto& query : queries) {
        int a = query.first - 1; // Convert to 0-based index
        int b = query.second - 1; // Convert to 0-based index

        // Check if a is an ancestor of b
        int current = b;
        int is_ancestor = 0;

        while (current != -1) {
            if (current == a) {
                is_ancestor = 1;
                break;
            }
            current = ancestors[current];
        }

        results.push_back(is_ancestor);
    }

    // Output results
    for (const auto& result : results) {
        output << result << '\n';
    }

    return 0;
}