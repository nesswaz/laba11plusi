#include <vector>
#include <string>
#pragma once
#include <iostream>



class DoublyList42 {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int d);
    };
    Node* head;
public:
    DoublyList42();
    DoublyList42(const DoublyList42& other);
   ~DoublyList42();
    void push_back(int value);
    void print();
    void solveListWork42(); // решение задачи
};

void ListWork42(); // функция демонстрации

//----------------------------------------------------

class DoublyList43 {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int d);
    };
    Node* head;
    Node* tail;
public:
    DoublyList43();
    DoublyList43(const DoublyList43& other);
    ~DoublyList43();

    void push_back(int value);
    void print();
    void solveListWork43();
};
void ListWork43();

//-------------------------------------
class DoublyList46 {
public:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int d);
    };
private:
    Node* head;
    Node* tail;
public:
    DoublyList46();
    ~DoublyList46();
    void push_back(int value);
    void print();
    Node* solveListWork46();
};
void ListWork46();

//----------------------------------

class CircularList68 {
private:
    struct Node {
        int data;
        Node* next;

        Node(int d);
    };
    Node* head;
public:
    CircularList68();
    ~CircularList68();
    void push_back(int value);
    void print();
    void solveListWork68(const char* filename);
};
void ListWork68();

//--------------------------------------------------


class CircularList7 {
private:
    struct Node {
        int data;
        Node* next;

        Node(int d);
    };

    Node* head;
public:
    CircularList7();
    ~CircularList7();
    void push_back(int value);
    void print();
    void findMax();
};
void number7();