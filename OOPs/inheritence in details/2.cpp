// multi level inheritence
#include<bits/stdc++.h>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "This mammal walks." << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	#ifndef SPOJ
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    Dog myDog;
    myDog.eat();
    myDog.walk();
    myDog.bark();
	return 0;
}