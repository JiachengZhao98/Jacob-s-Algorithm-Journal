#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
    vector<int> times(n, 0);
    stack<pair<int, int>> st; // To store function ID and the start time
    int lastTime = 0;

    for (const auto& log : logs) {
        istringstream ss(log);
        string token;
        getline(ss, token, ':');
        int id = std::stoi(token);
        getline(ss, token, ':');
        string type = token;
        getline(ss, token, ':');
        int time = std::stoi(token);

        if (type == "start") {
            if (!st.empty()) {
                times[st.top().first] += time - lastTime;
            }
            st.push({id, time});
            lastTime = time;
        } else {
            auto& top = st.top();
            times[top.first] += time - lastTime + 1;
            st.pop();
            lastTime = time + 1;
        }
    }

    return times;
}

int main() {
    std::vector<std::string> logs = {
        "0:start:0", "2:start:4", "2:end:5", "1:start:7", "1:end:10", "0:end:11"
    };
    int n = 3;
    std::vector<int> result = exclusiveTime(n, logs);

    for (int time : result) {
        std::cout << time << " ";
    }

    return 0;
}
