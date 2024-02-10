//Fournir.hpp

#ifndef WINEPROJECT_FOURNIR_HPP
#define WINEPROJECT_FOURNIR_HPP

#include <iostream>
#include "Fournisseur.hpp"
#include "Vin.hpp"
#include "Cave.hpp"

using namespace std;

class Vin;
class Cave;
class Fournisseur;

class Fournir {

private:
    Vin* vin;
    Fournisseur* fournisseur;
    Cave * cave;
    double prix;

public:
    //Constructeur
    Fournir(Vin* v, Fournisseur* f,Cave* c, double p);
    //getters
    double getPrix() const;
    Fournisseur* getFournisseur() const;
    Vin *getVin() const;
    //setters
    void setVin(Vin *v);

};

#endif
