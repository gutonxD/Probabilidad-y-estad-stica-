#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
 
    double dataset[] = {1.5, 211.5, 1.5, 3.2, 2.5, 1.5, 4.8, 3.2, 2.5, 1.5};
    int n = 10; 

    double clases[10]; 
    int frecuencias[10];
    int num_clases = 0; 

    for (int i = 0; i < n; i++) {
        double valor_actual = dataset[i];
        bool ya_existe = false;

      
        for (int j = 0; j < num_clases; j++) {
            if (clases[j] == valor_actual) {
                frecuencias[j] = frecuencias[j] + 1;
                ya_existe = true;
                break; 
            }
        }

       
        if (ya_existe == false) {
            clases[num_clases] = valor_actual;
            frecuencias[num_clases] = 1; 
            num_clases = num_clases + 1; 
        }
    }

    cout << "TABLA DE FRECUENCIAS\n\n";
    cout << left << setw(10) << "CLASE" 
         << right << setw(5) << "f" 
         << right << setw(20) << "fr" 
         << right << setw(10) << "%" << "\n\n";

    int suma_f = 0;
    double suma_fr = 0.0;
    double suma_porcentaje = 0.0;

    for (int i = 0; i < num_clases; i++) {
        double fr = (double)frecuencias[i] / n;
        double porcentaje = fr * 100.0;

        suma_f = suma_f + frecuencias[i];
        suma_fr = suma_fr + fr;
        suma_porcentaje = suma_porcentaje + porcentaje;

      
        cout << left << setw(10) << fixed << setprecision(2) << clases[i];
        cout << right << setw(5) << frecuencias[i];
        
        cout << right << setw(10) << frecuencias[i] << " / " << left << setw(3) << n << " = " 
             << fixed << setprecision(2) << fr;
             
        cout << right << setw(7) << fixed << setprecision(0) << porcentaje << "%" << "\n";
    }

   
    cout << "---------------------------------------------------\n";
    cout << left << setw(10) << "TOTAL" 
         << right << setw(5) << suma_f 
         << right << setw(20) << fixed << setprecision(2) << suma_fr 
         << right << setw(9) << fixed << setprecision(0) << suma_porcentaje << "%" << "\n";

    system("pause");
    return 0;
}