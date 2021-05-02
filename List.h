#pragma once
#include <iostream>
#include "organism.h"

using namespace std;

class Node {
    Organism* value;
    Node* next = nullptr;
    Node* prev = nullptr;
public:
    Node(Organism* startValue) : value(startValue) {}
    Node(Organism* startValue, Node* startNext, Node* startPrev) : value(startValue), next(startNext), prev(startPrev) {}

    void setValue(Organism* newValue) {
        value = newValue;
    }
    void setNext(Node* newNext) {
        next = newNext;
    }
    void setPrev(Node* newPrev) {
        prev = newPrev;
    }
    const int getValue() {
        return value->getActivity();
    }
    Node* getNext() {
        return next;
    }
    Node* getPrev() {
        return prev;
    }
    Organism* getOrganism() {
        return value;
    }
};

//lista dwukierunkowa
class List {
public:
    Node* first = nullptr;
    Node* last = nullptr;

    int size() {
        if (first == nullptr) return 0;
        else {
            int liczba = 1;
            Node* temporary = first;
            while (temporary != last) {
                temporary = temporary->getNext();
                liczba++;
            }
            return liczba;
        }
    }

    void PUSH(Organism* newValue) {
        if (!size()) {
            Node* newNode = new Node(newValue);
            newNode->setNext(newNode);
            newNode->setPrev(newNode);
            first = newNode;
            last = newNode;
        }
        else if (size() == 1) {
            Node* newNode = new Node(newValue, first, last);
            if (last->getValue() >= newValue->getActivity()) {
                first->setNext(newNode);
                first->setPrev(newNode);
                last = newNode;
            }
            else {
                last->setNext(newNode);
                last->setPrev(newNode);
                first = newNode;
            }
        }
        else {
            if (first->getValue() < newValue->getActivity()) {
                Node* newNode = new Node(newValue, first, last);
                last->setNext(newNode);
                first->setPrev(newNode);
                first = newNode;
            }
            else if (last->getValue() >= newValue->getActivity()) {
                Node* newNode = new Node(newValue, first, last);
                last->setNext(newNode);
                first->setPrev(newNode);
                last = newNode;
            }
            else {
                Node* temp = last;
                do {
                    if (temp->getValue() >= newValue->getActivity()) {
                        Node* newNode = new Node(newValue, temp->getNext(), temp);
                        temp->getNext()->setPrev(newNode);
                        temp->setNext(newNode);
                        break;
                    }
                    temp = temp->getPrev();
                } while (temp != last);
            }
        }
    }

    //wywo³uje akcje przy ka¿dym organizmie
    //lista jets ju¿ posortowana ze wzgledu na inicjatywe
    //wiêc wystarczy iterowac od poczatku
    void MAKE_ACTION() {
        if (size()){
            Node* temporary = first;
            Node* next = temporary->getNext();

            temporary->getOrganism()->move();
            temporary->getOrganism()->action();

            while (temporary != last) {
                Node* temp = first;
                while (true) {
                    if (temp == temporary) {
                        temporary = temporary->getNext();
                        next = temporary->getNext();
                        break;
                    }
                    else if (temp == next) {
                        temporary = next;
                        next = temporary->getNext();
                        break;
                    }
                    else {
                        temp = temp->getNext();
                    }
                }
                
                temporary->getOrganism()->move();
                temporary->getOrganism()->action();
            }
        }
    }

    //usuwa podany element z listy
    void DELETE_ELEMENT(Organism* el) {
        if (size() == 1) {
            delete first;
            first = nullptr;
            last = nullptr;
        }
        else if(size() > 1) {
            if (first->getOrganism() == el) {
                Node* temp = first->getNext();
                delete first;
                first = temp;
                first->setPrev(last);
                last->setNext(first);
            }
            else if (last->getOrganism() == el) {
                Node* temp = last->getPrev();
                delete last;
                last = temp;
                last->setNext(first);
                first->setPrev(last);
            }
            else {
                Node* temp = first;
                while (temp != last) {
                    temp = temp->getNext();
                    if (temp->getOrganism() == el) {
                        Node* prev = temp->getPrev();
                        Node* next = temp->getNext();
                        delete temp;
                        prev->setNext(next);
                        next->setPrev(prev);
                        break;
                    }
                }
            }
        }
    }
    void PRINT_FORWARD() {
        if (!size()) cout << "NULL" << endl;
        else {
            Node* temporary = first;
            cout << temporary->getValue() << " ";
            while (temporary != last) {
                temporary = temporary->getNext();
                cout << temporary->getValue() << " ";
            }
            cout << "|||||"<<endl;
        }
    }
    void PRINT_BACKWARD() {
        if (!size()) cout << "NULL" << endl;
        else {
            Node* temporary = last;
            cout << temporary->getValue() << " ";
            while (temporary != first) {
                temporary = temporary->getPrev();
                cout << temporary->getValue() << " ";
            }
            cout << endl;
        }
    }
};

