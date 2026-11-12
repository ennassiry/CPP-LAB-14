
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

// Fonction pour lire un fichier
void lireFichier(string nomFichier) {

    // Creation d'un objet pour lire le fichier
    ifstream fichier(nomFichier);

    // Verification de l'ouverture
    if (!fichier.is_open()) {
        throw runtime_error(
            "Erreur : impossible d'ouvrir le fichier " + nomFichier
        );
    }

    string ligne;

    cout << "Contenu du fichier :" << endl;

    // Lecture ligne par ligne
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }

    // Fermeture du fichier
    fichier.close();
}

// Programme principal
int main() {

    try {
        lireFichier("texte.txt");
    }
    catch (const runtime_error& e) {
        cout << "Exception interceptee : "
             << e.what() << endl;
    }

    cout << "Fin du programme." << endl;

    return 0;
}
