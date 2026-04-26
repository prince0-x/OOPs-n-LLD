#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


/* ============================================================
 *  2. FIFO  (First In First Out)
 * ============================================================
 *  Idea: Evict the page that was loaded earliest, regardless of
 *  how recently it was accessed.
 */
class FIFOCache {
private:
    int capacity;
    queue<int> q;
    unordered_map<int, bool> present;
    int hits, misses;

public:
    FIFOCache(int cap) : capacity(cap), hits(0), misses(0) {}

    void refer(int page) {
        if (present[page]) {                        // HIT
            hits++;
            return;
        }
        misses++;                                   // MISS
        if ((int)q.size() == capacity) {
            int old = q.front(); q.pop();
            present[old] = false;
        }
        q.push(page);
        present[page] = true;
    }

    void display() const {
        cout << "FIFO Cache [Oldest -> Newest]: ";
        queue<int> tmp = q;
        while (!tmp.empty()) { cout << tmp.front() << " "; tmp.pop(); }
        cout << "\n";
    }

    void stats() const {
        cout << "FIFO -> Hits: " << hits << ", Misses: " << misses << "\n";
    }
};




/* ============================================================
 *                          DRIVER
 * ============================================================ */
int main() {
    vector<int> refString = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int capacity = 4;

    cout << "Reference string: ";
    for (int p : refString) cout << p << " ";
    cout << "\nCapacity: " << capacity << "\n";
    cout << "------------------------------------------------\n";

    
    FIFOCache         fifo(capacity);
    for (int p : refString) {
        fifo.refer(p);
    }

    cout << "\nFinal cache states:\n";
    fifo.display();

    cout << "\nStatistics:\n";
    fifo.stats();

    return 0;
}
