#include <iostream>
#include <cstdlib>
using namespace std;


class Asunto {

    public:
    int asukasMaara;
    int neliot;

    void maarita(int a, int b);
    double laskeKulutus(double k);

    Asunto() {
        cout<<"Asunto luotu."<<endl;
    }
};
   void Asunto::maarita(int a, int b){
        asukasMaara = a;
        neliot = b;

        cout<<"Asunto määritetty. Asukkaita: "<<asukasMaara<<". Neliöitä: "<<neliot<<"."<<endl; 
    }

     double Asunto::laskeKulutus(double k) {
        double arvo = k;
        double kulutus = arvo*asukasMaara*neliot;

        cout<<" asunnon kulutus, kun hinta "<<k<<" on yhtä suuri kuin"<<kulutus<<"."<<endl;
        return kulutus;
    }


class Katutaso {

    public:
    Asunto as1;
    Asunto as2;
    void maaritaAsunnot();
    double laskeKulutus(double);

 Katutaso() {
        cout<<"Katutaso luotu."<<endl;
    }
};
    void Katutaso::maaritaAsunnot() {
        cout<<"Määritetään 2 kpl katutason asuntoja."<<endl;
        as1.maarita(2,100);
        as2.maarita(2,100);

    }


class Kerros: public Katutaso {

    public:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;

    virtual void maaritaAsunnot();
    double laskeKulutus(double);
 
 Kerros() {
        cout<<"Kerros luotu."<<endl;
    }
};

void Kerros::maaritaAsunnot() {
    cout<<"Määritetään 4 kpl kerroksen asuntoja."<<endl;
    as1.maarita(2,100);
    as2.maarita(2,100);
    as3.maarita(2,100);
    as4.maarita(2,100);
}

class Kerrostalo {

    public:
    double laskeKulutus(double);
    Kerrostalo(){
    cout<<"Kerrostalo luotu."<<endl;
    cout<<"Määritellään koko kerrostalon kaikki asunnot."<<endl;
    eka.maaritaAsunnot();
    toka.maaritaAsunnot();
    kolmas.maaritaAsunnot();
    }

    private:
    Katutaso eka;
    Kerros toka;
    Kerros kolmas;
    
};






