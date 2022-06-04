class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& I) 
     {
        sort(begin(I), end(I));
        int R = 0; 
        for(auto i : I)
            if(i[0] <= I[R][1])                  
                I[R][1] = max(I[R][1], i[1]);
            else
                I[++R] = i; 
        I.resize(R+1); 
        return I;
    }
};
/*
With Comments

class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& I) 
     {
        sort(begin(I), end(I));
        int R = 0; // Rth index, Index of the interval we will compare all new intervals with. 
         
         // If Rth and ith interval are "mergeable", we merge them into the Rth interval, other wise we will increase R and make the newest "unmergable" interval the Rth interval.
         
        for(auto i : I)
            if(i[0] <= I[R][1]) // If the end time of Rth interval is   greater than or equal to start time of the i th interval                   
                I[R][1] = max(I[R][1], i[1]); // Merge Intervals
            else
                I[++R] = i; // Increase R and replace the next interval with the i th interval. In the next iterations we will compare the new intervals to this interval
        I.resize(R+1); // Delete all intervals after the Rth interval
        return I;
    }
};
*/