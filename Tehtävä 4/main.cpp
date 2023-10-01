#include <iostream>
#include "asunto.h"
using namespace std;



int main()
{
    Asunto testiasunto;
    Kerros testikerros;
    Katutaso testikatutaso;
    Kerrostalo testikerrostalo;
    //testiasunto.maarita(2,100);
    //testiasunto.laskeKulutus(1);
    //testikatutaso.maaritaAsunnot();   
    //testikerros.maaritaAsunnot(); 
    cout<<"Kerrostalon kulutus on "<<testikerrostalo.laskeKulutus(1)<<endl;

    return 0;
}
