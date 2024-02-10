#ifndef WINEPROJECT_VIN_HPP
#define WINEPROJECT_VIN_HPP

#include <string>
#include "Fournir.hpp"
#include "Marge.hpp"

using namespace std;


class Vin {

private:
    string IdVin;
    string Region;
    string Cru;
    string NomVin;
    int Millesime;
    vector<Fournir*> fournitures;
    Marge* marge;

public:
    Vin(string idv, string rg, string cru, string nv, int ml);
    void infoVin();
    void addFourniture(Fournir* f);  // méthode d'ajout d'une fourniture
    //getters
    string getIdVin();
    string getRegion();
    string getCru();
    string getNomVin();
    int getMillesime();
    Marge *getMarge() const; //méthode pour récupérer la marge d'un vin
    vector<Fournir*> getFournitures() const;  //méthode pour récupérer les fournitures d'un vin
    //setters
    void setIdVin(string idv);
    void setRegion(string rg);
    void setCru(string cru);
    void setNomVin(string nv);
    void setMillesime(int ml);
    void setMarge(Marge* m); //méthode pour modifier la marge d'un vin

};

//Class Vin de Consomation qui hérite de Vin
class VinDeConsomation : public Vin {
private:
    int DateExp;

public:
    VinDeConsomation(string idv, string rg, string cru, string nv, int ml, int de);
    void infoVinConso();
    int getDateExp();
};
//Class Vin de Garde qui hérite de Vin
class VinDeGarde : public Vin {
private:
    int DureeDeConser;

public:
    VinDeGarde(string idv, string rg, string cru, string nv, int ml, int dc);
    void infoVinGarde();
    int getDureeDeConser();
};
#endif
