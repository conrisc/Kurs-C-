#include "lib.hpp"

namespace obliczenia {
    div0::div0() noexcept {
    }
    const char* div0::what() noexcept {
        return "Dzielenie przez zero!";
    }

    LiczbaCalk::LiczbaCalk () noexcept {
        dlugosc = 1;
        bity = new bool[2];
        bity[0] = 0;
        bity[1] = 0;
    }
    LiczbaCalk::LiczbaCalk (int n) noexcept {
        dlugosc = 0;
        for (int k = n;k!=0;k/=2) dlugosc++;
        bity = new bool[dlugosc+1];
        for (int k = n,i=0;k!=0;k/=2,i++) {
            bity[i] = k%2;
        }
        bity[dlugosc] = 0;
        //Jezeli ujemna
        if (n<0) *this = -*this;
    }
    LiczbaCalk::LiczbaCalk (const LiczbaCalk &x) noexcept {
        dlugosc = x.dlugosc;
        bity = new bool[dlugosc+1];
        for (int i=0;i<=dlugosc;i++) {
            bity[i] = x.bity[i];
        }
    }
    LiczbaCalk::LiczbaCalk (LiczbaCalk &&x) noexcept {
        dlugosc = x.dlugosc;
        bity = x.bity;
        x.dlugosc = 0;
        x.bity = nullptr;
    }
    LiczbaCalk& LiczbaCalk::operator= (const LiczbaCalk &x) noexcept {
        if (this == &x) return *this;
        this->~LiczbaCalk();
        dlugosc = x.dlugosc;
        bity = new bool[dlugosc+1];
        for (int i=0;i<=dlugosc;i++) {
            bity[i] = x.bity[i];
        }
        return *this;
    }
    LiczbaCalk& LiczbaCalk::operator= (LiczbaCalk &&x) noexcept {
        dlugosc = x.dlugosc;
        x.dlugosc = 0;
        std::swap(bity,x.bity);
        return *this;
    }
    LiczbaCalk::~LiczbaCalk () {
        delete[] bity;
    }
    ///*****************************************
    LiczbaCalk LiczbaCalk::operator<< (const int &x) {
        LiczbaCalk result;
        result.dlugosc = dlugosc+x;
        result.bity = new bool[result.dlugosc+1];
        for (int i=0;i<x;i++)
            result.bity[i] = 0;
        for (int i=x;i<=result.dlugosc;i++)
            result.bity[i] = bity[i-x];
        return result;
    }
    LiczbaCalk operator+ (const LiczbaCalk &x, const LiczbaCalk &y) noexcept {
        LiczbaCalk result,a,b;
        a.dlugosc = std::max(x.dlugosc,y.dlugosc)+1;
        b.dlugosc = a.dlugosc;
        result.dlugosc = a.dlugosc;
        a.bity = new bool[a.dlugosc+1];
        b.bity = new bool[b.dlugosc+1];
        result.bity = new bool[result.dlugosc+1];
        ///KOPIOWANIE DO POWIEKSZONYCH TABLIC
        for (int i=0;i<=result.dlugosc;i++) {
            if (i<=x.dlugosc) a.bity[i] = x.bity[i];
            else a.bity[i] = x.bity[x.dlugosc];
            ///
            if (i<=y.dlugosc) b.bity[i] = y.bity[i];
            else b.bity[i] = y.bity[y.dlugosc];
        }
        ///DODAWANIE
        bool przeniesienie = 0;
        int suma;
        for (int i=0;i<=result.dlugosc;i++) {
            suma = przeniesienie + a.bity[i] + b.bity[i];
            if (suma>1) przeniesienie = 1;
            else przeniesienie = 0;
            result.bity[i] = suma%2;
        }
        result.mini();
        return result;
    }
    LiczbaCalk& LiczbaCalk::operator+= (const LiczbaCalk &y) noexcept {
        *this = *this + y;
        return *this;
    }
    LiczbaCalk operator- (const LiczbaCalk &x, const LiczbaCalk &y) noexcept {
        return x+(-y);
    }
    LiczbaCalk& LiczbaCalk::operator-= (const LiczbaCalk &y) noexcept {
        *this = *this - y;
        return *this;
    }
    LiczbaCalk operator* (const LiczbaCalk &x, const LiczbaCalk &y) noexcept {
        LiczbaCalk result,a,b;
        a.dlugosc = std::max(x.dlugosc,y.dlugosc)*2+1;
        b.dlugosc = a.dlugosc;
        a.bity = new bool[a.dlugosc+1];
        b.bity = new bool[b.dlugosc+1];
        ///KOPIOWANIE DO POWIEKSZONYCH TABLIC
        for (int i=0;i<=a.dlugosc;i++) {
            if (i<=x.dlugosc) a.bity[i] = x.bity[i];
            else a.bity[i] = x.bity[x.dlugosc];
            ///
            if (i<=y.dlugosc) b.bity[i] = y.bity[i];
            else b.bity[i] = y.bity[y.dlugosc];
        }
        ///MNOZENIE
        for (int i=0;i<=b.dlugosc;i++) {
            if (b.bity[i] == 1)
                result += (a<<i);
        }
        ///"ZEROWANIE" DODADKOWYCH BITOW
        for (int i=b.dlugosc+1;i<=result.dlugosc;i++)
            result.bity[i] = result.bity[b.dlugosc];
        result.mini();
        return result;
    }
    LiczbaCalk& LiczbaCalk::operator*= (const LiczbaCalk &y) noexcept {
        *this = *this * y;
        return *this;
    }
    LiczbaCalk operator% (const LiczbaCalk &x, const LiczbaCalk &y) noexcept {
        if (y.zero()) return LiczbaCalk();
        LiczbaCalk result = x,temp,a;
        if (x.bity[x.dlugosc] != y.bity[y.dlugosc]) a = y;
        else a = -y;
        for (temp = x+a;temp.bity[temp.dlugosc]==x.bity[x.dlugosc];temp+=a)
            result += a;
        return result;
    }
    LiczbaCalk& LiczbaCalk::operator%= (const LiczbaCalk &y) noexcept {
        *this = *this % y;
        return *this;
    }
    LiczbaCalk operator/ (const LiczbaCalk &x, const LiczbaCalk &y) throw (div0) {
        if (y.zero()) throw div0();
        LiczbaCalk result,temp,a;
        if (x.bity[x.dlugosc] != y.bity[y.dlugosc]) a = y;
        else a = -y;
        for (temp = x+a;x.bity[x.dlugosc] == temp.bity[temp.dlugosc];temp+=a)
            result++;
        //Jezeli wynik dzielenie powinien byc ujemny
        if (x.bity[x.dlugosc]!=y.bity[y.dlugosc]) return -result;
        return result;
    }
    LiczbaCalk& LiczbaCalk::operator/= (const LiczbaCalk &y) throw (div0) {
        if (y.zero()) throw div0();
        *this = *this / y;
        return *this;
    }
    LiczbaCalk LiczbaCalk::operator- () const noexcept {
        LiczbaCalk result = *this;
        for (int i=0;i<=dlugosc;i++) {
            if (result.bity[i]) result.bity[i] = 0;
            else result.bity[i] = 1;
        }
        result++;
        return result;
    }
    LiczbaCalk& LiczbaCalk::operator-- () noexcept {
        *this -= LiczbaCalk(1);
        return *this;
    }
    LiczbaCalk LiczbaCalk::operator-- (int) noexcept {
        LiczbaCalk result = *this;
        *this -= LiczbaCalk(1);
        return result;
    }
    LiczbaCalk& LiczbaCalk::operator++ () noexcept {
        *this += LiczbaCalk(1);
        return *this;
    }
    LiczbaCalk LiczbaCalk::operator++ (int) noexcept {
        LiczbaCalk result = *this;
        *this += LiczbaCalk(1);
        return result;
    }
    ///******************************************
    std::istream& operator>> (std::istream &we, LiczbaCalk &x) {
        int n;
        we>>n;
        x = LiczbaCalk(n);
        return we;
    }
    std::ostream& operator<< (std::ostream &wy, const LiczbaCalk &x) {
        int n = 0;
        int potega = 1;
        for (int i=0;i<x.dlugosc;potega*=2,i++) {
            n += x.bity[i]*potega;
        }
        n -= x.bity[x.dlugosc] * potega;
        wy<<n;
    }
    LiczbaCalk& LiczbaCalk::mini() {
        LiczbaCalk temp(*this);
        int licz = 0;
        for (int i = dlugosc;i>0 && bity[i]==bity[i-1];i--)
            licz++;
        this->~LiczbaCalk();
        dlugosc = temp.dlugosc - licz;
        bity = new bool[dlugosc+1];
        for (int i=0;i<=dlugosc;i++)
            bity[i] = temp.bity[i];
        return *this;
    }
    bool LiczbaCalk::zero() const {
        bool zero = true;
        for (int i=0;i<=dlugosc && zero==true;i++) {
            if (bity[i]==1) zero = false;
        }
        return zero;
    }

}
