class Solution {
public:
    bool findPath(map<string, vector<string>>& m, map<string, vector<bool>>& mUsed, vector<string>& path, string startingAirport, int flightsUsed, int flightsTotal) {
        if (flightsUsed == flightsTotal) {
            path[flightsUsed] = startingAirport;
            return true;
        }
        for (int i = 0; i < m[startingAirport].size(); i++) {
            if (mUsed[startingAirport][i]) {
                continue;
            }
            mUsed[startingAirport][i] = true;
            if (findPath(m, mUsed, path, m[startingAirport][i], flightsUsed + 1, flightsTotal)) {
                path[flightsUsed] = startingAirport;
                return true;
            }


            mUsed[startingAirport][i] = false;
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> m;
        map<string, vector<bool>> mUsed;
        for (auto ticket: tickets) {
            if (m.find(ticket[0]) == m.end()) {
                m[ticket[0]] = {ticket[1]};
                mUsed[ticket[0]] = {false};
            }
            else {
                m[ticket[0]].push_back(ticket[1]);
                mUsed[ticket[0]].push_back(false);
            }
        }
        for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            sort(m[it->first].begin(), m[it->first].end());
        }

        vector<string> path(tickets.size() + 1);

        findPath(m, mUsed, path, "JFK", 0, tickets.size());
        return path;

// bool findPath(map<string, vector<string>>& m, map<string, vector<bool>>& mUsed, vector<string> path, string startingAirport, int flightsUsed, int flightsTotal) {

    }
};
