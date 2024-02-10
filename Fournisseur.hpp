//Fournisseur.hpp

#ifndef WINEPROJECT_FOURNISSEUR_HPP
#define WINEPROJECT_FOURNISSEUR_HPP

#include <string>
#include <vector>
#include "Reduction.hpp"
#include <algorithm>

using namespace std;


class Fournir;

class Fournisseur {

private:
    string IdFournisseur;
    string NomFournisseur;
    string AdresseFournisseur;
    Fournir *fournir;
    vector<Reduction*> reductions;

public:
    //Constructeur
    Fournisseur(string idf, string nf, string af) : IdFournisseur(idf), NomFournisseur(nf), AdresseFournisseur(af){}
    void infoFournisseur();
    //Méthode d'ajout d'une réduction dans la liste des réduction du fournisseur
    void ajouterReduction(Reduction* reduction) {
        reductions.push_back(reduction);
    }
    //getters
    vector<Reduction*> getReductions() const {
        return reductions;
    }
    bool emptyReductions() const {
        return reductions.empty();
    }

    string getIdFournisseur() const {
        return IdFournisseur;
    }
    string getNomFournisseur() const {
        return NomFournisseur;
    }
    string getAdresseFournisseur() const {
        return AdresseFournisseur;
    }
    //setters
    void setIdFournisseur(string idf) {
        IdFournisseur = idf;
    }
    void setNomFournisseur(string nf) {
        NomFournisseur = nf;
    }
    void setAdresseFournisseur(string af) {
        AdresseFournisseur = af;
    }
};

#endif
