#include "lista2_zad1.cpp"

ostream & operator<< (ostream &wyjscie, punkt &p) {
   return wyjscie <<"P("<<p.wsp_x()<<","<<p.wsp_y()<<")";
 }

 ostream & operator<< (ostream &wyjscie, odcinek &o) {
   return wyjscie <<"P("<<o.punkt_a().wsp_x()<<","<<o.punkt_a().wsp_y()<<") P("<<o.punkt_b().wsp_x()<<","<<o.punkt_b().wsp_y()<<")";
 }

 ostream & operator<< (ostream &wyjscie, trojkat &t) {
   return wyjscie <<"P("<<t.punkt_a().wsp_x()<<","<<t.punkt_a().wsp_y()<<") P("<<t.punkt_b().wsp_x()<<","<<t.punkt_b().wsp_y()<<") P("<<t.punkt_c().wsp_x()<<","<<t.punkt_c().wsp_y()<<")";
 }

int main() {
    punkt wypisz_p;
    odcinek wypisz_o;
    trojkat wypisz_t;
    ///PUNKT
        //Konstruktor domyœlny
        punkt p1;
        cout<<p1<<endl;
        //Konstruktor
        punkt p2(2,-0.2);
        cout<<p2<<endl;
        //Przesuwanie
        p2.przesun(-1.5,3.2);
        cout<<p2<<endl;
    cout<<endl;
    ///ODCINEK
        //Konstruktor domyœlny
        odcinek o1;
        cout<<o1<<endl;
        //Konstruktor z prawidlowymi punktami
        try {
            odcinek o2(p1,p2);
            o1 = o2;
            cout<<o1<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //Konstruktor tworzacy odcinek o zerowej dlugosci
        try {
            odcinek o3(p1,p1);
            o1 = o3;
            cout<<o1<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //Dlugosc odcinka
        cout<<o1.dlugosc()<<endl;
        //Odleglosc 2 punktow (FUNKCJA GLOBALNA)
        cout<<odleglosc(p1,p2)<<endl;
        //Sprawdzanie czy punkt nalezy do odcinka part1
        p1 = punkt((double)1/3,2);
        if(o1.czy_zawiera_p(p1)) cout<<"ZAWIERA"<<endl;
        else cout<<"NIE ZAWIERA"<<endl;
        //Sprawdzanie czy punkt nalezy do odcinka part2
        p1 = punkt((double)11/30,2);
        if(o1.czy_zawiera_p(p1)) cout<<"ZAWIERA"<<endl;
        else cout<<"NIE ZAWIERA"<<endl;
        //Srodek odcinka
        wypisz_p = o1.srodek();
        cout<<wypisz_p<<endl;
        //NOWE ODCINKI (DO SPRAWDZENIA FUNKCJI: ROWNOLEGLE, PROSTOPADLE)
        odcinek o2;
        try {
            o2 = odcinek(punkt(4,7),punkt(4.5,10));
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        odcinek o3;
        try {
            o3 = odcinek(punkt(4,10),punkt(10,9));
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //ROWNOLEGLE
        if (rownolegle(o1,o2)) cout<<"ROWNOLEGLE"<<endl;
        else cout<<"NIE SA ROWNOLEGLE"<<endl;
        //PROSTOPADLE
        if (prostopadle(o1,o3)) cout<<"PROSTOPADLE"<<endl;
        else cout<<"NIE SA PROSTOPADLE"<<endl;
        //PRZECIECIE PART1
        try {
            wypisz_p = przeciecie (o1,o2);
            cout<<wypisz_p<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //PRZECIECIE PART2
        try {
            wypisz_p = przeciecie (o1,o3);
            cout<<wypisz_p<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //PRZECIECIE PART3
        try {
            wypisz_p = przeciecie (o2,o3);
            cout<<wypisz_p<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }

    cout<<endl;
    ///TROJKAT
        //Konstruktor domyslny
        trojkat t1;
        cout<<t1<<endl;
        //Konstruktor part1
        try {
            trojkat t2(punkt(4,4),punkt(8,7),punkt(11,2));
            t1 = t2;
            cout<<t1<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //Konstruktor part2
        try {
            trojkat t2(punkt(4,4),punkt(4,4),punkt(11,2));
            t1 = t2;
            cout<<t1<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //Konstruktor part3
        try {
            trojkat t2(punkt(0,0),punkt(1,1),punkt(2,2));
            t1 = t2;
            cout<<t1<<endl;
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //Obwod
        cout<<t1.obwod()<<endl;
        //Pole
        cout<<t1.pole()<<endl;
        //Czy zawiera punkt part1
        if (t1.czy_zawiera_p(punkt(7.5,3))) cout<<"ZAWIERA"<<endl;
        else cout<<"NIE ZAWIERA"<<endl;
        //Czy zawiera punkt part2
        if (t1.czy_zawiera_p(punkt(7.5,2.99))) cout<<"ZAWIERA"<<endl;
        else cout<<"NIE ZAWIERA"<<endl;
        //Srodek
        wypisz_p = t1.srodek();
        cout<<wypisz_p<<endl;
        //NOWE TROJKATY DO SPRAWDZENIA FUNCKJI GLOBALNYCH (ROZLACZNE, ZAWIERANIE)
        trojkat t2,t3,t4;
        try {
            t2 = trojkat(punkt(7,4),punkt(7,1),punkt(10,1));
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        try {
            t3 = trojkat(punkt(6,4),punkt(9,3),punkt(8,6));
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        try {
            t4 = trojkat(punkt(1,3),punkt(3,4),punkt(1,5));
        }
        catch(string w) {
            cout<<"Wyjatek: "<<w<<endl;
        }
        //ROZLACZNE PART1 (powinny nie byc rozlaczne)
        if (rozlaczne(t1,t2)) cout<<"ROZLACZNE"<<endl;
        else cout<<"NIE SA ROZLACZNE"<<endl;
        //ROZLACZNE PART1 (powinny byc rozlaczne)
        if (rozlaczne(t1,t4)) cout<<"ROZLACZNE"<<endl;
        else cout<<"NIE SA ROZLACZNE"<<endl;
        //ZAWIERANIE PART1 (nie powinny sie zawierac)
        if (sprw_zawieranie(t1,t2)) cout<<"ZAWIERANIE = TRUE"<<endl;
        else cout<<"ZAWIERANIE = FALSE"<<endl;
        //ZAWIERANIE PART2 (powinny sie zawierac)
        if (sprw_zawieranie(t1,t3)) cout<<"ZAWIERANIE = TRUE"<<endl;
        else cout<<"ZAWIERANIE = FALSE"<<endl;

    return 0;

}
