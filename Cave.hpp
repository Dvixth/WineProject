#ifndef WINEPROJECT_CAVE_HPP
#define WINEPROJECT_CAVE_HPP

#include <string>
#include <vector>
#include <list>
#include <map>
#include "Vin.hpp"
#include "Marge.hpp"
#include <algorithm>


class Marge;

using namespace std;

class Cave {

private:
    string IdCave;
    string NomCave;
    string AdresseCave;
    Marge* marge;
    Vin* vin;
    map<Vin*, int> vinsStock;
    vector<Fournir*> fournitures;

public:
    Cave(string idc, string nc, string ac);
    void infoCave();
    void ajouterVinAvecQuantite(Vin* vin, int quantite);
    void afficherStock();
    bool stockVide();
    float calculerPrixFourniture(Fournir *fourniture) const; //méthode pour calculer le prix d'une fourniture
    void ajouterFourniture(Fournir* nouvelleFourniture); //méthode pour ajouter une fourniture a cave
    map <Vin*, int> getVinsStock(){ //méthode pour récupérer le stock d'une cave
        return vinsStock;
    }
    void setVinStock(map<Vin*, int> vS){ //méthode set pour stock
        vinsStock=vS;
    };
    bool vinExiste(Vin* vin) const ;//méthode pour vérifier si un vin existe dans le stock

    //getters
    Fournir *getFourniture(string nomVin, int millesime) const; //méthorde pour récupérer une fourniture
    string getIdCave(){
        return IdCave;
    }
    string getNomCave(){
        return NomCave;
    }
    string getAdresseCave(){
        return AdresseCave;
    }
    Marge* getMarge(){
        return marge;
    }
    //setters
    void setIdCave(string idc){
        IdCave=idc;
    }
    void setNomCave(string nc){
        NomCave=nc;
    }
    void setAdresseCave(string ac){
        AdresseCave=ac;
    }
    void setMarge(Marge* m){
        marge=m;
    }

};
#endif
