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
 *  4. MRU  (Most Recently Used)
 * ============================================================
 *  Idea: Opposite of LRU. Evict the most recently used page.
 *  Useful when older data is more likely to be reused (e.g.
 *  database scans).
 */
class MRUCache {
private:
    int capacity;
    list<int> dq;                                   // front = MRU
    unordered_map<int, list<int>::iterator> map;
    int hits, misses;

public:
    MRUCache(int cap) : capacity(cap), hits(0), misses(0) {}

    void refer(int page) {
        if (map.count(page)) {                      // HIT
            hits++;
            dq.erase(map[page]);
        } else {                                    // MISS
            misses++;
            if ((int)dq.size() == capacity) {
                int mru = dq.front();               // evict MRU
                dq.pop_front();
                map.erase(mru);
            }
        }
        dq.push_front(page);
        map[page] = dq.begin();
    }

    void display() const {
        cout << "MRU Cache [MRU -> LRU]: ";
        for (int p : dq) cout << p << " ";
        cout << "\n";
    }

    void stats() const {
        cout << "MRU  -> Hits: " << hits << ", Misses: " << misses << "\n";
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

    MRUCache          mru(capacity);

    for (int p : refString) {
        mru.refer(p);
    }

    cout << "\nFinal cache states:\n";
    mru.display();

    cout << "\nStatistics:\n";
    mru.stats();

    return 0;
}


