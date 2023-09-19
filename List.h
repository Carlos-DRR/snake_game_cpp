#include <iostream>
#include "Node.h"

template <class T>

class List{
    private:
        Node <T> * head;
        Node <T> * tail;
        int size;
    public:
        List(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        } 

        bool empty(){
            return size == 0;
        }
        T getHead(){
            return head->getInfo();
        }
        void add(T info){
            Node <T> *node = new Node<T>(info);//next is null in constructor
            if(empty()){
                head = node;
                tail = node;
            }else{
                tail->setNext(node);
                tail = node;
            }   
            size += 1;
        }

        T removeLast(){
            T info;
            if(!empty()){
                Node <T> *current = head;
                Node <T> *previous = nullptr;
                while(current->getNext() != nullptr){
                    previous = current;
                    current = current->getNext();
                }
                info = current->getInfo();
                if(current == head){
                    head = nullptr;
                    tail = nullptr;
                }else{
                    previous->setNext(current->getNext());
                }
                delete current;
                
            }else throw "Empty list exception";
            size -= 1;
            return info;
        }

        void print(){
            Node <T> *current = head;
            while(current != nullptr){
                std::cout << current->getInfo() << std::endl;
                current = current->getNext();
            }
            delete current;
        }

};