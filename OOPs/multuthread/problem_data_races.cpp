#include <iostream>
#include <thread>
// counter is shared by two different thread 
int counter = 0; // Shared resource

void increment() {
    for (int i = 0; i < 10000; i++) {
        counter++; 
        // This isn't atomic! It's 3 steps:
        // 1. Read counter
        // 2. Add 1
        // 3. Write back
        // Threads interrupt each other in the middle of these steps.
    }
}

int main() {
    std::thread t1(increment);
//     std::thread t2(increment);

    t1.join();
//     t2.join();

    // You expect 20000, but you will get random numbers like 14532 or 19800.
    std::cout << "Final Counter: " << counter << std::endl; 
    return 0;
}