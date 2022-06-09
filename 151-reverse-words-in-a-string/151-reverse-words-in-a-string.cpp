class Solution {
public:
    string reverseWords(string s) 
    {
        
        vector <string> arr;
        int i = 0, j = 0;
        string temp = "";
        while(i < s.length())
        {
        // Check for space and push in the array whenever space occured
           if(s[i] != ' ')
               temp += s[i];
            else if(temp != "")
            {
               arr.push_back(temp);
               temp = "";
            }
            i++;
        }
        // as we check till the s.length() so we miss the last word.
        // So push it outside the loop with the check that it's not a space
        
        if(temp != "")
            arr.push_back(temp);
        
        // Reverse the arr as we need to return the reversed string
        reverse(arr.begin(), arr.end());
        
        string ans = "";
        for(int i = 0; i < arr.size(); i++)
        {
            if(i!=arr.size()-1)
            {
                ans += arr[i];
                ans += " ";
            }
            else
                ans += arr[i];
        }
        return ans;
    }
};