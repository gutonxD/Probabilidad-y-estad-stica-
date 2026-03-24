#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct ModelCoefficients {
    double b0;
    double b1;
};

ModelCoefficients calculate_slr_coefficients(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.empty()) {
        return {0.0, 0.0};
    }

    int n = x.size();
    double sum_x = 0;
    double sum_y = 0;
    double sum_xx = 0;
    double sum_xy = 0;

    for (int i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xx += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    double denominator = (n * sum_xx - sum_x * sum_x);
    if (std::abs(denominator) < 1e-9) {
         return {0.0, 0.0};
    }

    double b1 = (n * sum_xy - sum_x * sum_y) / denominator;
    double b0 = (sum_y - b1 * sum_x) / n;

    return {b0, b1};
}

double predict_sales(double b0, double b1, double advertising_value) {
    return b0 + b1 * advertising_value;
}

int main() {
    std::vector<double> advertising_data = {43.60, 50.44, 59.01, 66.30, 82.36, 92.15, 100.51, 110.06, 111.51};
    std::vector<double> sales_data = {1261.08, 1475.28, 1657.52, 2059.05, 2303.76, 2512.64, 2751.46, 2787.67, 2939.13};

    std::cout << "--- Hands-on 2: Implementacion SLR ---" << std::endl;
    std::cout << "Dataset del Caso Benetton:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "| Advertising | Sales     |" << std::endl;
    for (size_t i = 0; i < advertising_data.size(); ++i) {
        std::cout << "| " << std::setw(11) << advertising_data[i] << " | " << std::setw(9) << sales_data[i] << " |" << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;

    ModelCoefficients coeffs = calculate_slr_coefficients(advertising_data, sales_data);

    std::cout << "\n1. Ecuacion de Regresion:" << std::endl;
    std::cout << "y^ = " << std::fixed << std::setprecision(4) << coeffs.b0 << " + " << coeffs.b1 << " * x1" << std::endl;

    std::vector<double> test_advertising_values = {30.0, 75.0, 105.0, 125.0, 150.0};

    std::cout << "\n2. Predicciones para nuevos valores de Advertising:" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "| Advertising | Predicted Sales (y^)     |" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    for (double test_val : test_advertising_values) {
        double predicted_sales = predict_sales(coeffs.b0, coeffs.b1, test_val);
        std::cout << "| " << std::setw(11) << std::fixed << std::setprecision(2) << test_val << " | " 
                  << std::setw(24) << std::fixed << std::setprecision(2) << predicted_sales << " |" << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "\nPresiona Enter para salir..." << std::endl;
    std::cin.get();
    return 0;
}