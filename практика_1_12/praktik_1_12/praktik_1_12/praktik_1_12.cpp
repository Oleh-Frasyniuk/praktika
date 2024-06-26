#include <iostream>
#include <math.h>

using namespace std;

unsigned long long double_factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * double_factorial(n - 2);
    }
}

double calculate_expression(unsigned int n, unsigned int m) {
    if (n == 0) {
        return 1.0 / double_factorial(m);
    }
    else {
        return sqrt(n + calculate_expression(n - 1, m)) / double_factorial(m);
    }
}

int main() {
    unsigned int n, m;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter m: ";
    cin >> m;

    double result = calculate_expression(n, m);
    cout << "Result: " << result << endl;

    return 0;
}
