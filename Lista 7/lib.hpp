#ifndef LIB_HPP_INCLUDED
#define LIB_HPP_INCLUDED
#include <iostream>
#include <exception>


namespace obliczenia {

class div0 : std::exception {
    public:
        div0() noexcept;
        virtual const char* what() noexcept;
};

class LiczbaCalk {
    protected:
        bool *bity;         // tablica o dlugosci 'dlugosc' + 1 (dodatkowy bit na znak)
        int dlugosc;
    public:
        LiczbaCalk () noexcept;
        LiczbaCalk (int n) noexcept;
        LiczbaCalk (const LiczbaCalk &x) noexcept;
        LiczbaCalk (LiczbaCalk &&x) noexcept;
        LiczbaCalk& operator= (const LiczbaCalk &x) noexcept;
        LiczbaCalk& operator= (LiczbaCalk &&x) noexcept;
        virtual ~LiczbaCalk ();
    public:
        LiczbaCalk operator<< (const int &x);
        friend LiczbaCalk operator+ (const LiczbaCalk &x, const LiczbaCalk &y) noexcept;
        LiczbaCalk& operator+= (const LiczbaCalk &y) noexcept;
        friend LiczbaCalk operator- (const LiczbaCalk &x, const LiczbaCalk &y) noexcept;
        LiczbaCalk& operator-= (const LiczbaCalk &y) noexcept;
        friend LiczbaCalk operator* (const LiczbaCalk &x, const LiczbaCalk &y) noexcept;
        LiczbaCalk& operator*= (const LiczbaCalk &y) noexcept;
        friend LiczbaCalk operator% (const LiczbaCalk &x, const LiczbaCalk &y) noexcept;
        LiczbaCalk& operator%= (const LiczbaCalk &y) noexcept;
        friend LiczbaCalk operator/ (const LiczbaCalk &x, const LiczbaCalk &y) throw (div0);
        LiczbaCalk& operator/= (const LiczbaCalk &y) throw (div0);
        LiczbaCalk operator- () const noexcept;
        LiczbaCalk& operator-- () noexcept;
        LiczbaCalk operator-- (int) noexcept;
        LiczbaCalk& operator++ () noexcept;
        LiczbaCalk operator++ (int) noexcept;
    public:
        friend std::istream& operator>> (std::istream &we, LiczbaCalk &x);
        friend std::ostream& operator<< (std::ostream &wy, const LiczbaCalk &x);
    protected:
        LiczbaCalk& mini();  ///FUNKCJA DO MINIMALIZACJI (Usuwanie wiodacych zer w przypadku liczby dodatniej i usuwanie jedynek w przypadku liczby ujemnej)
        bool zero() const;
};

}


#endif // LIB_HPP_INCLUDED
