#ifndef LIB_HPP_INCLUDED
#define LIB_HPP_INCLUDED

class lista {
    int number;
public:
    class node;
    node *first;
    node *last;
public:
    lista();
    lista(double a);
    lista(const lista &l);
    lista (lista &&l);
    lista & operator = (const lista &l);
    lista & operator = (lista &&l);
    ~lista();
public:
    void add(double a,int i);
    void remv(int i);
public:
    double* operator[] (int i);
    int length();
};

class lista::node {
public:
    double value;
    node *next;
    node *prev;
public:
    node(double a);
    node *add(double a,int i);
    node *remv(int i);
};

class queue2s : protected lista {
public:
    void addFirst(double a);
    void addLast(double a);
    void remvFirst();
    void remvLast();
    double valFirst();
    double valLast();
    using lista::length;
    void operator +(const double &a);
    void operator --();
    void operator --(int);
};


#endif // LIB_HPP_INCLUDED
