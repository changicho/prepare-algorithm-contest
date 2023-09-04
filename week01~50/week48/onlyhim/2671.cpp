#include <unordered_map>
#include <vector>
using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() {
        um.clear();
        freq.clear();
        freq.resize(200003, 0);
    }

    void add(int number) {
        if (freq[um[number]] > 0)   freq[um[number]]--;
        freq[++um[number]]++;
    }

    void deleteOne(int number) {
        if (um[number] > 0) {
            freq[um[number]--]--;
            freq[um[number]]++;
        }
    }

    bool hasFrequency(int frequency) {
        return freq[frequency] > 0;
    }
private:
    unordered_map<int, int> um;
    vector<int> freq;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
