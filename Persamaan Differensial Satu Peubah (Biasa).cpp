#include <iostream>
#include <cmath> // ini library untuk fungsi matematika seperti abs() dan tan()
using namespace std;

int tan(double x) {
    double sum = 0;
    double term = x;
    int n = 1;

    while (abs(term) > 1e-6) {
        sum += term;
        n++;
        term *= -x * x / (n * (n - 1));
    }

    return sum;
}

int f(double x, double y) {
    return 1 + y*y;
}

int y_euler (double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; i++) {
        y += h * f(x, y);
        x += h;
    }

    return y;
}

int heun (double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; i++) {
        double k1 = f(x, y);
        double k2 = f(x + h, y + h * k1);
        y += (h / 2) * (k1 + k2);
        x += h;
    }

    return y;
}

int runge_kutta_3 (double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; i++) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + h * k1 / 2);
        double k3 = f(x + h, y - h * k1 + 2 * h * k2);
        y += (h / 6) * (k1 + 4*k2 + k3);
        x += h;
    }

    return y;
}

int runge_kutta_4 (double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; i++) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + h * k1 / 2);
        double k3 = f(x + h / 2, y + h * k2 / 2);
        double k4 = f(x + h, y + h * k3);
        y += (h / 6) * (k1 + 2*k2 + 2*k3 + k4);
        x += h;
    }

    return y;
}


int main () {
    double x0 = 0, y0 = 0;
    double h = cin >> h;
    cout << "Enter the maximum value of y: ";
    double y_max = cin >> y_max;
    int n = y_max / h;
    cout << "Euler's method: " << y_euler(x0, y0, h, n) << endl;
    cout << "Heun's method: " << heun(x0, y0, h, n) << endl;
    cout << "Runge-Kutta 3rd order method: " << runge_kutta_3(x0, y0, h, n) << endl;
    cout << "Runge-Kutta 4th order method: " << runge_kutta_4(x0, y0, h, n) << endl;
    cout << "Exact solution: " << tan(x0) << endl;
}