//Fournir.cpp

#include "Fournir.hpp"
#include <iostream>

 Fournir::Fournir(Vin *v, Fournisseur *f, Cave *c, double p): vin(v),fournisseur(f), cave(c), prix(p) {

};

Fournisseur* Fournir::getFournisseur() const {
    return fournisseur;
}

double Fournir::getPrix() const {
    return prix;
}
Vin* Fournir ::getVin() const {
    return vin;
}
void Fournir::setVin(Vin* v) {
    vin = v;
}
