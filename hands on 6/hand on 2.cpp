#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 6, 8, 10};
    int n = x.size();

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }


    double B_1 = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double B_0 = (sum_y - B_1 * sum_x) / n;


    cout << "--- Hands-on 2: Simple Linear Regression ---" << endl;
    cout << "Ecuacion de Regresion: y_hat = " << B_0 << " + " << B_1 << "*x1" << endl;


    vector<double> nuevos_x = {6, 7, 8, 9, 10}; // Valores no conocidos
    cout << "\nPredicciones de Sales (Y) para nuevos valores de Advertising (X):" << endl;
    for (int i = 0; i < 5; i++) {
        double y_pred = B_0 + B_1 * nuevos_x[i];
        cout << "X = " << nuevos_x[i] << " -> Y_pred = " << y_pred << endl;
    }

    return 0;
}