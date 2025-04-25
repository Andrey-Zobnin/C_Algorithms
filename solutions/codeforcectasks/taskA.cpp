#include <iostream>
#include <cmath>
#include <iomanip>

double initParametrs(int a, int b, int c, int d, int x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double findRoot(int a, int b, int c, int d) {
    long double left = -1e10, right =1e10;
    while ((right - left) > 1e-9) {
        long double mid = (left + right) / 2;
        if (initParametrs(a, b, c, d) * initParametrs(a, b, c, d) < 0) {
            right = mid;
        }
        else {
            left = mid;
        }
        if (initParametrs(a, b, c, d) * initParametrs(a, b, c, d) < 0) {
            left = mid;
        }
        else {
            right = mid;
        }

    }
    return (left + right) / 2;
}

int main() {
    freopen("cubroot.in", "r", stdin);
    freopen("cubroot.out", "w", stdout);
}