#include <iostream>
#include <string>

using namespace std;

const int B[] = {1000,
    900, 500, 400, 100,
    90, 50, 40, 10,
    9, 5, 4, 1};
const string R[] = {"M",
    "CM", "D", "CD", "C",
    "XC", "L", "XL", "X",
    "IX", "V", "IV", "I"};


int arab_bin(const char *x);
string bin_rzym(int x);

int main(int argc,char *argv[]) {

    for (int i=1;i<argc;i++)
        cout<<bin_rzym(arab_bin(argv[i]))<<endl;

return 0;

}
///FUNKCJE

int arab_bin(const char *x) {
    int result = 0;
    //Sprawdzanie poprawnosci wyrazu i zamiana na liczbe dziesietna
    if (x[0]==48) {
            cerr<<"Liczba zaczyna sie od 0.";
            return 0;
    }
    for (int i=0;x[i]!='\0';i++) {
        if (x[i]<48 || 57<x[i]) {
                cerr<<"Liczba zawiera niedozwolone znaki.";
                return 0;
        }
        result *= 10;
        result += (x[i]-48);
        if (i==4) {
                cerr<<"Liczba jest za dluga.";
                return 0;
        }
    }
    return result;
}
string bin_rzym(int x) {
    string result = "";
    //Zamiana na rzymska
    for (int rzymska_lvl = 0;x>0;) {
        if (B[rzymska_lvl]<=x) {
            result += R[rzymska_lvl];
            x -= B[rzymska_lvl];
        }
        else rzymska_lvl++;
    }
    return result;
}
