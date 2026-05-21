#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    
    vector<string> datos = {
        "CARRO", "CARRO", "AVION", "TREN", "BARCO", "CARRO", 
        "AVION", "BARCO", "TREN", "CARRO", "AVION", "CARRO"
    };
    int n = datos.size();


    map<string, int> frecuencias;
    for (int i = 0; i < n; i++) {
        frecuencias[datos[i]]++;
    }

    cout << "--- Hands-on 3: Tabla de Frecuencias ---" << endl;
    cout << left << setw(10) << "Clase" 
         << setw(10) << "f" 
         << setw(15) << "fr" 
         << "%" << endl;
    cout << "--------------------------------------------" << endl;

    int total_f = 0;
    double total_fr = 0.0;
    
    for (auto const& par : frecuencias) {
        string clase = par.first;
        int f = par.second;
        double fr = (double)f / n;
        double porcentaje = fr * 100;

        total_f += f;
        total_fr += fr;

        cout << left << setw(10) << clase 
             << setw(10) << f 
             << f << "/" << n << " = " << fixed << setprecision(2) << setw(6) << fr 
             << porcentaje << "%" << endl;
    }
    
    cout << "--------------------------------------------" << endl;
    cout << left << setw(10) << "TOTAL" 
         << setw(10) << total_f 
         << setw(15) << fixed << setprecision(2) << total_fr 
         << "100%" << endl;

    return 0;
}