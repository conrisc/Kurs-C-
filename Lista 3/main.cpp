#include <iostream>
#include <string>
#include "stos.hpp"
#include "stos.cpp"

void info();


int main() {

    int pojemnosc;
    string komenda = "";
    string wartosc = "";
    cerr<<"Wprowadz pojemnosc stosu: ";
    cin>>pojemnosc;
    while (pojemnosc <= 0) {
            cerr<<"Pojemnosc stosu powinna byc liczba calkowita wieksza od 0!"<<endl;
            cerr<<"Wprowadz pojemnosc stosu: ";
            cin>>pojemnosc;
    }
    stos *nowy = new stos(pojemnosc);
    info();


    while (komenda != "exit") {
        cin>>komenda;
        if (komenda == "rozmiar") cout<<"Ilosc elementow na stosie: "<<nowy->rozmiar()<<endl;
        else if (komenda == "wloz") {
            getline( cin, wartosc );
            try {
                nowy->wloz(wartosc);
                cout<<"Napis \""<<wartosc<<"\" zostal wlozony na stos."<<endl;
            }
            catch (string w) {
                cout<<w<<endl;
            }
        }
        else if (komenda == "sciagnij") {
            try {
                cout<<"Napis \""<<nowy->sciagnij()<<"\" zostal zdjety ze stosu."<<endl;
            }
            catch (string w) {
                cout<<w<<endl;
            }
        }
        else if (komenda == "sprawdz") {
            try {
                cout<<"Aktualny napis na stosie to: \""<<nowy->sprawdz()<<"\"."<<endl;
            }
            catch (string w) {
                cout<<w<<endl;
            }
        }
        else if (komenda == "help") info();
        else if (komenda != "exit") {
            cerr<<"Nieprawidlowa komenda!"<<endl;
        }
    }

    delete nowy;

    return 0;
}

void info() {
    cerr<<endl<<"DOSTEPNE KOMENDY:"<<endl
    <<"  - rozmiar - ilosc elementow na stosie"<<endl
    <<"  - wloz NAPIS - wklada NAPIS na stos"<<endl
    <<"  - sciagnij - zdejmuje napis ze stosu i go wypisuje"<<endl
    <<"  - sprwadz - wypisuje napis znajdujacy sie na stosie"<<endl
    <<"  - help - lista komend"<<endl
    <<"  - exit - zakoncz program"<<endl<<endl;
}
