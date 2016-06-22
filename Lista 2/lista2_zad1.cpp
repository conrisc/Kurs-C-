#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include "lista2_zad1.hpp"

using namespace std;

///PUNKT
punkt::punkt () {
    x = y = 0;
}
punkt::punkt (double a, double b) {
    x = a;
    y = b;
}
double punkt::wsp_x () {
    return x;
}
double punkt::wsp_y () {
    return y;
}
void punkt::przesun (double a, double b) {
    x += a;
    y += b;
}

///ODCINEK
odcinek::odcinek () {
    a = punkt();
    b = punkt(1,1);
}
odcinek::odcinek (punkt p1, punkt p2) {
    if (p1.wsp_x()==p2.wsp_x() && p1.wsp_y()==p2.wsp_y())
        throw string("Nie mozna utworzyc odcinka o zerowej dlugosci!");
    else {
        a = punkt(p1);
        b = punkt(p2);
    }
}
punkt odcinek::punkt_a() {
    return a;
}
punkt odcinek::punkt_b() {
    return b;
}
double odcinek::dlugosc() {
    return sqrt(pow(a.wsp_x() - b.wsp_x(),2) + pow(a.wsp_y() - b.wsp_y(),2));
}
bool odcinek::czy_zawiera_p(punkt p) {
    if (fabs(odleglosc(a,p) + odleglosc(b,p) - odleglosc(a,b))<0.00001) return 1;
    else return 0;
}
punkt odcinek::srodek() {
    punkt nowy(min(a.wsp_x(),b.wsp_x()) + (fabs(a.wsp_x() - b.wsp_x())/2),min(a.wsp_y(),b.wsp_y()) + fabs(a.wsp_y() - b.wsp_y())/2);
    return nowy;
}

///TROJKAT
trojkat::trojkat() {
    a = punkt(0,0);
    b = punkt(0,1);
    c = punkt(1,0);
}
trojkat::trojkat (punkt p1, punkt p2, punkt p3) {
    double a1_prostej = (p1.wsp_y() - p2.wsp_y())/(p1.wsp_x() - p2.wsp_x());
    double b1_prostej = p1.wsp_y() - a1_prostej * p1.wsp_x();
    double a2_prostej = (p3.wsp_y() - p2.wsp_y())/(p3.wsp_x() - p2.wsp_x());
    double b2_prostej = p3.wsp_y() - a2_prostej * p3.wsp_x();
    if ((p1.wsp_x()==p2.wsp_x() && p1.wsp_y()==p2.wsp_y()) ||
        (p1.wsp_x()==p3.wsp_x() && p1.wsp_y()==p3.wsp_y()) ||
        (p3.wsp_x()==p2.wsp_x() && p3.wsp_y()==p2.wsp_y()))
        throw string("Punkty na siebie nachodza!");
    else if (a1_prostej == a2_prostej && b1_prostej == b2_prostej)
        throw string("Punkty nie moga byc wspoliniowe!");
    else {
        a = punkt(p1);
        b = punkt(p2);
        c = punkt(p3);
    }
}
punkt trojkat::punkt_a() {
    return a;
}
punkt trojkat::punkt_b() {
    return b;
}
punkt trojkat::punkt_c() {
    return c;
}
double trojkat::obwod() {
    return odleglosc(a,b) + odleglosc(b,c) + odleglosc(c,a);
}
double trojkat::pole() {
    double od1 = odleglosc(a,b);
    double od2 = odleglosc(b,c);
    double od3 = odleglosc(c,a);
    double p = (od1 + od2 + od3)/2;
    return sqrt(p * (p - od1) * (p - od2) * (p - od3));
}
bool trojkat::czy_zawiera_p(punkt p) {
    if (odcinek(a,b).czy_zawiera_p(p) || odcinek(b,c).czy_zawiera_p(p) || odcinek(c,a).czy_zawiera_p(p)) return 1;
    else {
        double naj_wysuniety = max(a.wsp_x(),max(b.wsp_x(),c.wsp_x())) + 1;
        if (p.wsp_x() == naj_wysuniety) naj_wysuniety++;
        odcinek nowy(p,punkt(naj_wysuniety , p.wsp_y()));
        int przeciecia = 0;
        if (czy_przeciecie(nowy,odcinek(a,b))) przeciecia++;
        if (czy_przeciecie(nowy,odcinek(b,c))) przeciecia++;
        if (czy_przeciecie(nowy,odcinek(c,a))) przeciecia++;
        if (przeciecia == 1) return 1;
        else return 0;
    }
}
punkt trojkat::srodek() {
    punkt result((a.wsp_x() + b.wsp_x() + c.wsp_x())/3 , (a.wsp_y() + b.wsp_y() + c.wsp_y())/3);
    return result;
}

///GLOBALNE
double odleglosc (punkt p1, punkt p2) {
    return sqrt(pow(p1.wsp_x() - p2.wsp_x(),2) + pow(p1.wsp_y() - p2.wsp_y(),2));
}

bool rownolegle (odcinek o1, odcinek o2) {
    double a1_prostej = (o1.punkt_a().wsp_y() - o1.punkt_b().wsp_y())/(o1.punkt_a().wsp_x() - o1.punkt_b().wsp_x());
    double a2_prostej = (o2.punkt_a().wsp_y() - o2.punkt_b().wsp_y())/(o2.punkt_a().wsp_x() - o2.punkt_b().wsp_x());
    if (a1_prostej == a2_prostej) return 1;
    else return 0;
}
bool prostopadle (odcinek o1, odcinek o2) {
    double a1_prostej = (o1.punkt_a().wsp_y() - o1.punkt_b().wsp_y())/(o1.punkt_a().wsp_x() - o1.punkt_b().wsp_x());
    double a2_prostej = (o2.punkt_a().wsp_y() - o2.punkt_b().wsp_y())/(o2.punkt_a().wsp_x() - o2.punkt_b().wsp_x());
    if (a1_prostej * a2_prostej + 1 < 0.00001) return 1;
    else return 0;
}
punkt przeciecie (odcinek o1, odcinek o2) {
    double x,y;
    if (o1.punkt_a().wsp_x() == o1.punkt_b().wsp_x() &&
        o2.punkt_a().wsp_x() == o2.punkt_b().wsp_x()) {
        throw string("Odcinki sa rownolegle!");
    }
    else if (o1.punkt_a().wsp_x() == o1.punkt_b().wsp_x()) {
        double a2_prostej = (o2.punkt_a().wsp_y() - o2.punkt_b().wsp_y())/(o2.punkt_a().wsp_x() - o2.punkt_b().wsp_x());
        double b2_prostej = o2.punkt_a().wsp_y() - a2_prostej * o2.punkt_a().wsp_x();
        x = o1.punkt_a().wsp_x();
        y = a2_prostej * x + b2_prostej;
    }
    else if (o2.punkt_a().wsp_x() == o2.punkt_b().wsp_x()) {
        double a1_prostej = (o1.punkt_a().wsp_y() - o1.punkt_b().wsp_y())/(o1.punkt_a().wsp_x() - o1.punkt_b().wsp_x());
        double b1_prostej = o1.punkt_a().wsp_y() - a1_prostej * o1.punkt_a().wsp_x();
        x = o2.punkt_a().wsp_x();
        y = a1_prostej * x + b1_prostej;
    }
    else {
        double a1_prostej = (o1.punkt_a().wsp_y() - o1.punkt_b().wsp_y())/(o1.punkt_a().wsp_x() - o1.punkt_b().wsp_x());
        double b1_prostej = o1.punkt_a().wsp_y() - a1_prostej * o1.punkt_a().wsp_x();
        double a2_prostej = (o2.punkt_a().wsp_y() - o2.punkt_b().wsp_y())/(o2.punkt_a().wsp_x() - o2.punkt_b().wsp_x());
        double b2_prostej = o2.punkt_a().wsp_y() - a2_prostej * o2.punkt_a().wsp_x();
        if (fabs(a1_prostej - a2_prostej) < 0.00001)
            throw string("Odcinki sa rownolegle!");
        else {
            x = (b2_prostej - b1_prostej)/(a1_prostej - a2_prostej);
            y = a1_prostej * x + b1_prostej;
        }
    }
    punkt result(x,y);
    if (o1.czy_zawiera_p(result) && o2.czy_zawiera_p(result)) return result;
    else throw string("Odcinki sie nie przecinaja!");
}
bool czy_przeciecie (odcinek o1, odcinek o2) {
    bool result = false;
    try {
        przeciecie(o1,o2);
        result = true;
    }
    catch (string w) {
        return 0;
    }
    return result;
}
bool rozlaczne (trojkat t1, trojkat t2) {
    odcinek t1_o1(t1.punkt_a(),t1.punkt_b()), t1_o2(t1.punkt_b(),t1.punkt_c()), t1_o3(t1.punkt_c(),t1.punkt_a());
    odcinek t2_o1(t2.punkt_a(),t2.punkt_b()), t2_o2(t2.punkt_b(),t2.punkt_c()), t2_o3(t2.punkt_c(),t2.punkt_a());
    if (czy_przeciecie(t1_o1,t2_o1) || czy_przeciecie(t1_o1,t2_o2) || czy_przeciecie(t1_o1,t2_o3) ||
        czy_przeciecie(t1_o2,t2_o1) || czy_przeciecie(t1_o2,t2_o2) || czy_przeciecie(t1_o2,t2_o3) ||
        czy_przeciecie(t1_o3,t2_o1) || czy_przeciecie(t1_o3,t2_o2) || czy_przeciecie(t1_o3,t2_o3) ||
        sprw_zawieranie(t1,t2))
            return 0;
    else return 1;
}
bool sprw_zawieranie (trojkat t1, trojkat t2) {
    if (t1.czy_zawiera_p(t2.punkt_a()) && t1.czy_zawiera_p(t2.punkt_b()) && t1.czy_zawiera_p(t2.punkt_c()) ||
       (t2.czy_zawiera_p(t1.punkt_a()) && t2.czy_zawiera_p(t1.punkt_b()) && t2.czy_zawiera_p(t1.punkt_c())))  return 1;
    return 0;
}
