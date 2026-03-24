#define _CONSOLE 1
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

int main() {
    std::vector<double> data = {
        25.1, 26.5, 27.8, 28.4, 29.9, 30.1, 31.5, 32.2, 33.7, 34.1,
        35.6, 36.8, 37.2, 38.9, 39.4, 40.5, 41.1, 42.6, 43.3, 44.8,
        45.9, 46.2, 47.7, 48.1, 49.6, 50.3, 51.8, 52.4, 53.9, 54.5, 56.1
    };

    int n = data.size();
    
    int k = std::round(1 + 3.322 * std::log10(n));

    double min_val = *std::min_element(data.begin(), data.end());
    double max_val = *std::max_element(data.begin(), data.end());
    double width = (max_val - min_val) / k;

    std::vector<double> lower_limits(k);
    std::vector<double> upper_limits(k);
    std::vector<int> f(k, 0);
    std::vector<double> Xc(k);
    std::vector<int> Fa(k);
    std::vector<double> fr(k);
    std::vector<double> fra(k);
    std::vector<double> percentage(k);

    for (int i = 0; i < k; ++i) {
        lower_limits[i] = min_val + i * width;
        upper_limits[i] = (i == k - 1) ? max_val : min_val + (i + 1) * width;
        
        Xc[i] = (lower_limits[i] + upper_limits[i]) / 2.0;

        for (double val : data) {
            if (i == k - 1) {
                if (val >= lower_limits[i] && val <= upper_limits[i]) f[i]++;
            } else {
                if (val >= lower_limits[i] && val < upper_limits[i]) f[i]++;
            }
        }
    }

    int current_Fa = 0;
    double current_fra = 0.0;

    for (int i = 0; i < k; ++i) {
        current_Fa += f[i];
        Fa[i] = current_Fa;

        fr[i] = (double)f[i] / n;
        
        current_fra += fr[i];
        fra[i] = current_fra;

        percentage[i] = fr[i] * 100.0;
    }
    
    fra[k-1] = 1.00;

    std::cout << "--- Hands-on 4: Tabla de Frecuencia Extendida ---" << std::endl;
    std::cout << "Total de datos (n): " << n << std::endl;
    std::cout << "Clases calculadas (k): " << k << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------\n";
    std::cout << "| Clase | Limite de clase | Frec (f) | Punto Medio (Xc) | Fa  | fr   | fra  | Porcentaje % |\n";
    std::cout << "-------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < k; ++i) {
        std::cout << "| " << std::setw(5) << i + 1 << " | "
                  << std::fixed << std::setprecision(2) << std::setw(6) << lower_limits[i] << " - " 
                  << std::setw(5) << upper_limits[i] << " | "
                  << std::setw(8) << f[i] << " | "
                  << std::setw(16) << std::fixed << std::setprecision(2) << Xc[i] << " | "
                  << std::setw(3) << Fa[i] << " | "
                  << std::setw(4) << std::fixed << std::setprecision(2) << fr[i] << " | "
                  << std::setw(4) << std::fixed << std::setprecision(2) << fra[i] << " | "
                  << std::setw(10) << std::fixed << std::setprecision(2) << percentage[i] << " % |" << std::endl;
    }
    std::cout << "-------------------------------------------------------------------------------------------------\n";
    std::cout << "| TOTAL |                 | " << std::setw(8) << n << " |                  |     | " 
              << std::setw(4) << std::fixed << std::setprecision(2) << 1.00 << " |      |     100.00 % |\n";
    std::cout << "-------------------------------------------------------------------------------------------------\n";

    std::cout << "\nPresiona ENTER para cerrar la terminal...";
    std::cin.get(); 

    return 0;
}