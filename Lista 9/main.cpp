#include <iostream>
#include "lib.hpp"
#include <cstdlib>
#include <ctime>



int main() {
    std::string exampl;
    std::cin>>calculations::clearline>>calculations::ignore(5)>>exampl;
    std::cout<<exampl<<" - wczytany string (pominiete 5 znakow)";
    std::cout<<"\n---------------------------------\n\n";
    ///TABLICA LICZB TYPU DOUBLE*****************
    srand(time(NULL));
    double tab[10];
    for (int i=0;i<10;i++)
        tab[i] = (rand()%100)-5.25;

    try {
        std::cout<<calculations::array<double>(tab,10)<<std::endl;
    }
    catch (std::string w) {
        std::cout<<w<<std::endl;
    }
    ///TABLICA ZNAKOW CHAR***********************
    char tab2[10];
    for (int i=0;i<10;i++)
        tab2[i] = char((rand()%26)+97);
    std::cout<<calculations::array<char>(tab2,10)<<std::endl;

    ///TABLICA KLASY ARR
    calculations::arr<int> NOWA{5,-3,183,8,0};
    std::cout<<NOWA<<std::endl;
    std::cin>>NOWA;
    std::cout<<NOWA<<std::endl;



    return 0;

}
