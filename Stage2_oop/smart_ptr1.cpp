/*
Pointers are the variables that stores the memory addresses. 
They are extensively used in dynamic memory location to store the address
of allocated memory. But a lot of issues occure. 

Memory leaks:
Occurs when memory is repeatedly allocated by a program but never freed. 
This leads to excessive memory consumption and eventually leads to system crash. 

Wild pointers: 
A pointer that is never initialized with valid object or address. 

Dangling pointers: 
Assume there is a pointer that refers to memory which was deallocated earlier
in the program, that pointer is called a dangling pointer. 
*/

#include <iostream>

using namespace std;

// int main() {
//     while (1) {
//         //create a variable in heap memory using pointer
//         int* ptr = new int;
//     }
//   //oh well, memory leak...
//     return 0;
// }

/*
There are a few types of smart pointers.
auto_ptr, unique_ptr, shared_ptr, weak_ptr
*/

/*
auto_ptr is a smart pointer that automatically manages the lifetime of a 
dynamically allocated object. It takes ownership of the object it points to, 
ensuring that the object is automatically deleted when the auto_ptr goes out of scope 
*/

// #include <iostream>
// #include <memory>

// using namespace std;

// int main() {

//     //pointer declaration
//     auto_ptr<int> ptr1(new int(19));
//     cout << *ptr1 << endl;


//     //transfer ownership to pointer ptr2.
//     auto_ptr<int> ptr2 = ptr1;
//     cout << *ptr2;


//     return 0;
// }


/*
Unique pointer:
stores one pointer only at a time. We cannot copy unique pointer, only transfer 
ownership of the object to another unique_ptr using the move() method
*/

// #include <bits/stdc++.h>

// using namespace std; 

// class Rectangle {
//     int length;
//     int breadth;

//     public:
//         Rectangle(int l, int b) {
//             length = l;
//             breadth = b;
//         }

//         int area() {
//             return length * breadth;
//         }
// };

// int main() {
//     unique_ptr<Rectangle> P1(new Rectangle(10, 5));
//     cout << P1->area() << endl;

//     unique_ptr<Rectangle> P2;
//     //copy address of p1 into p2
//     P2 = move(P1);
//     cout << P2->area() << endl;

//     return 0;
// }

/*
shared_ptr
more than one pointer cna point to same object at a time, and it will maintain 
a reference counter using the user_count() method. 
*/

// #include <bits/stdc++.h>

// using namespace std;

// class Rectangle {
//     int length;
//     int breadth;

//     public:
//         Rectangle(int l, int b) {
//             length = l;
//             breadth = b;
//         }

//         int area() {
//             return (length * breadth);
//         }
// };

// int main() {
//     shared_ptr<Rectangle> P1(new Rectangle(10, 5));
//     cout << P1->area() << endl;

//     shared_ptr<Rectangle> P2;

//     //P1 and P2 are pointing to same object
//     P2 = P1;
//     cout << P2->area() << endl;
//     cout << P1->area() << endl;
//     cout << P1.use_count();


//     return 0;
// }


/*
weak_ptr
a smart pointer that holds a non-owning refrence to an object. It is much more
similiar to shared_ptr except it will not maintain a reference counter. In this case,
a pointer will not have a stronghold on the object. The reason is to avoid the circular
dependency created by two or more object pointing to each other using shared_ptr. 
*/
//Driver Code Starts{
#include <bits/stdc++.h>
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() { return length * breadth; }
};

int main() {
    // Create shared_ptr Smart Pointer
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    
    // Created a weak_ptr smart pointer
    weak_ptr<Rectangle> P2 (P1);
    cout << P1->area() << endl;
    
    // Returns the number of shared_ptr 
    // objects that manage the object
    cout << P2.use_count();
    return 0;
}