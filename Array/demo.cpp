#include <iostream>
#include <string>

#include "arrayContainer.h"

using namespace std;

int main(){

    ArrayContainer<string> B;

    B.add("15");
    B.add("11");
    B.add("25");
    cout<< "get value: " << B.getVal(4)<<endl;

    cout<<endl;
    cout<< "----------------------------------" <<endl;
    cout<<endl;

    ArrayContainer<int> A;

    A.add(5);
    A.add(15);
    A.add(11);
    A.add(25);
    A.addFirst(35);
    A.add(2,54);
    A.add(0,33);
    A.add(543);

    cout<< "size: " << A.getSize()<<endl;
    cout<< "max size: " << A.getMaxSize()<<endl;

    cout<< "get value: " << A.getVal(40)<<endl;
    cout<< "get position: " << A.getPos(25)<<endl;
    cout<< "get first: " << A.getFirst()<<endl;
    cout<< "get last: " << A.getLast()<<endl;

    A.print();
    A.removeVal(5);
    A.print();
    A.removePos(3);
    A.print();
    A.removeFirst();
    A.print();
    A.removeLast();
    A.print();


    return 0;
}

