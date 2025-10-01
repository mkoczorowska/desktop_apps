#include "Stos.h"
#include <iostream>

using namespace std;

Stos::Stos() : top(nullptr) {}

Stos::~Stos() {
    while (top) {
        pop();
    }
}

void Stos::push(int val) {
    StosNode* nowy = new StosNode{ val, top };
    top = nowy;
}

void Stos::pop() {
    if (!top) return;
    StosNode* temp = top;
    top = top->next;
    delete temp;
}

int Stos::peek() {
    if (!top) throw runtime_error("Stos pusty!");
    return top->data;
}

bool Stos::empty() {
    return top == nullptr;
}

void Stos::wypisz() {
    StosNode* temp = top;
    while (temp) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
}
