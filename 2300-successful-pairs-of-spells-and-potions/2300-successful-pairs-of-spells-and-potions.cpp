class Solution {
public:
    int binarySearch(vector<int>& arr, int num) {
        int p = 0;
        int r = arr.size() - 1;
        while (p <= r) {
            int mid = (p + r)/2;
            
            if (arr[mid] == num) return mid;
            else if (arr[mid] > num) r = mid-1;
            else  p = mid+1;
        }
        return -1;
    }
    // Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> spellscopy = spells;
        sort(potions.begin(), potions.end(), greater <>());
        sort(spells.begin(), spells.end());
        vector <int> result;
        int x = 0;
        int index = 0;
        for(int i = 0; i < spells.size(); i++)
        {
            for(int j = index; j < potions.size(); j++)
            {
                long long m = (long(spells[i])) * (long(potions[j]));
                if(m >= success)
                {
                    x++;
                    index++;
                }
                else
                    break;
            }
            result.push_back(x);
        }
        vector <int> result2;
        int it;
        for(int i = 0; i < result.size(); i++)
        {
            it = binarySearch(spells, spellscopy[i]);
            result2.push_back(result[it]);
        }
        return result2;
    }
};