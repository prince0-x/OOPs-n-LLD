#include <iostream>
#include <thread> // Required for multithreading

// This is the function the thread will execute
void cpu_waster() {
    std::cout << "Worker: Cooking the pasta...\n";
}

int main() {
    std::cout << "Main: Ordering ingredients.\n";

    // 1. Create a thread named 't1' that runs 'cpu_waster'
    std::thread t1(cpu_waster);

    std::cout << "Main: Setting the table.\n";

    // 2. Wait for t1 to finish before exiting main
    // If you forget this, the program might crash because main dies before t1 finishes.
    t1.join(); 

    std::cout << "Main: Dinner is served!\n";
    return 0;
}