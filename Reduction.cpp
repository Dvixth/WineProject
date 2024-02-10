//Reductions.cpp

#include "Reduction.hpp"

int Reduction::getFirstentry() const {
    return firstentry;
}

int Reduction::getSecondentry() const {
    return secondentry;
}
float Reduction::getTaux() const {
    return taux;
}
void Reduction::afficherReduction() {
    cout << "Reduction de "<<taux<<"% pour " << firstentry << " bouteilles achete a " << secondentry << " " << taux << endl;
}