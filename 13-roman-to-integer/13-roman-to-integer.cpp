class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map <char, int> roman_numeral;
        
        roman_numeral['I'] = 1;
        roman_numeral['V'] = 5;
        roman_numeral['X'] = 10;
        roman_numeral['L'] = 50;
        roman_numeral['C'] = 100;
        roman_numeral['D'] = 500;
        roman_numeral['M'] = 1000;
        
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(roman_numeral[s[i]] < roman_numeral[s[i + 1]])
            {
                sum -= roman_numeral[s[i]];
                continue;
            }
            sum += roman_numeral[s[i]];
        }
        
        return sum;
    }
};