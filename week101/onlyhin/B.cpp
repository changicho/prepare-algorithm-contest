#define N 200003

int count_in_vector_range(const std::map<int, std::vector<int>>& m, int key, int a, int b) {
    auto it = m.find(key);
    if (it == m.end()) return 0;

    const std::vector<int>& vec = it->second;

    // 정렬되어 있다는 가정 하에 수행
    auto low = std::lower_bound(vec.begin(), vec.end(), a); // 첫 a 이상 위치
    auto up = std::upper_bound(vec.begin(), vec.end(), b); // 첫 b 초과 위치

    return std::distance(low, up);
}

class Router {
public:
    Router(int memoryLimit) {
        lim = memoryLimit;
        while (!q.empty())   q.pop();
        sets.clear();
        maps.clear();
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "," + to_string(destination) + "," + to_string(timestamp);
        if (sets.find(key) != sets.end())  return 0;
        if (q.size() == lim) {
            forwardPacket();
        }

        sets.insert(key);
        q.push({source, destination, timestamp});
        maps[destination].push_back(timestamp);
        return 1;
    }

    vector<int> forwardPacket() {
        if (q.empty())   return {};
        vector<int> cur = q.front();
        q.pop();

        int dest = cur[1];
        maps[dest].erase(maps[dest].begin());
        string key = to_string(cur[0]) + "," + to_string(cur[1]) + "," + to_string(cur[2]);
        sets.erase(key);
        return cur;
    }

    int getCount(int destination, int startTime, int endTime) {
        return count_in_vector_range(maps, destination, startTime, endTime);
    }

private:
    int lim;
    queue<vector<int>> q;
    set<string> sets;
    map<int, vector<int>> maps;
};
