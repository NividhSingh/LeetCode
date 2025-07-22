class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto compare = [](const pair<double, vector<int>>& a, const pair<double, vector<int>>& b) {
            return a.first > b.first; // This will create a max-heap, reverse logic for a min-heap
        };

        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, decltype(compare)> a(compare);
        for (int i = 0; i < points.size(); i++) {
            a.push({points[i][0]*points[i][0]+points[i][1]*points[i][1], points[i]});
            // a.push({points[i][0]*points[i][0]*+points[i][1]*points[i][1], points[0], points[1]});
        }
        vector<vector<int>> b(k);
        for (int i = 0; i < k; i++) {
            b[i] = a.top().second;
            a.pop();
        }
        return b;
    }
};
