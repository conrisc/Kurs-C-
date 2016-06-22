#include "lib.hpp"
#include <iostream>

    lista::lista() {
        number = 0;
        first = NULL;
        last = NULL;
    }
    lista::lista(double a) {
        number = 0;
        first = NULL;
        last = NULL;
        add(a,0);
    }
    lista::lista (const lista &l) {
        number = 0;
        first = NULL;
        last = NULL;
        for (node* wsk = l.first;wsk != NULL;wsk = wsk->next)
            add(wsk -> value,number);
    }

    lista::lista (lista &&l) {
        number = l.number;
        first = l.first;
        last = l.last;
        l.first = NULL;
        l.last = NULL;
        l.number = 0;
    }
    lista & lista::operator = (const lista &l) {
        if (this == &l) return *this;
        this->~lista();
        number = 0;
        first = NULL;
        last = NULL;
        for (node* wsk = l.first;wsk != NULL;wsk = wsk->next)
            add(wsk -> value,number);
    }
    lista & lista::operator = (lista &&l) {
        number = l.number;
        l.number = 0;
        std::swap(first,l.first);
        std::swap(last,l.last);
    }
    lista::~lista() {
        while(first!=NULL)
            remv(0);
    }
    void lista::add(double a,int i) {
        if (i < 0 || i > this->length())
            throw std::string("Przekroczono zakres listy!");
        //-------------------------
        if (first == NULL) {
            first = new node(a);
            last = first;
        }
        else if (i == 0) {
            first = first->add(a,0);
        }
        else if (i == this->length())
            last = last->add(a,1);
        else
            first->add(a,i);
        number++;
    }

    void lista::remv(int i) {
        if (i < 0 || i > this->length()-1)
            throw std::string("Przekroczono zakres listy!");
        if (first == last) {
            delete first;
            first = NULL;
            last = NULL;
        }
        else if (i == 0) {
            first = first->remv(0);
        }
        else if (i == this->length()-1) {
            last = last->remv(0);
        }
        else {
            first->remv(i);
        }
        number--;
    }
    double* lista::operator[] (int i) {
        if (i < 0 || i > this->length()-1)
            throw std::string("Przekroczono zakres listy!");
        node* wsk = first;
        for (;i>0 && wsk!=NULL;i--)
            wsk = wsk->next;
        return &wsk->value;
    }

    int lista::length() {
        return number;
    }

///NODE**************************************************

    lista::node::node(double a) {
        value = a;
        next = NULL;
        prev = NULL;
    }

    lista::node* lista::node::add(double a,int i) {
        node* neww = new node(a);
        node* wsk = this;
        for (;i>0 && next!=NULL;i--) {
            wsk = wsk->next;
        }
        if (i==0) {
            neww->next = wsk;
            if (wsk->prev != NULL) {
                neww->prev = wsk->prev;
                wsk->prev->next = neww;
            }
            wsk->prev = neww;
        }
        else {
            wsk->next = neww;
            neww->prev = wsk;
        }
        return neww;
    }
    lista::node* lista::node::remv(int i) {
        node* wsk = this;
        for (;i>0 && next!=NULL;i--) {
            wsk = wsk->next;
        }
        if (wsk->prev == NULL) {
            wsk = wsk->next;
            delete wsk->prev;
            wsk->prev = NULL;
        }
        else if (wsk->next == NULL) {
            wsk = wsk->prev;
            delete wsk->next;
            wsk->next = NULL;
        }
        else {
            node *p = wsk->prev;
            node *n = wsk->next;
            p->next = n;
            n->prev = p;
            delete wsk;
        }
        return wsk;
    }


    void queue2s::addFirst(double a) {
        this->add(a,0);
    }
    void queue2s::addLast(double a) {
        this->add(a,this->length());
    }
    void queue2s::remvFirst() {
        this->remv(0);
    }
    void queue2s::remvLast() {
        this->remv(this->length()-1);
    }
    double queue2s::valFirst() {
        if (this->length() == 0)
            throw std::string("Kolejka nie zawiera elementow!");
        return first->value;
    }
    double queue2s::valLast() {
        if (this->length() == 0)
            throw std::string("Kolejka nie zawiera elementow!");
        return last->value;
    }
    void queue2s::operator +(const double &a) {
        this->addLast(a);
    }

    void operator +(const double &a, queue2s &q) {
        q.addFirst(a);
    }

    void queue2s::operator --() {
        this->remvFirst();
    }

    void queue2s::operator --(int) {
        this->remvLast();
    }
