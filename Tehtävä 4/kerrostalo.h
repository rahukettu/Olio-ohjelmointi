#include <iostream>
#include <cstdlib>
#include "katutaso.h"
#include "kerros.h"
using namespace std;

class Kerrostalo {

    public:
    double laskeKulutus(double j);

    private:
    Katutaso eka;
    Kerros toka;
    Kerros kolmas;

};