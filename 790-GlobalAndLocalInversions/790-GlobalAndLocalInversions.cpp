// Last updated: 8/30/2025, 8:18:32 PM
class Solution{
    public:
// https://leetcode.com/problems/global-and-local-inversions/solutions/1143422/js-python-java-c-simple-3-line-solutions-w-explanation/?orderBy=most_votes

    /*bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); i++)
            if (i - A[i] > 1 || i - A[i] < -1) return false;
        return true;
    }*/

    bool isIdealPermutation(vector<int>& A) {
        int cmax = 0, n = A.size();
        for (int i = 0; i < n - 2; ++i) {
            cmax = max(cmax, A[i]);
            if (cmax > A[i + 2]) return false;
        }
        return true;
    }

/*
        bool isIdealPermutation(vector<int>& nums) {
            int max = -1;
            for(int i = 0; i < nums.size()-2; i++){
                max = std::max(nums[i], max);
                if(max > nums[i+2])
                    return false;
            }
            return true;
        }*/

};

/*class Solution {
public:
long long merge(vector<int>& arr,long long temp[],int left,int mid,int right)
{
    long long inv_count=0;
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long merge_Sort(vector<int>& arr,long long temp[],long long left,long long right)
{
    long long mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        long long temp[n];
        
        long long local = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] > nums[i])
                local++;
        }
        long long global = merge_Sort(nums,temp,0,n-1);
        cout << local << " " << global;
        if(local == global)
            return true;
        return false;
    }
};*/