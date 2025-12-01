#include <iostream>
#include <future> // Required for async
#include <thread> // <--- ADD THIS
#include <chrono> // <--- ADD THIS
int square(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate hard work
    return x * x;
}

int main() {
    // Launch 'square(10)' in a background thread immediately
    
    std::future<int> result = std::async(std::launch::async, square, 10);
    std::cout<<"hello its prince "<<"\n";
    std::cout << "Main is doing other work while waiting...\n";
    
    // .get() blocks main until the result is ready
    int value = result.get(); 

    std::cout << "Result: " << value << std::endl;
    return 0;
}