// Last updated: 8/30/2025, 8:18:47 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        if(arr.size() == 1)
            return arr[0];
        int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l)/2; // to prevent overflow
        if(mid == 0 && arr[mid + 1] != arr[mid])
            return arr[mid];
        if(mid == arr.size() - 1 && arr[mid - 1] != arr[mid])
            return arr[mid];
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];
        if((r - l) % 4 != 0)
        {
            if (arr[mid] == arr[mid + 1])
                r = mid - 1;
            else
                l = mid + 1;
        }        
        else
        {
            if (arr[mid] == arr[mid + 1])
                l = mid + 2;
            else
                r = mid - 2;
        }
    } 
    return -1; 
    }
};

/*class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> times;
        for(auto num : nums) times[num]++;
        
        for(auto num : times) if(num.second == 1) return num.first;
        return -1;
    }
};*/