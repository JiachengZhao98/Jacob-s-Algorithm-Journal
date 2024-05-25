#include "iostream"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "vector"
#include "queue"
#include "mutex"
#include "condition_variable"
#include "thread"

using namespace std;
// intern OA

int maxdiff(vector<vector<int>>& nodes) {
    std::unordered_map<int, vector<int>> mp;
    int maxnode = 0;
    for (auto node : nodes) {
        mp[node[0]].push_back(node[1]);
        mp[node[1]].push_back(node[0]);
        maxnode = max(maxnode, max(node[0], node[1]));
    }
    // suppose the first node is 1, not 0
    vector<bool> visited(maxnode + 1, false);
    int res = 0;
    for (int i = 1; i <= maxnode; i++) {
        if (visited[i]) continue;
        queue<int> que;
        visited[i] = true;
        int min_node = i, max_node = i;
        for (auto a : mp[i]) {
            min_node = min(a, min_node);
            max_node = max(a, max_node);
            que.push(a);
            visited[a] = true;
        }

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int cur = que.front(); que.pop();
                for (auto num : mp[cur]) {
                    if (visited[num] == false) {
                        min_node = min(num, min_node);
                        max_node = max(num, max_node);
                        visited[num] = true;
                        que.push(num);
                    }
                }
            }
        }
        res = max(res, (max_node - min_node));
    }
    return res;
}

class getMostCommon {

private:

    std::unordered_map<int, int> num_times;
    std::map<int, unordered_set<int>> times_num;
    std::queue<int> q;
    int cap;

public:
    getMostCommon(int capacity) {
        this->cap = capacity;
    }


    void add(int num) {
        if (q.size() >= cap) {
            int removed_num = q.front(); q.pop();
            int removed_times = num_times[removed_num];
            num_times[removed_num]--;
            times_num[removed_times].erase(removed_num);
            times_num[num_times[removed_num]].insert(removed_num);
        }

        q.push(num);
        int times = num_times[num];
        num_times[num]++;
        if (times_num.find(times) != times_num.end()) {
            times_num[times].erase(num);
        }
        times_num[num_times[num]].insert(num);
    }

    int get() {
        return *times_num.rbegin()->second.begin();
    }
};

struct LinkedList {
    int val;
    LinkedList* next;
    LinkedList* triple_next;
    LinkedList(): val(0), next(nullptr), triple_next(nullptr) {}
    LinkedList(int x): val(x), next(nullptr), triple_next(nullptr) {}
    LinkedList(int x, LinkedList* ptr): val(x), next(ptr), triple_next(nullptr) {}
};

class tripleNextNode {

    LinkedList* root;
    int capacity;
    LinkedList* tail;

public:
    tripleNextNode(LinkedList* node) {
        root = node;
        capacity = 1;
        tail = root;
    }

    // suppose the value of each node is distinct
    void addNode(int value) {
        LinkedList* node = new LinkedList(value);
        int tailVal = tail->val;
        tail->next = node;
        tail = tail->next;
        capacity++;
        if (capacity > 3) {
            LinkedList* dummyroot = root;
            if (capacity == 4) dummyroot->triple_next = tail;
            else {
                while (dummyroot->triple_next->val != tailVal) {
                    dummyroot = dummyroot->next;
                }
                dummyroot = dummyroot->next;
                dummyroot->triple_next = node;
            }
        }
    }

    void deleteNode(int value) {
        if (capacity == 1) return;
        if (capacity <= 3) {
            LinkedList* dummyroot = root;
            while (dummyroot->next->val != value) {
                dummyroot = dummyroot->next;
            }
            dummyroot->next = dummyroot->next->next;
            if (tail->val == value) {
                tail = dummyroot;
            }
            capacity--;
            return;
        }
        queue<LinkedList*> q;
        LinkedList* dummyroot = root;
        q.push(dummyroot);
        while (dummyroot->next->val != value) {
            dummyroot = dummyroot->next;
            q.push(dummyroot);
            if (q.size() > 3) q.pop();
        }
        LinkedList* removeNode = dummyroot->next;
        dummyroot->next = dummyroot->next->next;
        if (tail->val == value) tail = dummyroot;
        if (q.size() > 0) {
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                if (cur->triple_next != nullptr) {
                    cur->triple_next = cur->triple_next->next;
                }
            }
        }
        capacity--;
    }
};

    std::vector<std::string> getMutationString(std::string str) {
        std::vector<std::string> res;
        size_t size = str.size();
        for (int i = 0; i <= size; ++i) {
            if (i == 0) {
                res.push_back(str); continue;
            }
            if (i == size) {
                res.push_back(to_string(size)); continue;
            }
            string num = to_string(i);
            for (int j = 0; j < size - i + 1; j++) {
                string cur = str.substr(0, j) + num + str.substr(j + i, size);
                res.push_back(cur);
            }
        }
        return res;
    }

    std::vector<std::vector<int>> numOccursMostInIntervals(std::vector<std::vector<int>> intervals) {
        std::vector<std::vector<int>> res;
        std::map<int, int> entry_exit;
        for (auto a : intervals) {
            if (a[0] == a[1]) {
                entry_exit[a[0]] += 2;
                continue;
            }
            entry_exit[a[0]]++;
            entry_exit[a[1]]--;
        }
        int count = 0, max_count = 0;
        std::unordered_map<int, int> rec;
        for (auto a : entry_exit) {
            count += a.second;
            rec[a.first] = count;
            max_count = max(max_count, count);
        }
        for (auto a = rec.begin(); a != rec.end(); ++a) {
            if (a->second == max_count) {
                if (a->second - prev(a)->second == 1) {
                    res.push_back({a->first, next(a)->first});
                }
                else {
                    res.push_back({a->first, a->first});
                }
            }
        }
        return res;
    }

#include <vector>
#include <random>
#include <iostream>

class SegmentTree {
    std::vector<int> tree;
    int n;
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;

public:
    SegmentTree(const std::vector<int>& weights) {
        n = weights.size();
        tree.resize(4 * n);
        build(weights, 0, 0, n - 1);
        gen = std::mt19937(std::random_device{}());
        dist = std::uniform_int_distribution<>(1, tree[0]);  // The root node holds the total sum
    }

    void build(const std::vector<int>& weights, int node, int start, int end) {
        if (start == end) {
            tree[node] = weights[start];
        } else {
            int mid = (start + end) / 2;
            build(weights, 2 * node + 1, start, mid);
            build(weights, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int pickIndex() {
        int randWeight = dist(gen);
        return query(0, 0, n - 1, randWeight);
    }

    int query(int node, int start, int end, int weight) {
        if (start == end) {
            return start;
        }
        int mid = (start + end) / 2;
        if (weight <= tree[2 * node + 1]) {
            return query(2 * node + 1, start, mid, weight);
        } else {
            return query(2 * node + 2, mid + 1, end, weight - tree[2 * node + 1]);
        }
    }
};

int main() {
    std::vector<int> weights = {1, 3, 4, 6};
    SegmentTree obj(weights);
    std::cout << "Picked index: " << obj.pickIndex() << std::endl;
}



int main() {

    vector<vector<int>> res = {{1,9}, {2,8}, {3,7}, {4,6}, {5,5}};
    vector<vector<int>> vec = numOccursMostInIntervals(res);
    //if (vec.size() == 0) cout<<1;
    for (auto a : vec) {
        cout<<a[0]<<" "<<a[1];
        cout<<endl;
    }

    // string str = "collegestation";
    // vector<string> vec = getMutationString(str);
    // for (auto a : vec) {
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    // vector<vector<int>> nodes = {{5,5}, {1,2}, {1,3}, {2,3}, {2,4}, {3,4}, {4,5}};
    // int res = maxdiff(nodes);
    // cout<<res<<endl;

    // getMostCommon g(3);
    // vector<int> vec;
    // g.add(1); vec.push_back(g.get());
    // g.add(2); vec.push_back(g.get());
    // g.add(2); vec.push_back(g.get());
    // g.add(3); vec.push_back(g.get());
    // g.add(3); vec.push_back(g.get());

    // for (auto a : vec) {
    //     std::cout<<a<<std::endl;
    // }

    // buffer buf(5);
    // std::vector<std::thread> readers;
    // std::vector<std::thread> writers;

    // for (int i = 0; i < 10; ++i) {
    //     writers.emplace_back(write, ref(buf), i);
    // }

    // for (int i = 0; i < 10; ++i) {
    //     readers.emplace_back(read, ref(buf));
    // }

    // for (auto& a : writers) {
    //     a.join();
    // }

    // for (auto& a : readers) {
    //     a.join();
    // }

    // std::thread write_thread(write, ref(buf), 10);
    // std::thread read_thread(read, ref(buf), 10);

    // write_thread.join();
    // read_thread.join();

    // LinkedList* node = new LinkedList();
    // tripleNextNode listNode(node);
    // listNode.addNode(1);
    // listNode.addNode(2);
    // listNode.addNode(3);
    // listNode.addNode(4);
    // listNode.addNode(5);
    // listNode.addNode(6);
    // listNode.addNode(7);
    // listNode.addNode(8);

    // listNode.deleteNode(6);

    // while (node->triple_next != nullptr) {
    //     std::cout<<node->val<<" "<<node->triple_next->val<<std::endl;
    //     node = node->next;
    // }

    return 0;
}
