#pragma once
#ifndef KOLEJKA_H
#define KOLEJKA_H

struct KolejkaNode {
    int data;
    KolejkaNode* next;
};

class Kolejka {
private:
    KolejkaNode* front;
    KolejkaNode* rear;

public:
    Kolejka();
    ~Kolejka();

    void enqueue(int val);
    void dequeue();
    int peek();
    bool empty();
    void wypisz();
};

#endif
