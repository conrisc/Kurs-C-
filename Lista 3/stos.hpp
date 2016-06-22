#ifndef LISTA3_ZAD1_HPP_INCLUDED
#define LISTA3_ZAD1_HPP_INCLUDED
#include <initializer_list>
#include <string>

using namespace std;

class stos {
    int ile;
    string *napis;
public:
    const int pojemnosc;
    stos();
    stos(int a);
    stos(const stos &s);
    stos(stos &&s);
    stos(initializer_list<string> lista);
    ~stos();
    stos & operator= (const stos &s) {
        if (this == &s) return *this;
        if (pojemnosc < s.ile) throw string ("Stos jest za maly, aby wykonac przypisanie!");
        ile = s.ile;
        for (int i=0;i<ile;i++) {
            napis[i] = s.napis[i];
        }
        return *this;
    }
    //METODY
    void wloz(string text);
    string sciagnij();
    string sprawdz();
    int rozmiar();
};


#endif // LISTA3_ZAD1_HPP_INCLUDED
