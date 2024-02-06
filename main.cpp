#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        int numero;

        cout << "Ingrese un numero entero: ";
        cin >> numero;

        if (cin.fail()) {
            // Si la entrada no es un n�mero entero, lanzar una excepci�n
            throw runtime_error("Error: La entrada no es un numero entero");
        }

        cout << "Numero ingresado: " << numero << endl;

    } catch (const exception& e) {
        // Manejo de la excepci�n
        cerr << "Error: " << e.what() << endl;

        // Limpiar el estado de error del flujo de entrada
        cin.clear();
        // Descartar caracteres no v�lidos en el flujo de entrada
        fflush(stdin);
    }

    // El programa contin�a ejecut�ndose despu�s del bloque try-catch
    cout << "El programa continua ejecutandose..." << endl;

    return 0;
}
