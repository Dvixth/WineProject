// Cave.cpp

#include "Cave.hpp"
#include <iostream>

Cave::Cave(string idc, string nc, string ac) : IdCave(idc), NomCave(nc), AdresseCave(ac), marge(nullptr), vin(nullptr) {
    fournitures = vector<Fournir*>();
}
void Cave::infoCave() {
    cout << "Cave id is: " << IdCave << endl;
    cout << "Cave name is: " << NomCave << endl;
    cout << "Cave address is: " << AdresseCave << endl;
}
// Fonction qui ajoute un vin avec une quantite donnee au stock de la cave si le vin n'existe pas deja dans le stock
void Cave::ajouterVinAvecQuantite(Vin* vin, int quantite) {
    for(auto& entry : vinsStock) {
        if (entry.first == vin) {
            cout << "Vin deja present dans le stock de la cave: " << this->getNomCave() << endl;
            return;
        }
    }
    vinsStock[vin] += quantite;
    cout << "Vin ajoute avec succes au stock de la cave: " << this->getNomCave() << endl;
}
// Fonction qui affiche un message si vinsStock est vide
bool Cave::stockVide() {
    return vinsStock.empty();
}
// Fonction qui va afficher le stock d'une cave avec tous les vins dans ce stock et le fournisseur qui l'a fourni
void Cave::afficherStock() {
    cout << "Stock dans la cave " << NomCave << ": " << endl;
    for (const auto& entry : vinsStock) {
        Vin* vin = entry.first;
        int quantite = entry.second;
        cout << "Vin: " << vin->getNomVin() << " | Quantite en stock: " << quantite;
        Marge* pMarge = vin->getMarge();
        Fournir *fourniture = this->getFourniture(vin->getNomVin(), vin->getMillesime());
        if (fourniture != nullptr) {
            Fournisseur *fournisseur = fourniture->getFournisseur();
            // Recherche de la reduction applicable à la quantite actuelle
            float tauxReduction = 0.0;
            for (Reduction *reduction: fournisseur->getReductions()) {
                if (quantite >= reduction->getFirstentry() && quantite <= reduction->getSecondentry()) {
                    tauxReduction = reduction->getTaux();
                    break;
                }
            }
            // Calcul du prix
            float prixFourniture = fourniture->getPrix();
            float prixApresReduction = prixFourniture - (prixFourniture * tauxReduction / 100);
            float prixFinal = prixApresReduction + (prixApresReduction * pMarge->getTaux() / 100);
            cout << "| Fournisseur: " << fournisseur->getNomFournisseur();
            cout << " au Prix de : " << prixFinal << "$ TTC" << endl;
        } else {
            cout << " | Fourniture introuvable" << endl;
        }
    }
}

// Fonction qui retourne true si le vin existe dans le stock de la cave
bool Cave::vinExiste(Vin* vin) const {
    auto it = vinsStock.find(vin);
    return it != vinsStock.end() && it->second > 0;
}

// Fonction qui retourne la fourniture associee à un vin et un millesime donnes
Fournir* Cave::getFourniture(string nomVin, int millesime) const {
    for (Fournir* fourniture : fournitures) {
        Vin* vin = fourniture->getVin();
        if (vin->getNomVin() == nomVin && vin->getMillesime() == millesime) {
            return fourniture;
        }
    }
    return nullptr;
}

// Fonction qui calcule le prix d'une fourniture en fonction des reductions et de la marge de la cave
float Cave::calculerPrixFourniture(Fournir* fourniture) const {
    Vin* vin = fourniture->getVin();
    int quantite = vinsStock.at(vin);
    Fournisseur* fournisseur = fourniture->getFournisseur();
    // Recherche de la reduction applicable à la quantite actuelle
    float tauxReduction = 0.0;
    for (Reduction* reduction : fournisseur->getReductions()) {
        if(! fournisseur->emptyReductions()){
            if (quantite >= reduction->getFirstentry() && quantite <= reduction->getSecondentry()) {
                tauxReduction = reduction->getTaux();
                break;
            }
        }else{
            cout<<"Il ne y a pas de reduction "<<endl;
        }
    }
    // Calcul du prix
    float prixFourniture = fourniture->getPrix();
    float prixApresReduction = prixFourniture - (prixFourniture * tauxReduction / 100);
    float prixFinal = prixApresReduction + (prixApresReduction * marge->getTaux() / 100);

    return prixFinal;
}
// Fonction qui ajoute une fourniture à la cave
void Cave::ajouterFourniture(Fournir* nouvelleFourniture) {
    fournitures.push_back(nouvelleFourniture);
}

