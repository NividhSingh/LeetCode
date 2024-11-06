class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; 
        int N = height.size();
        int j = N - 1;
        int volume = min(height[i], height[j]) * (j-i);
        while (i < j) {
            volume = max(volume, min(height[i], height[j]) * (j-i));
            if (height[i] < height[j]) {
                int current_height = height[i];
                while (i < N && height[i] <= current_height) {
                    i++;
                }
            }
            else if (height[j] <= height[i]) {
                int current_height = height[j];
                while (j >= 0 && height[j] <= current_height) {
                    j--;
                }
            }
        }
    return volume;
    }
};
