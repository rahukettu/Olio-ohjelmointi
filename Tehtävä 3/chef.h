#include <iostream>
#include <cstdlib>
using namespace std;


class Chef {

    protected:
        string name;

    public:
        Chef(string n) {
            name=n;
            cout<<name << " konstruktori."<<endl;
        }
        ~Chef() {
            cout<<name << " destruktori."<<endl;
        }
        void makeSalad() {
            cout<<name << " makes salad."<<endl;
        }
        void makeSoup() {
            cout<<name << " makes soup."<<endl;
        }
};

class ItalianChef: public Chef {

     private:
        int vesi;
        int jauhot;
   
    public:
        ItalianChef(string k, int v, int j):Chef(k) {
            name=k;
            vesi=v;
            jauhot=j;

            cout<<name << " konstruktori."<<endl;
        }
        ~ItalianChef() {
            cout<<name << " destruktori."<<endl;
        }
        string getName() {
            return name;
        }
        void makePasta() {
            cout<<name << " makes pasta with special recipe."<<endl;
            cout<<name << " uses jauhot = " <<jauhot <<endl;
            cout<<name << " uses vesi = " <<vesi <<endl;
        }

  
};




