#include "Lista.h"
#include <iostream>

using namespace std;

Lista::Lista() : head(nullptr) {}

Lista::~Lista() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Lista::dodajNaPoczatek(int val) {
    Node* nowy = new Node{ val, head };
    head = nowy;
}

void Lista::dodajNaKoniec(int val) {
    Node* nowy = new Node{ val, nullptr };
    if (!head) {
        head = nowy;
    }
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = nowy;
    }
}

void Lista::dodajPoElemencie(int poJakim, int val) {
    Node* temp = head;
    while (temp && temp->data != poJakim) temp = temp->next;
    if (temp) {
        Node* nowy = new Node{ val, temp->next };
        temp->next = nowy;
    }
}

void Lista::dodajPrzedElemencie(int przedJakim, int val) {
    if (!head) return;

    if (head->data == przedJakim) {
        dodajNaPoczatek(val);
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr && curr->data != przedJakim) {
        prev = curr;
        curr = curr->next;
    }

    if (curr) {
        Node* nowy = new Node{ val, curr };
        prev->next = nowy;
    }
}

void Lista::usunZPoczatku() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void Lista::usunZKonca() {
    if (!head) return;

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }

    delete curr;
    prev->next = nullptr;
}

void Lista::usunElement(int val) {
    if (!head) return;

    if (head->data == val) {
        usunZPoczatku();
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr) {
        prev->next = curr->next;
        delete curr;
    }
}

Node* Lista::szukaj(int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void Lista::wypisz() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
