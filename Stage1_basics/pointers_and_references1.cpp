/*
The thing about pointers and references is that when to use which?
From coding in C, I feel like pointers are more comfortable, but references?
There must be a reason people use it. But what is that?
https://www.reddit.com/r/cpp/comments/18186it/i_am_absolutely_confused_on_the_topic_of/?rdt=59056
*/

#include <iostream>

struct Data {
    int a;
    int b;
    double c;
};

//pass-by-value (copies the whole struct)
void passByValue(Data d) {
    d.a = 100;
}

//pass-by-reference (uses address)
void passByReference(Data& d) {
    d.a = 200; //modifies the original
}

//pass-by-pointer (explicitly uses address)
void passByPointer(Data* d) {
    if (d) d->a = 300; //modifies the original
}

int main() {
    Data data = {1,2,3.14};

    passByValue(data);
    passByReference(data);
    passByPointer(&data);

    return 0;
}

//g++ -O0 -masm=intel -S pointers_and_references1.cpp