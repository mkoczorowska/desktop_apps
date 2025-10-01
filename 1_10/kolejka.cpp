#include "Kolejka.h"
#include <iostream>

using namespace std;

Kolejka::Kolejka() : front(nullptr), rear(nullptr) {}

Kolejka::~Kolejka() {
    while (front) {
        dequeue();
    }
}

void Kolejka::enqueue(int val) {
    KolejkaNode* nowy = new KolejkaNode{ val, nullptr };
    if (!rear) {
        front = rear = nowy;
    }
    else {
        rear->next = nowy;
        rear = nowy;
    }
}

void Kolejka::dequeue() {
    if (!front) return;
    KolejkaNode* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

int Kolejka::peek() {
    if (!front) throw runtime_error("Kolejka pusta!");
    return front->data;
}

bool Kolejka::empty() {
    return front == nullptr;
}

void Kolejka::wypisz() {
    KolejkaNode* temp = front;
    while (temp) {
        std::cout << temp->data << " <- ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}
