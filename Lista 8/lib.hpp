#ifndef LIB_HPP_INCLUDED
#define LIB_HPP_INCLUDED
#include <random>
#include <ctime>
#include <cstring>

///PERMUTACJA

namespace obliczenia {

    template <typename T>
    void permutacja (T *tab, const int &rozmiar) {
        std::default_random_engine dre(time(NULL));
        std::uniform_int_distribution<int> di(0,rozmiar-1);
        for (int i=0;i<rozmiar;i++)
            std::swap(tab[di(dre)],tab[di(dre)]);
    }

    ///KOMPARATOR (ROWNIEZ DLA WSKAZNIKOW)
    template <typename T>
    bool comp1 (const T& x, const T& y) {
        return x<=y;
    }

    template <typename T>
    bool comp2 (const T& x, const T& y) {
        return x>=y;
    }

    ///KOMPARATOR DLA CHAR
    template <char*>
    bool comp1 (const char* x,const char* y) {
        return strcmp(x, y)<=0;
    }

    template <char*>
    bool comp2 (const char* x,const char* y) {
        return strcmp(x, y)>=0;
    }


    template <typename T>
    void sortuj (T tab[], const int &rozmiar,bool(*comparator)(const T&,const T&) = comp1) {
        bool zmiana = true;
        for (int i=rozmiar;i>0 && zmiana == true;i--) {
            zmiana = false;
            for (int j=0;j<i-1;j++) {
                if (!comparator(tab[j],tab[j+1])) {
                    std::swap(tab[j],tab[j+1]);
                    zmiana = true;
                }
            }
        }
    }


    template <typename T>
    void sortuj (T* tab[], const int &rozmiar,bool(*comparator)(const T&,const T&) = comp1) {
        bool zmiana = true;
        for (int i=rozmiar;i>0 && zmiana == true;i--) {
            zmiana = false;
            for (int j=0;j<i-1;j++) {
                if (!comparator(*tab[j],*tab[j+1])) {
                    std::swap(tab[j],tab[j+1]);
                    zmiana = true;
                }
            }
        }
    }


    template <typename comparator>
    void sortuj (const char* tab[], const int &rozmiar,comparator comp = comp1<char*>) {
        bool zmiana = true;
        for (int i=rozmiar;i>0 && zmiana == true;i--) {
            zmiana = false;
            for (int j=0;j<i-1;j++) {
                if (!comp(tab[j],tab[j+1])) {
                    std::swap(tab[j],tab[j+1]);
                    zmiana = true;
                }
            }
        }
    }


    /*template <void*>
    void  sortuj ( tab[], const int &rozmiar,bool(*comparator)(const ,const ) = comp1) {
        bool zmiana = true;
        for (int i=rozmiar;i>0 && zmiana == true;i--) {
            zmiana = false;
            for (int j=0;j<i-1;j++) {
                if (!comparator(tab[j],tab[j+1])) {
                    std::swap(*tab[j],*tab[j+1]);
                    zmiana = true;
                }
            }
        }
    }
    */
}



#endif // LIB_HPP_INCLUDED
