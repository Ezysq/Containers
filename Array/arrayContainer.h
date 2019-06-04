#ifndef CONTAIN_HPP
#define CONTAIN_HPP

#include <iostream>

#define SIZE 30

template <class T>
class ArrayContainer{
    T* cont;
    int size;
    int cap;
public:
    ArrayContainer(){
        size = SIZE ;
        cont = new T [size];
        cap=0;
    }
    ~ArrayContainer(){
        delete [] cont;
    }
    /* if array is full*/
    void full();
    /* add metods */
    void add(int pos, T const& val);
    void addFirst(T const& val);
    void add(T const& val);
    /* remove metods */
    void removePos(int pos);
    void removeVal(T const& val);
    void removeFirst();
    void removeLast();
    /* get metods */
    T getVal(int pos);
    T getFirst();
    T getLast();
    int getPos(T const& val);
    /* capacity size */
    int getSize();
    int getMaxSize();

    void print();

};

template <class T>
void ArrayContainer<T>::full(){

    size+=SIZE;
    T* newCont = new T [size];

    for(int i=0; i<cap; ++i)
        newCont[i] = cont[i];

    delete [] cont;
    cont = newCont;
}

template <class T>
void ArrayContainer<T>::add(int pos, T const& val){
    if(size == cap+1) full();
    for(int i=cap; i >= pos; --i){
        cont[i+1] = cont[i];
        if(i == 0) break;
    }
    cont[pos] = val;
    cap++;
}

template <class T>
void ArrayContainer<T>::addFirst(T const& val){
    if(size == cap+1) full();
    for(int i=cap; i >= 0; --i){
        cont[i+1] = cont[i];
        if(i == 0) break;
    }
    cont[0] = val;
    cap++;
}

template <class T>
void ArrayContainer<T>::add(T const& val){
    if(size == cap+1) full();
    cont[cap]=val;
    cap++;
}

template <class T>
void ArrayContainer<T>::print(){
    for(int i=0; i<cap; ++i)
        std::cout<< cont[i] << " ";
    std::cout<< std::endl;
}

template <class T>
void ArrayContainer<T>::removePos(int pos){
    if(pos >= cap) std::cout<< "Position is invalid" << std::endl;
    for(int i=pos; i < cap; ++i)
        cont[i] = cont[i+1];
    cap--;
}

template <class T>
void ArrayContainer<T>::removeVal(T const& val){
    bool removed=0;
    for(int i=0; i < cap; ++i){
        if(val == cont[i]) removed=1;
        if(removed) cont[i] = cont[i+1];
    }
    if(removed) cap--;
    else std::cout<< "Value is invalid" << std::endl;
}

template <class T>
void ArrayContainer<T>::removeFirst(){
    for(int i=0; i < cap; ++i)
        cont[i] = cont[i+1];
    cap--;
}

template <class T>
void ArrayContainer<T>::removeLast(){
    cap--;
}

template <class T>
T ArrayContainer<T>::getVal(int pos){
    if(pos < cap) return cont[pos];
    std::cout<< "Position is invalid" << std::endl;
    T k;
    if(std::is_same<T, int>::value || std::is_same<T, float>::value || std::is_same<T, double>::value) k = -1;
    return k;
}

template <class T>
int ArrayContainer<T>::getPos(T const& val){
    for(int i=0; i<cap; ++i)
        if(cont[i] == val) return i;

    std::cout<< "Position is invalid" << std::endl;
    return -1;
}

template <class T>
T ArrayContainer<T>::getFirst(){
    return cont[0];
}

template <class T>
T ArrayContainer<T>::getLast(){
    return cont[cap-1];
}

template <class T>
int ArrayContainer<T>::getSize(){
    return cap;
}

template <class T>
int ArrayContainer<T>::getMaxSize(){
    return size;
}

#endif // CONTAIN_HPP
