#include <iostream>
#include <thread>
#include <mutex> // Required for locks
using namespace std;
int counter = 0;
mutex mtx; // The "key"

void safe_increment() {
     mtx.lock();
    for (int i = 0; i < 10000; i++) {
        // 1. Acquire the lock
      //   lock_guard<mutex> lock(mtx); 
        
        // 2. Critical Section (Only one thread can be here at a time)
        counter++; 
        
        // 3. Lock is automatically released when 'lock' goes out of scope (RAII)
    }
    mtx.unlock();
}

int main() {
    thread t1(safe_increment);
    thread t2(safe_increment);

    t1.join();
    t2.join();

    cout << "Final Counter: " << counter << endl; // Always 20000
    return 0;
}