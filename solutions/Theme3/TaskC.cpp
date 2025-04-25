#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
  
int main(void) {
    int n = 0, array=0;
    std::cin >> n;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            array += 1;
            if(i != n/i) {
            array++;
        }

        }
        
    }
    std::cout << array;
    return 0;
}