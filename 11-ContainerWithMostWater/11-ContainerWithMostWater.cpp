// Last updated: 8/30/2025, 8:21:25 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        // Brute Force
        /*int res = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i+1; j < height.size(); j++){
                int area = (j-i) * min(height[i], height[j]);
                res = max(res, area);
            }
        }
        return res;*/

        int res = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            int area = (j-i) * min(height[i], height[j]);
            res = max(res, area);
            if(height[i] >= height[j]){
                j--;
            }else{
                i++;
            }
        }
        return res;
    }
};