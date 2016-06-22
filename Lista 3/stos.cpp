
///KONSTRUKTORY STOSU
stos::stos() : pojemnosc(1) {
    napis = new string[pojemnosc];
    ile = 0;
}
stos::stos(int a) : pojemnosc(a) {
    if (a<=0) {
        throw string("Nie mozna stworzyc stosu o pojemnosci mniejszej niz jeden!");
    }
    napis = new string[pojemnosc];
    ile = 0;
}
stos::stos(const stos &s) : pojemnosc(s.pojemnosc) {
    napis = new string[s.pojemnosc];
    for (int i=0;i<s.ile;i++) {
        napis[i] = s.napis[i];
    }
    ile = s.ile;
}
stos::stos(stos &&s) : pojemnosc(s.pojemnosc) {
    napis = s.napis;
    s.napis = nullptr;
    ile = s.ile;
}
stos::stos(initializer_list<string> lista) : pojemnosc(lista.size()*2+1) {
    napis = new string[pojemnosc];
    int i = 0;
    for (auto it = lista.begin();it != lista.end();i++,it++) {
        napis[i] = *it;
    }
    ile = lista.size();
}
///DESTRUKTOR
stos::~stos() {
    delete[] napis;
}

///METODY STOSU
void stos::wloz(string text) {
    if (ile==pojemnosc) throw string ("Stos zawiera juz maksymalna dopuszczalna ilosc elementow!");
    napis[ile] = text;
    ile++;
}
string stos::sciagnij() {
    if (ile<=0) throw string ("Stos jest pusty!");
    ile--;
    return napis[ile];
}
string stos::sprawdz() {
    if (this->ile>0) return napis[ile-1];
    else throw string ("Stos jest pusty!");
}
int stos::rozmiar() {
    return ile;
}


