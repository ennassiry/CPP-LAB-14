
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// 1. Exception pour un montant invalide
class MontantInvalideException : public runtime_error {
public:
    MontantInvalideException(const string& message)
        : runtime_error(message) {
    }
};

// 2. Exception pour un solde insuffisant
class SoldeInsuffisantException : public runtime_error {
public:
    SoldeInsuffisantException(const string& message)
        : runtime_error(message) {
    }
};

// 3. Classe Compte
class Compte {
private:
    string titulaire;
    int solde;

public:
    // Constructeur
    Compte(string nom, int s) {
        titulaire = nom;
        solde = s;
    }

    // Methode pour deposer de l'argent
    void deposer(int montant) {

        if (montant <= 0) {
            throw MontantInvalideException(
                "Le montant du depot doit etre positif !"
            );
        }

        solde += montant;

        cout << "Depot de " << montant
             << " DH effectue avec succes." << endl;
    }

    // Methode pour retirer de l'argent
    void retirer(int montant) {

        if (montant <= 0) {
            throw MontantInvalideException(
                "Le montant du retrait doit etre positif !"
            );
        }

        if (montant > solde) {
            throw SoldeInsuffisantException(
                "Solde insuffisant pour effectuer ce retrait !"
            );
        }

        solde -= montant;

        cout << "Retrait de " << montant
             << " DH effectue avec succes." << endl;
    }

    // Afficher le solde
    void afficherSolde() const {
        cout << "Titulaire : " << titulaire << endl;
        cout << "Solde actuel : " << solde << " DH" << endl;
    }
};

// 4. Programme principal
int main() {

    Compte c("Ahmed", 1000);

    c.afficherSolde();

    // Premier bloc try
    try {

        cout << "\n--- Operation 1 : Depot ---" << endl;
        c.deposer(500);

        cout << "\n--- Operation 2 : Retrait ---" << endl;
        c.retirer(200);

        cout << "\n--- Operation 3 : Retrait ---" << endl;
        c.retirer(2000);

        cout << "\n--- Operation 4 : Depot ---" << endl;
        c.deposer(-100);

    }
    catch (const MontantInvalideException& e) {
        cout << "\nErreur de montant : "
             << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << "\nErreur bancaire : "
             << e.what() << endl;
    }

    cout << "\n--- Etat final du compte ---" << endl;
    c.afficherSolde();

    return 0;
}
