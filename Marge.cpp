//Marge.cpp

#include "Marge.hpp"
#include "Vin.hpp"

Marge::Marge(Vin *V, Cave *C, float t):vin(V),cave(C),taux(t) {
    cave->setMarge(this);
}

float Marge::getTaux() {
    return taux;
}
