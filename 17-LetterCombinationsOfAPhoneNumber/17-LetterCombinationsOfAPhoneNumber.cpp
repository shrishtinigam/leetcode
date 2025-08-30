// Last updated: 8/30/2025, 8:21:20 PM
/*
How this code builds up the solution:

Digit - 1
x = 1
no. of letters = 3
a   
a b  
a b c 

Digit - 2
x = 3
no. of letters = 3
ad b c a b c a b c 
ad bd c a b c a b c 
ad bd cd a b c a b c 
ad bd cd ae b c a b c 
ad bd cd ae be c a b c 
ad bd cd ae be ce a b c 
ad bd cd ae be ce af b c 
ad bd cd ae be ce af bf c 
ad bd cd ae be ce af bf cf 

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Trivial Case
        if(digits.size() == 0)
            return {};
        // Hash map of the buttons
        unordered_map <char, string> buttons;
        buttons['2'] = "abc";
        buttons['3'] = "def";
        buttons['4'] = "ghi";
        buttons['5'] = "jkl";
        buttons['6'] = "mno";
        buttons['7'] = "pqrs";
        buttons['8'] = "tuv";
        buttons['9'] = "wxyz";
        
        // Initializing a vector of strings with a single empty string
        vector <string> result = {""};
        for(int i = 0; i < digits.size(); i++)
        {
            // If the new digit has k possible characters, then the numner of new combinations will be = existing combinations * k
            // So we will copy the existing result vector and insert the copied vector k - 1 times at the end. 
            
            // Like in first example "23",
            // a b c -> a b c a b c a b c
            // Now we can add d to first three, e to the next three and f to the last three.
            vector <string> v2 = result;
            for(int j = 0; j < buttons[digits[i]].size() - 1; j++)
                result.insert(result.end(), v2.begin(), v2.end());

            // x is the number of times each new character has to be added to a string.
            // Like in first example "23", d has to be added thrice
            // a b c -> ad bd cd a b c a b c
            // y is the shift, and it increases by x each iteration.
            int x = result.size() / buttons[digits[i]].size();
            int y = 0;
            for(int j = 0; j < buttons[digits[i]].size(); j++)
            {
                for(int k = 0; k < x; k++)
                    result[k + y] += buttons[digits[i]][j];
                y += x;
            }
        }
        return result;

    }
};