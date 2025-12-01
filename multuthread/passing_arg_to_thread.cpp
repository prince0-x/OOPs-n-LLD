#include <iostream>
#include <thread>
#include <string>

void worker(std::string& s) {
    s = "Changed by Thread";
}

int main() {
    std::string str = "Original";

    // std::ref wraps the variable to pass it by reference
    std::thread t1(worker, std::ref(str));
    
    t1.join();
    std::cout << str << std::endl; // Output: "Changed by Thread"
    return 0;
}