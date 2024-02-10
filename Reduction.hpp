//Reduction.hpp

#ifndef WINEPROJECT_REDUCTION_HPP
#define WINEPROJECT_REDUCTION_HPP

#include <iostream>

using namespace std;


class Reduction {

private :
    int firstentry;
    int secondentry;
    float taux;
public:
    Reduction(int firstentry, int secondentry, float taux) : firstentry(firstentry), secondentry(secondentry), taux(taux) {}
    void afficherReduction();
    //getters
    int getFirstentry() const ;
    int getSecondentry() const ;
    float getTaux() const ;
    //setters
    void setFirstentry(int firstentry) {
        Reduction::firstentry = firstentry;
    }
    void setSecondentry(int secondentry) {
        Reduction::secondentry = secondentry;
    }
    void setTaux(float taux) {
        Reduction::taux = taux;
    }
};

#endif //WINEPROJECT_REDUCTION_HPP
