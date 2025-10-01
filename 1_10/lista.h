#ifndef LISTA_H
#define LISTA_H

struct Node {
    int data;
    Node* next;
};

class Lista {
private:
    Node* head;

public:
    Lista();
    ~Lista();

    void dodajNaPoczatek(int val);
    void dodajNaKoniec(int val);
    void dodajPoElemencie(int poJakim, int val);
    void dodajPrzedElemencie(int przedJakim, int val);

    void usunZPoczatku();
    void usunZKonca();
    void usunElement(int val);

    Node* szukaj(int val);
    void wypisz();
};

#endif
