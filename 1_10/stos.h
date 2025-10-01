#pragma once
#ifndef STOS_H
#define STOS_H

struct StosNode {
    int data;
    StosNode* next;
};

class Stos {
private:
    StosNode* top;

public:
    Stos();
    ~Stos();

    void push(int val);
    void pop();
    int peek();
    bool empty();
    void wypisz();
};

#endif
