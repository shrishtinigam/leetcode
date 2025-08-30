// Last updated: 8/30/2025, 8:18:50 PM
class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i = nums2.size()-1; i >= 0; i--)
        {
            if(st.empty())
            {
                st.push(nums2[i]);
                mp[nums2[i]]=-1;
            }
            else
            {
                while(!st.empty() and st.top() <= nums2[i])
                    st.pop();
                if(!st.empty())
                    mp[nums2[i]]=st.top();
                else 
                    mp[nums2[i]]=-1;
                st.push(nums2[i]); 
            }
        }
        vector <int> ans;
        for(auto it : nums1)
            ans.push_back(mp[it]);
        return ans;
    }
};


/*
---
//since there are no duplicates, we can store them in a map;
        
        vector<int> res(nums1.size(), -1); //to be returned, initialize it with -1.
        stack<int> st;
        unordered_map<int, int> umap;
        
        for(int i=0; i<nums2.size(); i++)
        {
            int element = nums2[i];
            
            while(!st.empty() && element > st.top())
            {
                //NGE of st.top() is element
				
                umap[st.top()] = element;
                st.pop();
            }
            
            st.push(element);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            int ele = nums1[i];
            
            if(umap.find(ele) != umap.end())
            {
                int nge = umap[ele];
                res[i] = nge; //push NGE of desired element
            }
                
        }
        
        return res;
---
vector <int> nums1sorted = sort(nums1.begin(), nums1.end());
        stack <int> stack;
        vector <int> nextGreatest(nums2.size(), -1);
        for(int i = nums2.size(); i >= 0; i--){
            while(!stack.empty() and stack.top() <= nums2[i])
                stack.pop();
            if(!stack.empty())
                nextGreatest[i] = stack.top();
            stack.push(nums[i]);
        }

 int x;
        vector <int> table = Nearest_Greater_Right(nums2);
        vector_print(table);
        vector <int> result(nums1.size(),0);
        vector_print(result);        
        vector_print(nums1);        
        vector_print(nums2);

        int j = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            cout << nums1[i] << " ";
            x = BinarySearch(nums2, nums1[i]);
            cout << x <<"\n";
            //result[j] = table[x];
            j++;
        }
        return result;

int BinarySearch(vector<int>arr , int x)
    {
        int l = 0, r = arr.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2; // to prevent overflow
            if(arr[mid] == x)
                return mid;
            else if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        } 
        return -1; 
    }
    vector <int> Nearest_Greater_Right(vector <int> v)
    {
        vector <int> ans(0);
        stack <int> s;

        for(int i = 0; i < v.size(); i++)
        {
            while(!s.empty())
            {
                if(s.top() > v[v.size() - i - 1])
                {
                    ans.push_back(s.top());
                    break;
                }
                s.pop();
            }
            s.push(v[v.size() - i - 1]);
            if(ans.size() == i)
                ans.push_back(-1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void vector_print(vector<int> ans)
    {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
*/