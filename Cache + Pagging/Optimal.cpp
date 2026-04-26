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
 *  5. Optimal  (Belady's Algorithm)
 * ============================================================
 *  Idea: Evict the page whose next use is farthest in the
 *  future. Theoretical lower bound on misses; needs the entire
 *  reference string in advance.
 */
class OptimalCache {
private:
    int capacity;
    vector<int> frames;
    vector<int> refString;
    int hits, misses;

    int findVictim(int currentIndex) const {
        int farthest = currentIndex, victim = 0;
        for (int i = 0; i < (int)frames.size(); ++i) {
            int j;
            for (j = currentIndex + 1; j < (int)refString.size(); ++j) {
                if (refString[j] == frames[i]) {
                    if (j > farthest) { farthest = j; victim = i; }
                    break;
                }
            }
            if (j == (int)refString.size()) return i;   // never used again
        }
        return victim;
    }

public:
    OptimalCache(int cap, const vector<int>& refs)
        : capacity(cap), refString(refs), hits(0), misses(0) {}

    void run() {
        for (int i = 0; i < (int)refString.size(); ++i) {
            int page = refString[i];
            if (find(frames.begin(), frames.end(), page) != frames.end()) {
                hits++;
            } else {
                misses++;
                if ((int)frames.size() < capacity) frames.push_back(page);
                else                                frames[findVictim(i)] = page;
            }
        }
    }

    void display() const {
        cout << "Optimal Cache: ";
        for (int p : frames) cout << p << " ";
        cout << "\n";
    }

    void stats() const {
        cout << "OPT  -> Hits: " << hits << ", Misses: " << misses << "\n";
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


    OptimalCache      opt(capacity, refString);

  
    opt.run();

    cout << "\nFinal cache states:\n";
    opt.display();

    cout << "\nStatistics:\n";
    opt.stats();

    return 0;
}
