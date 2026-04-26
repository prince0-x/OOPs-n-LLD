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
 *  1. LRU  (Least Recently Used)
 * ============================================================
 *  Idea: Evict the page that has not been used for the longest
 *  time. Implemented with a doubly-linked list + hash map for
 *  O(1) access and O(1) eviction.
 */
class LRUCache {
private:
    int capacity;
    list<int> dq;                                   // front = MRU, back = LRU
    unordered_map<int, list<int>::iterator> map;    // page -> node in dq
    int hits, misses;

public:
    LRUCache(int cap) : capacity(cap), hits(0), misses(0) {}

    void refer(int page) {
        if (map.find(page) == map.end()) {          // MISS
            misses++;
            if ((int)dq.size() == capacity) {
                int lru = dq.back();
                dq.pop_back();
                map.erase(lru);
            }
        } else {                                    // HIT
            hits++;
            dq.erase(map[page]);
        }
        dq.push_front(page);
        map[page] = dq.begin();
    }

    void display() const {
        cout << "LRU Cache [MRU -> LRU]: ";
        for (int p : dq) cout << p << " ";
        cout << "\n";
    }

    void stats() const {
        cout << "LRU  -> Hits: " << hits << ", Misses: " << misses << "\n";
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

    LRUCache          lru(capacity);

    for (int p : refString) {
        lru.refer(p);
    }

    cout << "\nFinal cache states:\n";
    lru.display();

    cout << "\nStatistics:\n";
    lru.stats();

    return 0;
}
