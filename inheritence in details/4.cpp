#include <iostream>
using namespace std;
// hybrid inheritence when inherited class also inherited from same 
//base class called diamond ambiguity
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Mammal : virtual public Animal {
};

class Bird : virtual public Animal {
};

class Bat : public Mammal, public Bird {
};



int main() {
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef SPOJ
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    Bat bat;
    bat.eat(); 
    return 0;
}
