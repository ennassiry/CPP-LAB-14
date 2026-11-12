
#include <iostream>
#include <stdexcept>

using namespace std;

// Fonction de division securisee
int diviser(int a, int b) {
    if (b == 0) {
        throw runtime_error("Erreur : division par zero impossible !");
    }

    return a / b;
}

int main() {

    try {
        // Premier test
        cout << "10 / 2 = " << diviser(10, 2) << endl;

        // Deuxieme test
        cout << "20 / 5 = " << diviser(20, 5) << endl;

        // Troisieme test : division par zero
        cout << "15 / 0 = " << diviser(15, 0) << endl;

        cout << "Fin du programme." << endl;
    }
    catch (const runtime_error& e) {
        cout << "Exception interceptee : " << e.what() << endl;
    }

    return 0;
}
