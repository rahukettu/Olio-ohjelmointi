#include <iostream>
#include "chef.h"

using namespace std;

int main()
{
    Chef cooknro1("Gordon Ramsay");
    cooknro1.makeSalad();
    cooknro1.makeSoup();

    Chef cooknro2("Anthony Bourdain");
    cooknro2.makeSalad();
    cooknro2.makeSoup();
    
    Chef finnishcook("Jyrki");
    finnishcook.makeSalad();
    finnishcook.makeSoup();

    ItalianChef cooknro3("Mario",100,250);
    cooknro3.makePasta();
    
    return 0;
}



