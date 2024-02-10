#include "Vin.hpp"
#include <iostream>

Vin::Vin(string idv, string rg, string cru, string nv, int ml) : IdVin(idv), Region(rg), Cru(cru), NomVin(nv), Millesime(ml){}

void Vin::infoVin() {
    cout << "Vin id is: " << IdVin << endl;
    cout << "Vin region is: " << Region << endl;
    cout << "Vin cru is: " << Cru << endl;
    cout << "Vin name is: " << NomVin << endl;
    cout << "Vin millesime is: " << Millesime << endl;
}

vector<Fournir*> Vin::getFournitures() const {
    return fournitures;
}

void Vin::addFourniture(Fournir* f) {
    fournitures.push_back(f);
}
Marge* Vin ::getMarge() const {
    return marge;
}
void Vin::setMarge(Marge* m){
    marge=m;
}
string Vin::getIdVin() {
    return IdVin;
}
string Vin::getRegion() {
    return Region;
}
string Vin::getCru() {
    return Cru;
}
string Vin::getNomVin() {
    return NomVin;
}
int Vin::getMillesime() {
    return Millesime;
}
void Vin::setIdVin(string idv) {
    IdVin = idv;
}
void Vin::setRegion(string rg) {
    Region = rg;
}
void Vin::setCru(string cru) {
    Cru = cru;
}
void Vin::setNomVin(string nv) {
    NomVin = nv;
}
void Vin::setMillesime(int ml) {
    Millesime = ml;
}

VinDeConsomation::VinDeConsomation(string idv, string rg, string cru, string nv, int ml, int de) : Vin(idv, rg, cru, nv, ml), DateExp(de) {}
void VinDeConsomation::infoVinConso() {
    infoVin();
    cout << "Vin date expiration is: " << DateExp << endl;
}
int VinDeConsomation::getDateExp() {
    return DateExp;
}

VinDeGarde::VinDeGarde(string idv, string rg, string cru, string nv, int ml, int dc) : Vin(idv, rg, cru, nv, ml), DureeDeConser(dc) {}
void VinDeGarde::infoVinGarde() {
    infoVin();
    cout << "Vin duree de conservation is: " << DureeDeConser << endl;
}
int VinDeGarde::getDureeDeConser() {
    return DureeDeConser;
}

