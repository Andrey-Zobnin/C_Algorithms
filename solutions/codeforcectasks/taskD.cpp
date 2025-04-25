#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int t;
    cin >> t; // Читаем количество тестов
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r; // Читаем n, l и r
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Читаем массив a
        }

        int current_score = 0; // Текущий счет
        int tickets = 0; 
        for (int i = 0; i < n; ++i) {
            current_score += a[i]; 
            if (current_score >= l && current_score <= r) {
                tickets++; 
                current_score = 0; 
            }
        }

        cout << tickets << endl; 
    }
    
    return 0;
}
