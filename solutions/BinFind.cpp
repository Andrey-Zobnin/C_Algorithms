#include <iostream>
#include <vector>
#include <algorithm>

bool CanPlaceBovinesInStallsWithMinimumDistance(
    const std::vector<int>& CoordinatesOfStalls,
    int NumberOfBovinesToPlace,
    int MinimumDistanceBetweenBovines
) {
    int NumberOfBovinesPlaced = 1;
    int LastPositionOccupiedByBovine = CoordinatesOfStalls[0];
    for (size_t CurrentStallIndex = 1; 
         CurrentStallIndex < CoordinatesOfStalls.size(); 
         ++CurrentStallIndex) {
        if (CoordinatesOfStalls[CurrentStallIndex] - 
            LastPositionOccupiedByBovine >= 
            MinimumDistanceBetweenBovines) {
            ++NumberOfBovinesPlaced;
            LastPositionOccupiedByBovine = 
                CoordinatesOfStalls[CurrentStallIndex];
            if (NumberOfBovinesPlaced >= NumberOfBovinesToPlace) {
                return true;
            }
        }
    }
    return NumberOfBovinesPlaced >= NumberOfBovinesToPlace;
}

int FindMaximumPossibleMinimumDistanceBetweenBovines(
    const std::vector<int>& CoordinatesOfStalls,
    int NumberOfBovinesToPlace
) {
    int LowerBoundOfPossibleDistance = 1;
    int UpperBoundOfPossibleDistance = 
        CoordinatesOfStalls.back() - CoordinatesOfStalls.front();
    int MaximumFoundMinimumDistance = 0;

    while (LowerBoundOfPossibleDistance <= UpperBoundOfPossibleDistance) {
        int CurrentDistanceBeingTested = 
            LowerBoundOfPossibleDistance + 
            (UpperBoundOfPossibleDistance - LowerBoundOfPossibleDistance) / 2;
        if (CanPlaceBovinesInStallsWithMinimumDistance(
                CoordinatesOfStalls,
                NumberOfBovinesToPlace,
                CurrentDistanceBeingTested)) {
            MaximumFoundMinimumDistance = CurrentDistanceBeingTested;
            LowerBoundOfPossibleDistance = CurrentDistanceBeingTested + 1;
        } else {
            UpperBoundOfPossibleDistance = CurrentDistanceBeingTested - 1;
        }
    }

    return MaximumFoundMinimumDistance;
}

int main() {
    freopen("cows.in", "r", stdin);
    freopen("cows.out", "w", stdout);
    std::ios::sync_with_stdio(0); 
    std::cin.tie(0);
    
    int TotalNumberOfStallsAvailable;
    int TotalNumberOfBovinesToAccommodate;
    std::cin >> TotalNumberOfStallsAvailable >> TotalNumberOfBovinesToAccommodate;
    
    std::vector<int> StallCoordinates(TotalNumberOfStallsAvailable);
    for (int CurrentStallIndex = 0; 
         CurrentStallIndex < TotalNumberOfStallsAvailable; 
         ++CurrentStallIndex) {
        std::cin >> StallCoordinates[CurrentStallIndex];
    }

    std::sort(StallCoordinates.begin(), StallCoordinates.end());
    int OptimalMinimumDistance = FindMaximumPossibleMinimumDistanceBetweenBovines(
        StallCoordinates,
        TotalNumberOfBovinesToAccommodate
    );
    std::cout << OptimalMinimumDistance << std::endl;

    return 0;
}