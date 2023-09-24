#include <iostream>
#include <cstdlib>
#include "asunto.h"
#include "katutaso.h"
using namespace std;

class Kerros: public Katutaso {

    public:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;

    void maaritaAsunnot();
    double laskeKulutus(double m);

};
