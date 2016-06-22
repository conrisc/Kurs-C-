#include "lib.hpp"
#include "lib.cpp"
#include <iostream>

using namespace std;

void write(queue2s q);

int main() {

    queue2s exmpl;
    queue2s exmpl2;

    exmpl+321;
    52+exmpl;
    exmpl+481;
    exmpl2 = exmpl;

    write(exmpl);

    exmpl--;
    --exmpl;

    write(exmpl);
    exmpl2+932;
    --exmpl2;
    write(exmpl2);
    return 0;

}

void write(queue2s q) {
    cout<<"Pierwszy element: "<<q.valFirst()<<endl
    <<"Ostatni element: "<<q.valLast()<<endl
    <<"Dlugosc kolejki: "<<q.length()<<endl<<endl;
}
