#include <iostream>
#include <random>
#include <ctime>
#include "lib.hpp"
#include <string>


int main() {


    ///WCZYTYWANIE
    int rozmiar;
    std::cin>>rozmiar;
    int tab[rozmiar];
    for (int i=0;i<rozmiar;i++)
        std::cin>>tab[i];

    double* tab2[rozmiar];
    for (int i=0;i<rozmiar;i++) {
        tab2[i] = new double(5.2-tab[i]+i);
    }
    ///PERMUTACJA
    std::cout<<"\nPERMUTACJA\n";
    permutacja(tab,rozmiar);
    for (int i=0;i<rozmiar;i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;

    sort<int> obj;

    ///SORTOWANIE ROSNACO
    std::cout<<"\nSORTOWANIE ROSNACO\n";
    sort<int>::sortuj(tab,rozmiar);
    for (int i=0;i<rozmiar;i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;

    ///SORTOWANIE MALEJACO
    std::cout<<"\nSORTOWANIE MALEJACO\n";
    sort<int>::sortuj(tab,rozmiar,comp2);
    for (int i=0;i<rozmiar;i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;




    ///TABLICA WSKAZNIKOW LICZB RZECZYWISTYCH**********************
    std::cout<<"\nTABLICA WSKAZNIKOW DLA LICZB RZECZYWISTYCH\n";

    ///SORTOWANIE ROSNACO
    std::cout<<"\nSORTOWANIE ROSNACO\n";
    sort<double*>::sortuj(tab2,rozmiar);
    for (int i=0;i<rozmiar;i++)
        std::cout<<*tab2[i]<<" ";
    std::cout<<std::endl;

    ///SORTOWANIE MALEJACO
    std::cout<<"\nSORTOWANIE MALEJACO\n";
    sort<double*>::sortuj(tab2,rozmiar,comp2);
    for (int i=0;i<rozmiar;i++)
        std::cout<<*tab2[i]<<" ";
    std::cout<<std::endl;

    ///TABLICA NAPISOW*********************************************
    std::cout<<"\nTABLICA NAPISOW\n";
    const char* tab3[5];
    tab3[0] = "lol";
    tab3[1] = "dasd";
    tab3[2] = "rwedsf";
    tab3[3] = "asDdsz";
    tab3[4] = "sfdx";

    ///SORTOWANIE ROSNACO
    std::cout<<"\nSORTOWANIE ROSNACO\n";
    sort<const char*>::sortuj(tab3,5);
    for (int i=0;j<strlen(tab3[i]);i++)
        for (int j=0;j<strlen(tab3[i]);j++) {
            std::cout<<tab3[i];
            tab3[i]++;
        }
    std::cout<<std::endl;

    ///SORTOWANIE MALEJACO
    std::cout<<"\nSORTOWANIE MALEJACO\n";
    sort<const char*>::sortuj(tab3,5,comp2);
    for (int i=0;i<5;i++) {
        for (int j=0;j<strlen(tab3[i]);j++) {
            std::cout<<tab3[i];
            tab3[i]++;
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    ///TABLICA LANCUCHOW ZNAKOWYCH*********************************
    std::string tab4[rozmiar];






    return 0;

}
