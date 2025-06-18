class DetectSquares {
private:
    map<int, map<int, int>> points;
public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        if (this->points.find(point[0]) == this->points.end()) {
            map<int, int> m;
            m[point[1]] = 1;
            this->points[point[0]] = m;
            return;
        }
        if (this->points[point[0]].find(point[1]) == this->points[point[0]].end()) {
            this->points[point[0]][point[1]] = 1;
            return;
        }
        this->points[point[0]][point[1]]++;
        
    }
    
    int count(vector<int> point) {
        int count = 0;
        if (this->points.find(point[0]) == this->points.end()) {
            return 0;
        }
        int y2 = point[1];
        int x1 = point[0];
        for (map<int, int>::iterator it = this->points[point[0]].begin(); it != this->points[point[0]].end(); ++it) {
            int y1 = it->first;
            if (y1 == y2) {
                continue;
            }
            for (map<int, map<int, int>>::iterator it2 = this->points.begin(); it2 != this->points.end(); ++it2) {
                int x2 = it2->first;
                if (abs(x2-x1) != abs(y1-y2)) {
                    continue;
                }
                if (this->points[x2].find(y1) != this->points[x2].end() && this->points[x2].find(y2) != this->points[x2].end()) {
                    count += this->points[x2][y1] * this->points[x2][y2] * this->points[point[0]][y1];
                } 
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
