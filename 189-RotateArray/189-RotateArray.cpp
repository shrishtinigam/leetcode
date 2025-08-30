// Last updated: 8/30/2025, 8:19:36 PM
class Solution {
public:
    void reverse(vector<int> &num,int low,int high)
    {
        while(low<high)
        {
            swap(num[low],num[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }

};
    /*void print(vector<int>x)
    {
        for(int i : x)
            cout << i << " ";
        cout << "\n";
    }*/
/*
 void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            nums[(i+k)%nums.size()] = temp[i];
    }
*/
// std::rotate(vec1.begin(), vec1.begin()+vec1.size()-k, vec1.end());