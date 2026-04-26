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
 *  3. LFU  (Least Frequently Used)
 * ============================================================
 *  Idea: Evict the page that is referenced the fewest times.
 *  Ties broken by oldest insertion order.
 */
class LFUCache {
private:
    int capacity;
    unordered_map<int, int> freq;       // page -> frequency
    unordered_map<int, int> order;      // page -> insertion sequence (tiebreak)
    int counter;
    int hits, misses;

public:
    LFUCache(int cap) : capacity(cap), counter(0), hits(0), misses(0) {}

    void refer(int page) {
        if (freq.count(page)) {                     // HIT
            hits++;
            freq[page]++;
            return;
        }
        misses++;                                   // MISS
        if ((int)freq.size() == capacity) {
            // find page with min freq, break ties by oldest order
            int evict = -1, minFreq = INT_MAX, minOrder = INT_MAX;
            for (auto& p : freq) {
                if (p.second < minFreq ||
                   (p.second == minFreq && order[p.first] < minOrder)) {
                    minFreq = p.second;
                    minOrder = order[p.first];
                    evict = p.first;
                }
            }
            freq.erase(evict);
            order.erase(evict);
        }
        freq[page] = 1;
        order[page] = counter++;
    }

    void display() const {
        cout << "LFU Cache (page:freq): ";
        for (auto& p : freq) cout << p.first << ":" << p.second << "  ";
        cout << "\n";
    }

    void stats() const {
        cout << "LFU  -> Hits: " << hits << ", Misses: " << misses << "\n";
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

    
    LFUCache          lfu(capacity);

    for (int p : refString) {
        lfu.refer(p);
    }

    cout << "\nFinal cache states:\n";
    lfu.display();

    cout << "\nStatistics:\n";
    lfu.stats();

    return 0;
}
