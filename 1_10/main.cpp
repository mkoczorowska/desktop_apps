#include <iostream>
#include "Lista.h"
#include "Stos.h"
#include "Kolejka.h"

using namespace std;

int main() {
    cout << "=== Lista ===\n";
    Lista lista;
    lista.dodajNaPoczatek(3);
    lista.dodajNaKoniec(5);
    lista.dodajNaKoniec(7);
    lista.dodajPoElemencie(5, 6);
    lista.dodajPrzedElemencie(7, 4);
    lista.wypisz();

    lista.usunElement(5);
    lista.usunZPoczatku();
    lista.usunZKonca();
    lista.wypisz();

    if (lista.szukaj(6)) std::cout << "Znaleziono 6\n";

    std::cout << "\n=== Stos ===\n";
    Stos stos;
    stos.push(10);
    stos.push(20);
    stos.push(30);
    stos.wypisz();

    stos.pop();
    cout << "Top: " << stos.peek() << "\n";

    cout << "\n=== Kolejka ===\n";
    Kolejka kolejka;
    kolejka.enqueue(100);
    kolejka.enqueue(200);
    kolejka.enqueue(300);
    kolejka.wypisz();

    kolejka.dequeue();
    cout << "Front: " << kolejka.peek() << "\n";
    kolejka.wypisz();

    return 0;
}

