#include <iostream>
#include <fstream>
#include <string>

class Fichier {
private:
    std::fstream* fichier;
    std::string nomFichier;

public:
    // Constructor
    Fichier(const std::string& nom) : nomFichier(nom) {
        fichier = new std::fstream;
    }

    // Destructor
    ~Fichier() {
        delete fichier;
        std::cout << "Mémoire du flux libérée." << std::endl;
    }

    // Method to write data
    void sauvegarder(const std::string& texte) {
        fichier->open(nomFichier, std::ios::out);
        if (fichier->is_open()) {
            std::cout << "Sauvegarde des données..." << std::endl;
            *fichier << texte;
            fichier->close();
        }
    }

    // Method to read data
    void charger() {
        fichier->open(nomFichier, std::ios::in);
        if (fichier->is_open()) {
            std::cout << "Lecture des données..." << std::endl;
            std::string ligne;
            std::cout << "Contenu du fichier :" << std::endl;
            while (getline(*fichier, ligne)) {
                std::cout << ligne << std::endl;
            }
            fichier->close();
        }
    }
};

int main() {
    Fichier monFichier("test.txt");

    monFichier.sauvegarder("Bonjour, ceci est un test.");
    monFichier.charger();

    return 0;
}
