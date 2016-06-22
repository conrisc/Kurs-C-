#include <iostream>
#include "lib.hpp"
#include <string>


int main() {


    ///WCZYTYWANIE
    int rozmiar = 5;
    int tab[rozmiar];
    tab[0] = 32;
    tab[1] = -52;
    tab[2] = 17;
    tab[3] = 195;
    tab[4] = 0;

    double* tab2[rozmiar];
    for (int i=0;i<rozmiar;i++) {
        tab2[i] = new double(5.2-tab[i]+i);
    }
    ///PERMUTACJA
    std::cout<<"\nPERMUTACJA\n";
    obliczenia::permutacja(tab,rozmiar);
    for (int i=0;i<rozmiar;i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;

    ///SORTOWANIE ROSNACO
    std::cout<<"\nSORTOWANIE ROSNACO\n";
    obliczenia::sortuj(tab,rozmiar);
    for (int i=0;i<rozmiar;i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;

    ///SORTOWANIE MALEJACO
    std::cout<<"\nSORTOWANIE MALEJACO\n";
    obliczenia::sortuj(tab,rozmiar,obliczenia::comp2);
    for (int i=0;i<rozmiar;i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;


    ///TABLICA WSKAZNIKOW LICZB RZECZYWISTYCH**********************
    std::cout<<"\n---TABLICA WSKAZNIKOW DLA LICZB RZECZYWISTYCH---\n";

    ///SORTOWANIE ROSNACO
    std::cout<<"\nSORTOWANIE ROSNACO\n";
    obliczenia::sortuj(tab2,rozmiar);
    for (int i=0;i<rozmiar;i++)
        std::cout<<*tab2[i]<<" ";
    std::cout<<std::endl;

    ///SORTOWANIE MALEJACO
    std::cout<<"\nSORTOWANIE MALEJACO\n";
    obliczenia::sortuj(tab2,rozmiar,obliczenia::comp2<double>);
    for (int i=0;i<rozmiar;i++)
        std::cout<<*tab2[i]<<" ";
    std::cout<<std::endl;

    ///TABLICA NAPISOW*********************************************
    std::cout<<"\n---TABLICA NAPISOW (TO JEST ZLE :/)---\n";
    const char* tab3[5];
    tab3[0] = "csudsa";
    tab3[1] = "audsuf";
    tab3[2] = "klzuids";
    tab3[3] = "abusdis";
    tab3[4] = "fioasd";

    ///SORTOWANIE ROSNACO
    std::cout<<"\nSORTOWANIE ROSNACO\n";
    obliczenia::sortuj(tab3,5);
    for (int i=0;i<5;i++) {
        for (int j=0;j<strlen(tab3[i]);j++) {
            std::cout<<tab3[i];
            tab[i]++;
        }
    std::cout<<std::endl;
    }

    ///SORTOWANIE MALEJACO
    std::cout<<"\nSORTOWANIE MALEJACO\n";
    //obliczenia::sortuj(tab3,5,obliczenia::comp2<char*>);
    for (int i=0;i<5;i++) {
        for (int j=0;j<strlen(tab3[i]);j++) {
            std::cout<<tab3[i];
            tab[i]++;
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    ///TABLICA LANCUCHOW ZNAKOWYCH*********************************
    std::cout<<"\n---TABLICA STRINGOW---\n";
    std::string tab4[5];
    tab4[0] = "first";
    tab4[1] = "second";
    tab4[2] = "third";
    tab4[3] = "fourth";
    tab4[4] = "fifth";

    std::cout<<"\nSORTOWANIE ROSNACO\n";
    obliczenia::sortuj(tab4,5);
    for (int i=0;i<5;i++) {
        std::cout<<tab4[i]<<std::endl;
    }

     std::cout<<"\nSORTOWANIE MALEJACO\n";
    obliczenia::sortuj(tab4,5,obliczenia::comp2);
    for (int i=0;i<5;i++) {
        std::cout<<tab4[i]<<std::endl;
    }



    return 0;

}
