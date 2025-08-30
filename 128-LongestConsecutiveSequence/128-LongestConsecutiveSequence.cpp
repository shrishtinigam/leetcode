// Last updated: 8/30/2025, 8:19:59 PM
class Solution {
public:
// Cleaner O(n) solution
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> st;
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);
        int curr = 1, ans = 0;    
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i] - 1) == st.end()) {
                curr = 1;
                while (st.find(nums[i] + curr) != st.end())
                    curr++;
                ans = max (curr, ans);    
            }
        }
        return ans;
    }
    
};

/*  my old O(n) solution -

        if(nums.size() == 0)
            return 0;

        unordered_set<int> temp;

        for(int i = 0; i < nums.size(); i++)
            temp.insert(nums[i]);
        
        int cnt = 1, max_cnt = 1;

        for(int i = 0; i < nums.size(); i++){
            if(temp.find(nums[i]-1) == temp.end()){
                int n = nums[i] + 1;
                while(temp.find(n++) != temp.end())
                    cnt++;
                max_cnt = max(cnt, max_cnt);
                cnt = 1;
            }
        }
        
        return max_cnt;
    }*/


/*
O(NlogN)
        if(nums.size() == 0)
            return 0;

        set<int> temp;
        for(int i = 0; i < nums.size(); i++){
            temp.insert(nums[i]);
        }
        int prev = *temp.begin();
        int cnt = 1, max_cnt = 1;
        for(auto & i : temp){
            if(i == prev + 1){
                cnt++;  
                if(cnt > max_cnt)
                    max_cnt = cnt;
            }
            else
                cnt = 1;
            
            prev = i;
        }
        return max_cnt;
*/