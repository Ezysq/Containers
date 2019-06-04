#include <iostream>
#include <string>

#include "listContainer.h"

using namespace std;

int main(){
ListContainer<int> L;

    L.pushBack(5);
    L.pushFront(7);
    L.pushBack(8);
    L.pushFront(1);
    L.pushBack(9);
    L.pushFront(3);

    L.print(); cout<<endl;

    L.popBack();
    L.popFront();

    L.print();cout<<endl;

   cout<<L.get(0)<<endl;
   cout<<L.get(1)<<endl;
   cout<<L[2]<<endl;
   cout<<L[3]<<endl;


    cout<< "List size: " << L.getSize()<<endl;


    return 0;
}
