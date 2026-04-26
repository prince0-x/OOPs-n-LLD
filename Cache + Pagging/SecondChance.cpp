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
 *  6. Second Chance  (a.k.a. Clock approximation of LRU)
 * ============================================================
 *  Idea: FIFO + a reference bit per page. On eviction, if the
 *  oldest page has its bit set, clear it and give a second
 *  chance instead of evicting.
 */
class SecondChanceCache {
private:
    int capacity;
    list<pair<int,bool>> frames;                    // (page, refBit)
    unordered_map<int, list<pair<int,bool>>::iterator> map;
    int hits, misses;

public:
    SecondChanceCache(int cap) : capacity(cap), hits(0), misses(0) {}

    void refer(int page) {
        if (map.count(page)) {                      // HIT - set ref bit
            hits++;
            map[page]->second = true;
            return;
        }
        misses++;                                   // MISS
        if ((int)frames.size() == capacity) {
            while (true) {
                auto& front = frames.front();
                if (front.second) {                 // second chance
                    front.second = false;
                    frames.push_back(front);
                    map[front.first] = prev(frames.end());
                    frames.pop_front();
                } else {
                    map.erase(front.first);
                    frames.pop_front();
                    break;
                }
            }
        }
        frames.push_back({page, false});
        map[page] = prev(frames.end());
    }

    void display() const {
        cout << "Second-Chance Cache (page,bit): ";
        for (auto& p : frames) cout << "(" << p.first << "," << p.second << ") ";
        cout << "\n";
    }

    void stats() const {
        cout << "SC   -> Hits: " << hits << ", Misses: " << misses << "\n";
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


    SecondChanceCache sc(capacity);

    for (int p : refString) {
        sc.refer(p);
    }
    sc.display();

    cout << "\nStatistics:\n";
    sc.stats();

    return 0;
}
