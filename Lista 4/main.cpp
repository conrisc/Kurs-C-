#include "tabbit.hpp"
#include "tabbit.cpp"
#include <iostream>

using namespace std;

int main() {

    tab_bit tab(2);
    tab_bit wynik(4);
    cout<<"Podaj dwa bity: ";
    for (int i=0;i==0;) {
        try {
            cin>>tab;
            i++;
        }
        catch(string w) {
            cout<<w<<endl;
        }
    }
    cout<<"Podaj cztery bity: ";
    for (int i=0;i==0;) {
        try {
            cin>>wynik;
            i++;
        }
        catch(string w) {
            cout<<w<<endl;
        }
    }

    cout<<endl<<"1. Test operatorow | & ^"<<endl;
    cout<<"  Alternatywa: "<<tab[0]<<" | "<<tab[1]<<" = "<<(tab[0] | tab[1])<<endl;
    cout<<"  Koniunkcja:  "<<tab[0]<<" & "<<tab[1]<<" = "<<(tab[0] & tab[1])<<endl;
    cout<<"  XOR:         "<<tab[0]<<" ^ "<<tab[1]<<" = "<<(tab[0] ^ tab[1])<<endl;

    cout<<endl<<"2. Test operatorow |= &= ^= oraz !"<<endl;
    ///ALTERNATYWA
        cout<<"  Alternatywa: "<<wynik[0]<<" |= "<<tab[0];
        wynik[0] |= tab[0];
        cout<<" is "<<wynik[0]<<endl;
    ///KONIUNKCJA
        cout<<"  Koniunkcja:  "<<wynik[1]<<" &= "<<tab[0];
        wynik[1] &= tab[0];
        cout<<" is "<<wynik[1]<<endl;
    ///XOR
        cout<<"  XOR:         "<<wynik[2]<<" ^= "<<tab[0];
        wynik[2] ^= tab[0];
        cout<<" is "<<wynik[2]<<endl;
    ///ZAPRZECZENIE
        cout<<endl<<"  Zaprzeczenie: !"<<wynik[3]<<" = "<<!wynik[3]<<endl;

    tab_bit A(8);
    tab_bit B(8);

    cout<<"Podaj 8 bitow: ";
    for (int i=0;i==0;) {
        try {
            cin>>A;
            i++;
        }
        catch(string w) {
            cout<<w<<endl;
        }
    }
    cout<<"Podaj kolejne 8 bitow: ";
    for (int i=0;i==0;) {
        try {
            cin>>B;
            i++;
        }
        catch(string w) {
            cout<<w<<endl;
        }
    }

    cout<<"Alternatywa bitowa: "<<(A | B)<<endl;
    cout<<"Koniunkcja bitowa:  "<<(A & B)<<endl;
    cout<<"XOR:                "<<(A ^ B)<<endl;

    tab_bit C(8);
    tab_bit D(1);
    tab_bit E(1);
    cout<<"Podaj 8 bitow: ";
    for (int i=0;i==0;) {
        try {
            cin>>C;
            i++;
        }
        catch(string w) {
            cout<<w<<endl;
        }
    }
    D = C;
    E = C;
    C |= A;
    D &= A;
    E ^= A;
    cout<<endl<<"Alternatywa bitowa: "<<C<<endl;
    cout<<"Koniunkcja bitowa:  "<<D<<endl;
    cout<<"XOR:                "<<E<<endl;
    cout<<"------------------------------------------------"<<endl
    <<"TEST Z TRESCI ZADANIA:"<<endl;
    tab_bit t(46);
    tab_bit u(45ull);
    cout<<u<<endl;
    tab_bit v(t);
    tab_bit w(tab_bit(8));
    v[0] = 1;
    t[45] = true;
    bool b = v[1];
    u[45] = u[46] = u[63];
    cout<<t<<endl
    <<u<<endl
    <<v<<endl
    <<w<<endl;
    return 0;

}


