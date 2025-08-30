// Last updated: 8/30/2025, 8:17:55 PM
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> even_nos;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] % 2 == 0)
                even_nos[nums[i]]++;
        
        int max_count = 0;
        int most_freq_even = -1;
        for(auto i : even_nos){
            if(i.second > max_count){
                max_count = i.second;
                most_freq_even = i.first;
            }
        }
        return most_freq_even;
    }
};