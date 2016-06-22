#ifndef LISTA2_ZAD1_H_INCLUDED
#define LISTA2_ZAD1_H_INCLUDED

class punkt {
    double x,y;
public:
    punkt ();
    punkt (double a, double b);
    double wsp_x ();
    double wsp_y ();
    void przesun (double a, double b);
};

class odcinek {
    punkt a,b;
public:
    odcinek ();
    odcinek (punkt p1, punkt p2);
    punkt punkt_a();
    punkt punkt_b();
    double dlugosc();
    bool czy_zawiera_p(punkt p);
    punkt srodek();
};

class trojkat {
    punkt a,b,c;
public:
    trojkat();
    trojkat (punkt p1, punkt p2, punkt p3);
    punkt punkt_a();
    punkt punkt_b();
    punkt punkt_c();
    double obwod();
    double pole();
    bool czy_zawiera_p(punkt p);
    punkt srodek();
};

double odleglosc (punkt p1, punkt p2);

bool rownolegle (odcinek o1, odcinek o2);
bool prostopadle (odcinek o1, odcinek o2);
punkt przeciecie (odcinek o1, odcinek o2);
bool czy_przeciecie (odcinek o1, odcinek o2);

bool rozlaczne (trojkat t1, trojkat t2);
bool sprw_zawieranie (trojkat t1, trojkat t2);

#endif // LISTA2_ZAD1_H_INCLUDED
