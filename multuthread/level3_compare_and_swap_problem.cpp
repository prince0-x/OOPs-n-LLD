#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> account_balance(100);

void multiply_balance() {
    int expected_value;
    int new_value;

    do {
        // 1. Load current value
        expected_value = account_balance.load(); 
        
        // 2. Calculate desired value
        new_value = expected_value * 2;

        // 3. Try to update:
        // "If account_balance is still 'expected_value', set it to 'new_value'.
        //  Otherwise, update 'expected_value' with the actual current balance and return false."
    } while (!account_balance.compare_exchange_weak(expected_value, new_value));
    
    // If we exit the loop, it means we successfully updated the variable 
    // without anyone else interfering in that split second.
}

int main() {
    std::thread t1(multiply_balance);
    std::thread t2(multiply_balance);

    t1.join();
    t2.join();

    std::cout << "Final Balance: " << account_balance << "\n"; 
    // Should be 400 (100 * 2 * 2)
    return 0;
}