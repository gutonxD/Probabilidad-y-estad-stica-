#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  
    int matriz[2][2] = {
        {7, 3}, 
        {2, 6}  
    };

    // Totales
    int B = matriz[0][0] + matriz[0][1];   // Total Llueve = 10
    int B_prima = matriz[1][0] + matriz[1][1]; // Total No Llueve = 8
    int A = matriz[0][0] + matriz[1][0];   // Total Nublado = 9
    int A_prima = matriz[0][1] + matriz[1][1]; // Total No Nublado = 9
    int total = B + B_prima;               // Total general = 18

    cout << fixed << setprecision(3);
    cout << "--- Hands-on 6: Probabilidades ---" << endl;

    cout << "\n1. Probabilidades Marginales:" << endl;
    cout << "P(Nublado) = " << A << "/" << total << " = " << (double)A / total << endl;
    cout << "P(No Nublado) = " << A_prima << "/" << total << " = " << (double)A_prima / total << endl;
    cout << "P(Llueve) = " << B << "/" << total << " = " << (double)B / total << endl;

    cout << "\n2. Probabilidades Conjuntas:" << endl;
    cout << "P(Llueve Y Nublado) = " << matriz[0][0] << "/" << total << " = " << (double)matriz[0][0] / total << endl;
    cout << "P(No Llueve Y No Nublado) = " << matriz[1][1] << "/" << total << " = " << (double)matriz[1][1] / total << endl;

    cout << "\n3. Probabilidades Condicionales:" << endl;

    cout << "P(Llueve | Nublado) = " << matriz[0][0] << "/" << A << " = " << (double)matriz[0][0] / A << endl;
  
    cout << "P(Nublado | Llueve) = " << matriz[0][0] << "/" << B << " = " << (double)matriz[0][0] / B << endl;

    return 0;
}