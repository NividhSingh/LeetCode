class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            visited[i] = false;
            m[i] = {};
        }
        for (auto edge: edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            count++;
            queue<int> toVisit;
            toVisit.push(i);
            while(!toVisit.empty()) {
                for (auto node1: m[toVisit.front()]) {
                    if (!visited[node1]) {
                        visited[node1] = true;
                        toVisit.push(node1);
                    }
                }
                toVisit.pop();
            }
        }
        return count;
    }
};
