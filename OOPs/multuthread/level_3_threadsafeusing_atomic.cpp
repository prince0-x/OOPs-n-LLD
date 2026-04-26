#include <iostream>
#include <thread>
#include <vector>
#include <atomic> 

using namespace std;

atomic<int> counter(0); // data type is atomic int  

void increment() {
    for (int i = 0; i < 100000; i++) {
        counter++; 
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Final Counter: " << counter << "\n";
    return 0;
}