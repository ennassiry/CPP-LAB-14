
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// 1. Exception personnalisee
class StockInsuffisantException : public runtime_error {
public:
    StockInsuffisantException(const string& message)
        : runtime_error(message) {
    }
};

// 2. Classe Produit
class Produit {
private:
    string nom;
    int stock;

public:
    // Constructeur
    Produit(string n, int s) {
        nom = n;
        stock = s;
    }

    // Methode pour vendre un produit
    void vendre(int quantite) {

        if (quantite > stock) {
            throw StockInsuffisantException(
                "Stock insuffisant pour le produit : " + nom
            );
        }

        stock -= quantite;

        cout << quantite << " unites de "
             << nom << " vendues." << endl;

        cout << "Stock restant : " << stock << endl;
    }
};

// 3. Programme principal
int main() {

    Produit p("Ordinateur", 10);

    try {
        cout << "Premiere vente :" << endl;
        p.vendre(4);

        cout << "\nDeuxieme vente :" << endl;
        p.vendre(8);

        cout << "\nTroisieme vente :" << endl;
        p.vendre(2);
    }
    catch (const StockInsuffisantException& e) {
        cout << "\nErreur : " << e.what() << endl;
    }

    cout << "\nFin du programme." << endl;

    return 0;
}
