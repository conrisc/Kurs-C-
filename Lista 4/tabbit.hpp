#ifndef TABBIT_HPP_INCLUDED
#define TABBIT_HPP_INCLUDED
#include <iostream>

using namespace std;

///KLASA TAB_BIT

    class tab_bit {
            typedef unsigned long long slowo;
            static const int rozmiarSlowa;
            friend istream & operator >> (istream &we, tab_bit &tb);
            friend ostream & operator << (ostream &wy, const tab_bit &tb);
        public:
            class reff;
        protected:
            int dl;
            slowo *tab;
        public:
            explicit tab_bit (int rozm);
            explicit tab_bit (slowo tb);
            tab_bit (const tab_bit &tb);
            tab_bit (tab_bit &&tb);
            tab_bit & operator = (const tab_bit &tb);
            tab_bit & operator = (tab_bit &&tb);
            ~tab_bit ();
        private:
            bool czytaj (int i) const;
            bool pisz (int i, bool b);
        public:
            bool operator[] (int i) const;
            reff operator[] (int i);
            inline int rozmiar () const;
        public:
            tab_bit operator |( const tab_bit &tb);     ///OPERATORY DZIALAJACE NA CALYCH TABLICACH
            tab_bit operator &( const tab_bit &tb );
            tab_bit operator ^( const tab_bit &tb );
            tab_bit operator |=( const tab_bit &tb );
            tab_bit operator &=( const tab_bit &tb );
            tab_bit operator ^=( const tab_bit &tb );
            tab_bit operator !( );
    };

///KLASA POMOCNICZA REFF

    class tab_bit::reff {
            friend istream & operator >> (istream &we, reff r);
            friend ostream & operator << (ostream &wy, const reff &r);
        public:
            slowo *part;
            int indeks;
        private:
            void pisz (bool b);
            bool czytaj() const;
        public:
            reff & operator = (bool bit);
            reff & operator = (const reff &r);
        public:
            operator bool();
            bool operator |( const reff &r );       ///OPERATORY DLA POJEDYNCZYCH BITOW
            bool operator &( const reff &r );
            bool operator ^( const reff &r );
            reff operator |=( const reff &r );
            reff operator &=( const reff &r );
            reff operator ^=( const reff &r );
            bool operator !(  );
    };


#endif // TABBIT_HPP_INCLUDED
