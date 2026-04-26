#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "The cat meows." << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef SPOJ
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    Dog myDog;
    myDog.eat();  // Inherited from Animal
    myDog.bark(); // Defined in Dog

    Cat myCat;
    myCat.eat();  // Inherited from Animal
    myCat.meow(); // Defined in Cat

    return 0;
}
