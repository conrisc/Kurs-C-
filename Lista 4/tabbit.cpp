#include "tabbit.hpp"
#include <string>
#include <cmath>

///KLASA TAB_BIT*******************************************************
const int tab_bit::rozmiarSlowa = sizeof(slowo) * 8;

istream & operator >> (istream &we, tab_bit &tb) {
    char a;
    for (int i=0;i<tb.dl;i++) {
        we>>a;
        if (a<48 || 49<a) throw string("Niepoprawne dane!");
        tb.pisz(i,a-48);
    }
    return we;
}
ostream & operator << (ostream &wy, const tab_bit &tb) {
    for (int i = 0;i<tb.dl;i++) {
        wy<<tb.czytaj(i);
    }
    return wy;
}

tab_bit::tab_bit (int rozm) {
    if (rozm>0) {
        tab = new slowo[(rozm-1)/rozmiarSlowa + 1];
        for (int i=0;i<(rozm-1)/rozmiarSlowa + 1;i++) {
            tab[i] = 0;
        }
        dl = rozm;
    }
    else throw string ("Rozmiar tablicy musi byc wiekszy niz 0!");
}
tab_bit::tab_bit (slowo tb) {
    tab = new slowo;
    *tab = tb;
    dl = rozmiarSlowa;
}

tab_bit::tab_bit (const tab_bit &tb) {
    dl = tb.dl;
    tab = new slowo[(dl-1)/rozmiarSlowa + 1];
    for (int i=0;i<(dl-1)/rozmiarSlowa + 1;i++) {
        tab[i] = tb.tab[i];
    }
}
tab_bit::tab_bit (tab_bit &&tb) {
    tab = tb.tab;
    dl = tb.dl;
    tb.tab = nullptr;
    tb.dl = 0;
}
tab_bit & tab_bit::operator = (const tab_bit &tb) {
    if (this == &tb) return *this;
    this->~tab_bit();
    dl = tb.dl;
    tab = new slowo[(dl-1)/rozmiarSlowa +1];
    for (int i = 0; i<(dl-1)/rozmiarSlowa +1;i++) {
        tab[i] = tb.tab[i];
    }
    return *this;
}

tab_bit & tab_bit::operator = (tab_bit &&tb) {
    dl = tb.dl;
    tb.dl = 0;
    swap(tab,tb.tab);
    return *this;
}
tab_bit::~tab_bit () {
    delete[] tab;
    dl = 0;
}
///**************************
bool tab_bit::czytaj (int i) const {
    if (i>=dl || i<0) throw string("Przekroczono zakres tablicy!");
    return (tab[i/rozmiarSlowa]>>(i%rozmiarSlowa))%2;
}
bool tab_bit::pisz (int i, bool b) {
    if (czytaj(i) == b || i>=dl || i<0) return 0;
    else {
        if (b == 1)
            tab[i/rozmiarSlowa] += pow(2,i%rozmiarSlowa);
        else
            tab[i/rozmiarSlowa] -= pow(2,i%rozmiarSlowa);
    }
}
bool tab_bit::operator[] (int i) const {
    try {
        return czytaj(i);
    }
    catch(string w) {
        cout<<w<<endl;
    }
}
tab_bit::reff tab_bit::operator[] (int i) {
    if (i>=dl || i<0) throw string ("Przekroczono zakres tablicy!");
    reff wsk;
    wsk.part = &tab[i/rozmiarSlowa];
    wsk.indeks = i%rozmiarSlowa;
    return wsk;
}
int tab_bit::rozmiar () const {
    return dl;
}
//OPERATORY*********************************************************
tab_bit tab_bit::operator |( const tab_bit &tb) {
    int minn = min(this->rozmiar(),tb.rozmiar());
    int maxx = max(this->rozmiar(),tb.rozmiar());
    tab_bit wynik(maxx);
    for (int i = 0;i<minn;i++) {
        wynik[i] = (this->czytaj(i) || tb.czytaj(i));
    }
    if (this->rozmiar() < tb.rozmiar()) {
        for (int i=minn;i<maxx;i++)
            wynik[i] = tb.czytaj(i);
    }
    else {
        for (int i=minn;i<maxx;i++)
            wynik[i] = this->czytaj(i);
    }
    return wynik;
}
tab_bit tab_bit::operator &( const tab_bit &tb ){
    int minn = min(this->rozmiar(),tb.rozmiar());
    int maxx = max(this->rozmiar(),tb.rozmiar());
    tab_bit wynik(maxx);
    for (int i = 0;i<minn;i++) {
        wynik[i] = (this->czytaj(i) && tb.czytaj(i));
    }
    for (int i= minn;i<maxx;i ++) {
        wynik[i] = 0;
    }
   return wynik;
}
tab_bit tab_bit::operator ^( const tab_bit &tb ){
    int minn = min(this->rozmiar(),tb.rozmiar());
    int maxx = max(this->rozmiar(),tb.rozmiar());
    tab_bit wynik(maxx);
    for (int i = 0;i<minn;i++) {
        wynik[i] = (this->czytaj(i) == !tb.czytaj(i));
    }
    for (int i= minn;i<maxx;i ++) {
        wynik[i] = 0;
    }
    return wynik;
}
tab_bit tab_bit::operator |=( const tab_bit &tb ){
    int minn = min(this->rozmiar(),tb.rozmiar());
    for (int i = 0;i<minn;i++) {
        this->pisz(i,(this->czytaj(i) || tb.czytaj(i)));
    }
    return *this;
}
tab_bit tab_bit::operator &=( const tab_bit &tb ){
    int minn = min(this->rozmiar(),tb.rozmiar());
    for (int i = 0;i<minn;i++) {
        this->pisz(i,(this->czytaj(i) && tb.czytaj(i)));
    }
    for (int i = minn; i<this->rozmiar();i++) {
        this->pisz(i,0);
    }
    return *this;
}
tab_bit tab_bit::operator ^=( const tab_bit &tb ){
    int minn = min(this->rozmiar(),tb.rozmiar());
    for (int i = 0;i<minn;i++) {
        this->pisz(i,(this->czytaj(i) == !tb.czytaj(i)));
    }
    return *this;
}
tab_bit tab_bit::operator !( ){
    tab_bit wynik( this->rozmiar() );
    for (int i = 0;i<wynik.rozmiar();i++) {
        wynik[i] = !this->czytaj(i);
   }
   return wynik;
}


///KLASA REFF*******************************************************
istream & operator >> (istream &we, tab_bit::reff r) {
    bool b;
    we>>b;
    r.pisz(b);
    return we;
}
ostream & operator << (ostream &wy,const tab_bit::reff &r) {
    return wy<<(*r.part>>r.indeks)%2;
}
//*******************************************************************
tab_bit::reff & tab_bit::reff::operator = (bool bit) {
    pisz(bit);
    return *this;
}
tab_bit::reff & tab_bit::reff::operator = (const reff &r) {
    bool bit = (*r.part>>r.indeks)%2;
    pisz(bit);
    return *this;
}

void tab_bit::reff::pisz(bool b) {
    if ( (*part>>indeks)%2 != b ) {
        if (b == 1)
            *part += pow(2,indeks);
        else
            *part -= pow(2,indeks);
    }
}

bool tab_bit::reff::czytaj() const{
    return (*part>>indeks)%2;
}

//OPERATORY NA POJEDYNCZYCH BITACH***********************************
bool tab_bit::reff::operator |(const reff &r ) {
    return ( this->czytaj() || r.czytaj() );
}
bool tab_bit::reff::operator &(const reff &r ) {
    return ( this->czytaj() && r.czytaj() );
}
bool tab_bit::reff::operator ^(const reff &r ){
    return ( this->czytaj() == !r.czytaj() );
}
tab_bit::reff tab_bit::reff::operator |=(const reff &r ){
    bool wartosc = this->czytaj() || r.czytaj();
    this->pisz(wartosc);
    return *this;
}
tab_bit::reff tab_bit::reff::operator &=(const reff &r ){
    bool wartosc = this->czytaj() && r.czytaj();
    this->pisz(wartosc);
    return *this;
}
tab_bit::reff tab_bit::reff::operator ^=(const reff &r ){
    bool wartosc =  this->czytaj() == !r.czytaj();
    this->pisz(wartosc);
    return *this;
}
bool tab_bit::reff::operator !( ){
    return !this->czytaj();
}

tab_bit::reff::operator bool() {
    return (*part>>indeks)%2;
}
