#include "h11.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>

//----------------------------------------- 222
DoublyList42::Node::Node(int d) {
    data = d;
    prev = nullptr;
    next = nullptr;
}

DoublyList42::DoublyList42() { //конструктор
    head = nullptr;
}

DoublyList42::DoublyList42(const DoublyList42& other) { //конструктор копирования
    head = nullptr;
    Node* p = other.head;
    if (!p) {
        return;
    }
    do {
        push_back(p->data);
        p = p->next;
    } while (p != other.head);
}

DoublyList42::~DoublyList42() { //деструктор
    if (!head) {
        return;
    }
    Node* p = head->next;

    while (p != head) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    delete head;
}

void DoublyList42::push_back(int value) { //функция добавления элемента
    Node* n = new Node(value);
    if (!head) {
        head = n;
        head->next = head;
        head->prev = head;
        return;
    }
    Node* tail = head->prev;
    tail->next = n;
    n->prev = tail;
    n->next = head;
    head->prev = n;
}

void DoublyList42::print() { //функция вывода в консоль
    if (!head) {
        return;
    }
    Node* p = head;
    do {
        std::cout << p->data << " ";
        p = p->next;
    } while (p != head);
    std::cout << std::endl;
}

void DoublyList42::solveListWork42() { 
    if (!head) {
        return;
    }
    Node* p = head;
    do {
        Node* left = p->prev; //ставим указатель на предыдущий элемент
        Node* right = p->next; //ставим указатеь на следующий элемент
        Node* nextNode = p->next; //сохраняем следующий элемент
        if (left->data == right->data && p != left && p != right) {
            left->next = right; //меняем связи между элементами и далее удаляем
            right->prev = left;

            if (p == head) { //передвигаем на следующий элемент
                head = right;
            }
            delete p;
        }
        p = nextNode; //переходим дальше
    } 
    while (p != head);
}

void ListWork42() {
    DoublyList42 list;

    list.push_back(5);
    list.push_back(1);
    list.push_back(5);
    list.push_back(2);
    list.push_back(3);

    std::cout << "Исходный список:\n";
    list.print();
    list.solveListWork42();
    std::cout << "Измененный список:\n";
    list.print();
}


//---------------------------------------------- 33333
DoublyList43::Node::Node(int d) {
    data = d;
    prev = nullptr;
    next = nullptr;
}

DoublyList43::DoublyList43() { //конструктор
    head = nullptr;
    tail = nullptr;
}

DoublyList43::DoublyList43(const DoublyList43& other) { //конструктор копирования
    head = tail = nullptr;
    Node* p = other.head;
    while (p) {
        push_back(p->data);
        p = p->next;
    }
}

DoublyList43::~DoublyList43() { //деструктор
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyList43::push_back(int value) { //функция добавления элемента
    Node* n = new Node(value);
    if (!head) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void DoublyList43::print() { //функция вывода в консоль
    Node* p = head;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void DoublyList43::solveListWork43() {
    if (!head || !head->next) {
        return;
    }
    Node* p = head; //создаем указатель на голову
    int index = 1; //счетчик индексов (нумерация с единицы)
    Node* originalTail = tail; //создаем указатель на хвост
    while (p != originalTail->next) {
        Node* nextNode = p->next; //запоминаем следующий элемент
        if (index % 2 == 1) { //если элемент находится на нечетной позиции
            if (p == head) {
                head = p->next; //перемещаем голову
            }
            if (p->prev) {
                p->prev->next = p->next; //меняем связи 
            }
            if (p->next) {
                p->next->prev = p->prev; //меняем связь
            }
            tail->next = p; //добавляем элемент в конец
            p->prev = tail; //соединяем связи
            p->next = nullptr;

            tail = p;
        }
        index++;
        p = nextNode; //переход к следующему элементу
    }
}

void ListWork43() {
    DoublyList43 list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    std::cout << "Исходный список:\n";
    list.print();

    list.solveListWork43();

    std::cout << "Измененный список:\n";
    list.print();
}

//-------------------------------------------------- 444
DoublyList46::Node::Node(int d) {
    data = d;
    prev = nullptr;
    next = nullptr;
}

DoublyList46::DoublyList46() { //конструктор
    head = nullptr;
    tail = nullptr;
}

DoublyList46::~DoublyList46() { //деструктор
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyList46::push_back(int value) { //функция добавления элемента
    Node* n = new Node(value);
    if (!head) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void DoublyList46::print() { //функция вывода в консоль
    Node* p = head;
    while (p) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

DoublyList46::Node* DoublyList46::solveListWork46() {
    Node* bar = new Node(0); //создаем необходимый барьер сразу со значением 0
    if (!head) {
        bar->next = bar; //ставим связи с самим собой
        bar->prev = bar;
        return bar;
    }
    bar->next = head; //связываем с головой
    bar->prev = tail; //связываем с хвостом
    head->prev = bar; 
    tail->next = bar;

    return bar;
}

void ListWork46() {
    DoublyList46 list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "Исходный список:\n";
    list.print();   
   
    DoublyList46::Node* bar = list.solveListWork46();
    std::cout << "Барьер создан (значение): " << bar->data << std::endl;
    std::cout << "Измененный список с барьером:\n";
    DoublyList46::Node* p = bar;
    do {
        std::cout << p->data << " ";
        p = p->next;
    } while (p != bar);
    std::cout << std::endl;
}

//------------------------------------------------------------------------------------------ 111
CircularList68::Node::Node(int d) {
    data = d;
    next = nullptr;
}

CircularList68::CircularList68() { //конструктор
    head = nullptr;
}

CircularList68::~CircularList68() { //деструктор
    if (!head) {
        return;
    }
    Node* p = head->next;
    while (p != head) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    delete head;
}

void CircularList68::push_back(int value) { //функция добавления элемента
    Node* n = new Node(value);
    if (!head) {
        head = n;
        head->next = head;
        return;
    }
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = n;
    n->next = head; 
}

void CircularList68::print() { //функция вывода в консоль
    if (!head) { 
        return; 
    }
    Node* p = head;
    do {
        std::cout << p->data << " ";
        p = p->next;
    } while (p != head);
    std::cout << std::endl;
}

void CircularList68::solveListWork68(const char* filename) {
    std::ofstream fout(filename); //открываем файл для записи
    if (!head)  { 
        return;
    }
    Node* p = head; //создаем указатель и ставим его на голову
    Node* prev = nullptr; 

    Node* temp = head; //создаем указатель и ставим его на голову
    while (temp->next != head) { //ищем последний элемент списка
        temp = temp->next; //передвигаем этот указатель
    }
    prev = temp; //этот указатель становится последним (хвостом)
    while (head) {
        for (int i = 1; i < 4; i++) { //передвижение на 4 элемент
            prev = p;
            p = p->next;
        }
        fout << p->data << " ";// записываем в файл
        if (p == p->next) { //если один элемент остался удаляем
            delete p;
            head = nullptr;
            break;
        }
        prev->next = p->next;
        if (p == head) {
            head = p->next; //обновляем голову
        }
        Node* toDelete = p; 
        p = p->next;
        delete toDelete; //удаляем узел
    }
    fout.close();
}

void ListWork68() {
    CircularList68 list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    std::cout << "Исходный список:\n";
    list.print();

    list.solveListWork68("a.txt");

    std::cout << "Результат записан в файл a.txt\n";
}

//------------------------------------------------------------- 5555


CircularList7::Node::Node(int d) {
    data = d;
    next = nullptr;
}

CircularList7::CircularList7() { //конструктор
    head = nullptr;
}

CircularList7::~CircularList7() { //деструктор
    if (!head) {return;}
    Node* cur = head->next;
    while (cur != head) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    delete head;
}

void CircularList7::push_back(int value) { //функция добавления элемента
    Node* n = new Node(value);
    if (!head) {
        head = n;
        head->next = head;
        return;
    }
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = n;
    n->next = head;
}

void CircularList7::print() { //функция вывода в консоль
    if (!head) { return; }
    Node* p = head;
    do {
        std::cout << p->data << " ";
        p = p->next;
    } while (p != head);
    std::cout << std::endl;
}

void CircularList7::findMax() {
    if (!head) {return;}
    std::vector<int> best; //создаем вектор для хранения самой длинной последовательности
    Node* start = head; //создаем указатель на голову
    do {
        std::vector<int> current; //создаем вектор для хранения текущей последовательности
        Node* p = start;

        current.push_back(p->data); //добавляем элемент в вектор
        Node* nextNode = p->next; //переходим на следующий элемент

        while (nextNode != start && nextNode->data <= p->data) { //проверка на то вернулись ли в начало или послед. не возрастает
            current.push_back(nextNode->data); //добавляем
            p = nextNode; //передвигаемся
            nextNode = nextNode->next;
        }
        if (current.size() > best.size()) { //если нашли длиннее послед. сохраняем в вектор best
            best = current;
        }

        start = start->next;

    } while (start != head); //пока не дошли до конца
    std::cout << "Максимальная невозрастающая последовательность:\n";
    for (int x : best) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void number7() {
    CircularList7 list;
    list.push_back(-4);
    list.push_back(-12);
    list.push_back(-7);
    list.push_back(-1);
    list.push_back(-8);
    list.push_back(-1);
    list.push_back(-2);
    list.push_back(-4);

    list.print();

    list.findMax();
}