#ifndef LIB_HPP_INCLUDED
#define LIB_HPP_INCLUDED
#include <iostream>
#include <initializer_list>
#include <string>
#include <cstdio>

namespace calculations {

    ///CLEARLINE*************
    std::istream & clearline (std::istream & is) {
        char a = '.';
        while (a!='\n' && !is.eof()) {
            a = getchar();
        }
        return is;
    }

    ///INGNORE(INT X)********
    class ignore {
        int x;
        friend std::istream & operator>> (std::istream &is, const ignore &tm )   {
            char a = '.';
            for  (int i=0;a!='\n' && !is.eof() && i<tm.x;i++) {
                a = getchar();
            }
            return is;
        }
        public:
               ignore (int value) : x(value)  {}
    };

    ///PRZECINEK*****************
    std::ostream & comma (std::ostream & os) {
        return os <<", ";
    }

    ///SZABLON MANIPULATORA******
    template <typename T>
    class array {
            T* tab;
            int size;
            friend std::ostream & operator<< (std::ostream &os, const array &tm )   {
                os<<"(";
                for (int i=0;i<tm.size-1;i++)
                    os<<tm.tab[i]<<comma;
                os<<tm.tab[tm.size-1]<<")";

                return os;
            }
        public:
           array (T arr[],int n)  {
                size = n;
                if (size<1) throw std::string("Invalid size of the array!");
                tab = new T[size];
                for (int i=0;i<size;i++)
                    tab[i] = arr[i];
           }

    };


    template <>
    class array<char> {
            char* tab;
            int size;
            friend std::ostream & operator<< (std::ostream &os, const array &tm )   {
                os<<"\"";
                for (int i=0;i<tm.size;i++)
                    os<<tm.tab[i];
                os<<"\"";

                return os;
            }
        public:
           array (char arr[],int n)  {
                size = n;
                if (size<1) {
                    int number;
                    for (number = 0;arr[number]!='\0';number++) {}
                    size = number;
                }
                tab = new char[size];
                for (int i=0;i<size;i++)
                    tab[i] = arr[i];

           }

    };

    ///SZABLON KLASY DLA TABLICY

    template <typename T>
    class arr {
                friend std::istream & operator>> (std::istream &is, arr &tm) {
                    is>>ignore(1);
                    T character;
                    for (int i=0;i<tm.sizee-1;i++) {
                        is>>character;
                        tm.tab[i] = character;
                        is>>ignore(2);
                    }
                    is>>character;
                    tm.tab[tm.sizee-1] = character;
                    is>>ignore(1);
                    return is;
                }
                friend std::ostream & operator<< (std::ostream &os, const arr &tm) {
                    os<<array<T>(tm.tab,tm.sizee);
                    return os;
                }
            protected:
                int sizee;
                T* tab;
            public:
                arr (int n) {
                    if (n<1) throw std::string ("Incorrect size!");
                    sizee = n;
                    tab = new T[sizee];
                }
                arr(std::initializer_list<T> elements) : sizee(elements.size()) {
                    tab = new T[sizee];
                    int i = 0;
                    for (auto it=elements.begin() ; it!=elements.end() ; i++,it++)
                        tab[i] = *it;
                }
                arr (const arr &tm) {
                    sizee = tm.sizee;
                    tab = new T[sizee];
                    for (int i=0;i<sizee;i++)
                        tab[i] = tm.tab[i];
                }
                arr (const arr &tm,int n) {
                    if (n<1) throw std::string ("Incorrect size!");
                    sizee = n;
                    tab = new T[sizee];
                    int number;
                    if (n<tm.sizee) number = n;
                    else number = tm.sizee;
                    for (int i=0;i<number;i++)
                        tab[i] = tm.tab[i];
                }
                arr (arr &&tm) {
                    tab = tm.tab;
                    sizee = tm.sizee;
                    tm.tab = nullptr;
                    tm.sizee = 0;
                }
                arr & operator = (const arr &tm) {
                    ~arr();
                    sizee = tm.sizee;
                    tab = new T[sizee];
                    for (int i=0;i<sizee;i++)
                        tab[i] = tm.tab[i];
                    return *this;
                }
                arr & operator = (arr &&tm) {
                    sizee = tm.sizee;
                    swap(tab,tm.tab);
                    return *this;
                }
                ~arr () {
                    delete[] tab;
                }
            public:
                T & operator[] (int i) {
                    if (sizee<=i || i<0) throw std::string ("Invalid index!");
                    return tab[i];
                }
                inline int size () const {
                    return sizee;
                }
    };

}

#endif // LIB_HPP_INCLUDED
