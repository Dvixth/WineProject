//Marge.hpp

#ifndef WINEPROJECT_MARGE_HPP
#define WINEPROJECT_MARGE_HPP

#include <iostream>

class Cave;
class Vin;

class Marge {

private :

    float taux;
    Vin *vin;
    Cave *cave;

public:
    Marge(Vin *V, Cave *C, float t);
    float getTaux();
};

#endif
