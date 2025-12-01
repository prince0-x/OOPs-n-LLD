#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <condition_variable> // NEW HEADER
using namespace std;
queue<int> data_queue;
mutex mtx;
condition_variable cv; // The "Bell" to wake up threads
bool done = false; // Flag to stop the consumer

void producer() {
    for (int i = 1; i <= 5; ++i) {
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate work
        
        // Lock the mutex to modify the queue
        unique_lock<mutex> lock(mtx);
        data_queue.push(i);
        cout << "Producer: Produced " << i << "\n";
        
        // Manual unlocking is optional here, but good practice 
        // so the consumer can grab it immediately after notification
        lock.unlock(); 
        
        // Ring the bell! Wake up the consumer
        cv.notify_one();
    }
    
    // Signal that we are finished
    lock_guard<mutex> lock(mtx);
    done = true;
    cv.notify_one(); // Wake consumer one last time to check 'done'
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);

        // WAIT until queue has data OR work is done
        // This line puts the thread to SLEEP. It releases the lock automatically.
        cv.wait(lock, []{ return !data_queue.empty() || done; });

        // Once we wake up, we automatically re-acquire the lock.
        
        if (!data_queue.empty()) {
            int data = data_queue.front();
            data_queue.pop();
            cout << "Consumer: Ate " << data << "\n";
        } else if (done) {
            // Queue is empty AND producer is done. We can exit.
            break; 
        }
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}