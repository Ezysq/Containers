#pragma once

#include <iostream>

template<class T>
class ListContainer{
    struct node {
        T data;
        node *next, *prev;
        node(): data(NULL), next(nullptr), prev(nullptr) {}
        node(T const& dat, node* nex, node* pre): data(dat), next(nex), prev(pre) {}
    };

    int capacity;
    node *head;
    node *tail;
public:

    ListContainer(): capacity(0), head(nullptr), tail(nullptr){}
    ~ListContainer();
    /* adding to the front and back */
    void pushBack(T const& val);
    void pushFront(T const& val);
    /* deleting from the front and back */
    void popBack();
    void popFront();
    /* get first / last */
    T getFirst();
    T getLast();
    /* get by postition */
    T get(int pos);
    T operator[](int pos);
    /* get list size -*/
    int getSize();
    /* print list */
    void print();

};

template<class T>
ListContainer<T>::~ListContainer(){
    if(head != nullptr){
        node* temp;
        while(tail != nullptr){
            temp = tail;
            tail=tail->prev;
            delete temp;
        }
    }
}

template<class T>
void ListContainer<T>::pushBack(T const& val){
    node* newNode= new node(val, nullptr, tail);
    if(head == nullptr)
        head = newNode;
    if(tail != nullptr)
        tail->next = newNode;
    tail = newNode;
    capacity++;
}

template<class T>
void ListContainer<T>::pushFront(T const& val){
    node* newNode= new node(val, head, nullptr);
    if(tail == nullptr)
        tail = newNode;
    if(head != nullptr)
        head->prev = newNode;
    head = newNode;
    capacity++;
}

template<class T>
void ListContainer<T>::popBack(){
    if(tail == nullptr)
        std::cout << "List is empty" << std::endl;

    node* temp=tail;
    tail=tail->prev;

    if(tail != nullptr)
        tail->next=nullptr;

    delete temp;
    capacity--;
}

template<class T>
void ListContainer<T>::popFront(){
    if(head == nullptr)
        std::cout << "List is empty" << std::endl;

    node* temp=head;
    head=head->next;

    if(head != nullptr)
        head->prev=nullptr;

    delete temp;
    capacity--;
}

template<class T>
T ListContainer<T>::getFirst(){
    return head->data;
}

template<class T>
T ListContainer<T>::getLast(){
    return tail->data;
}

template<class T>
T ListContainer<T>::operator[](int pos){
    if(pos < 0) std::cout << "Must be positive number" << std::endl;
    else{
        if(pos < capacity/2){
            int i=0;
            node* temp=head;

            while(i != pos){
                temp=temp->next;
                i++;
            }

            return temp->data;
        }

        else if(pos < capacity){
            pos++;
            int i=capacity;
            node* temp=tail;

            while(i != pos){
                temp=temp->prev;
                i--;
            }

            return temp->data;
        }
        else
            std::cout << "Position bigger than capacity" << std::endl;
    }

}

template<class T>
T ListContainer<T>::get(int pos){
    if(pos < 0) std::cout << "Must be positive number" << std::endl;
    else{
        if(pos < capacity/2){
            int i=0;
            node* temp=head;

            while(i != pos){
                temp=temp->next;
                i++;
            }

            return temp->data;
        }

        else if(pos < capacity){
            pos++;
            int i=capacity;
            node* temp=tail;

            while(i != pos){
                temp=temp->prev;
                i--;
            }

            return temp->data;
        }
        else
            std::cout << "Position bigger than capacity" << std::endl;
    }
}

template<class T>
int ListContainer<T>::getSize(){
    return capacity;
}

template<class T>
void ListContainer<T>::print(){
    node* iter=head;
    while(iter != nullptr){
        std::cout<< iter->data << " ";
        iter=iter->next;
    }
    std::cout<< std::endl;
}

