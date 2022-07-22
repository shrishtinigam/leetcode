class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& newInterval) 
    {
        
        auto it = lower_bound(I.begin(), I.end(), newInterval);
        int pos = it - I.begin();
        
        I.insert(it, newInterval);
        
        if(I.size() == 0)
            return I;
        
        int start = (pos <= 0) ? 0 : pos - 1;
        int R = start;
        
        for(int j = start; j < I.size(); j++)
        {
            vector <int> i = I[j];
            if(i[0] <= I[R][1])                  
                I[R][1] = max(I[R][1], i[1]);
            else
                I[++R] = i; 
        }
        
        I.resize(R+1); 
        return I;
    }
};

/* OLD SOLUTION
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& newInterval) {
        auto it = lower_bound(I.begin(), I.end(), newInterval);
        I.insert(it, newInterval);
        int R = 0; 
        for(auto i : I)
            if(i[0] <= I[R][1])                  
                I[R][1] = max(I[R][1], i[1]);
            else
                I[++R] = i; 
        I.resize(R+1); 
        return I;
        
        for
    }
};
*/