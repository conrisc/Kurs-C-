#include <iostream>
#include "lib.hpp"

namespace obliczenia {
    LiczbaCalk silnia(int n) {
        if (n>1) return obliczenia::LiczbaCalk(n) * silnia(n-1);
        else return obliczenia::LiczbaCalk(1);
    }
}

int main() {

    obliczenia::LiczbaCalk ex1,ex2,pom1,pom2;
    std::cin>>ex1;
    std::cin>>ex2;
    std::cout<<"\n**Operatory ++ i --\n";
    pom1 = ex1;
    pom2 = ex2;
    std::cout<<pom1++<<"   "<<pom1<<std::endl;
    std::cout<<--pom2<<"   "<<pom2<<std::endl;
    std::cout<<"\n**Przesuniecie bitowe\n";
    pom1 = ex1<<2;
    std::cout<<pom1;
    std::cout<<"\n\n**Mnozenie**********\n";
    pom1 = ex1;
    pom2 = ex2;
    std::cout<<pom1 * pom2;
    std::cout<<"\n\n**Dzielenie**********\n";
    pom1 = ex1;
    pom2 = ex2;
    try {
        std::cout<<pom1 / pom2;
    }
    catch(obliczenia::div0 e) {
        std::cout<<e.what();
    }
    std::cout<<"\n\n**Modulo**********\n";
    pom1 = ex1;
    pom2 = ex2;
    std::cout<<pom1 % pom2;
    std::cout<<"\n\n100!**************\n";
    obliczenia::LiczbaCalk silnia(1);
    obliczenia::silnia(100);

    return 0;

}


