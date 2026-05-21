#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {

    vector<double> datos = {
        25, 30, 32, 35, 36, 38, 40, 42, 45, 46, 
        48, 50, 50, 51, 52, 55, 56, 58, 60, 61, 
        62, 65, 68, 70, 72, 75, 78, 80, 85, 90
    };
    int n = datos.size();

    int k = round(1 + 3.322 * log10(n));
    
    // Rango y Amplitud
    double min_val = *min_element(datos.begin(), datos.end());
    double max_val = *max_element(datos.begin(), datos.end());
    double rango = max_val - min_val;
    double amplitud = ceil(rango / k);

    vector<double> lim_inf(k), lim_sup(k), marca_clase(k);
    vector<int> f(k, 0);
    
    double limite_actual = min_val;
    for (int i = 0; i < k; i++) {
        lim_inf[i] = limite_actual;
        lim_sup[i] = limite_actual + amplitud - 0.1; // Para evitar solapamiento visual
        marca_clase[i] = (lim_inf[i] + (limite_actual + amplitud)) / 2.0;
        

        for (double x : datos) {
            if (x >= lim_inf[i] && (i == k-1 ? x <= max_val : x < limite_actual + amplitud)) {
                f[i]++;
            }
        }
        limite_actual += amplitud;
    }

    cout << "--- Hands-on 4: Tabla Extendida ---" << endl;
    cout << left << setw(8) << "Clase" << setw(15) << "Limites" << setw(5) << "f" 
         << setw(8) << "Xc" << setw(5) << "Fa" << setw(8) << "fr" << setw(8) << "fra" << "%" << endl;
         
    int Fa = 0;
    double fra = 0;
    double suma_fXc = 0;
    int clase_mediana = -1, clase_moda = 0;
    int max_f = 0;

    for (int i = 0; i < k; i++) {
        Fa += f[i];
        double fr = (double)f[i] / n;
        fra += fr;
        suma_fXc += f[i] * marca_clase[i];

        if (f[i] > max_f) {
            max_f = f[i];
            clase_moda = i;
        }

        if (clase_mediana == -1 && Fa >= n / 2.0) {
            clase_mediana = i;
        }

        cout << left << setw(8) << i+1 
             << lim_inf[i] << "-" << lim_sup[i] << "\t"
             << setw(5) << f[i] << setw(8) << marca_clase[i] 
             << setw(5) << Fa << fixed << setprecision(2) << setw(8) << fr 
             << setw(8) << fra << fr * 100 << "%" << endl;
    }

    double media = suma_fXc / n;
    
    double F_ant_mediana = (clase_mediana == 0) ? 0 : (Fa - f[k-1]); // Simplificación para F anterior
    int F_a_temp = 0;
    for(int i=0; i<clase_mediana; i++) F_a_temp += f[i];
    double mediana = lim_inf[clase_mediana] + (((n / 2.0) - F_a_temp) / f[clase_mediana]) * amplitud;

    double d1 = f[clase_moda] - (clase_moda == 0 ? 0 : f[clase_moda - 1]);
    double d2 = f[clase_moda] - (clase_moda == k - 1 ? 0 : f[clase_moda + 1]);
    double moda = lim_inf[clase_moda] + (d1 / (d1 + d2)) * amplitud;

    cout << "\n--- Hands-on 5: Medidas de Tendencia Central ---" << endl;
    cout << "Media: " << media << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Moda: " << moda << endl;

    return 0;
}