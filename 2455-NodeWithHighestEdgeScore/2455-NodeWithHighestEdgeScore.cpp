// Last updated: 8/30/2025, 8:17:57 PM
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<long,long> map;
        for(long i = 0; i < edges.size(); i++){
            map[edges[i]] += i;
        }
        long max_val = 0;
        long min_key = 1000000;
        for (auto i : map)
        {
            if(i.second > max_val){
                max_val = i.second;
                min_key = i.first;
            }else if(i.second == max_val and i.first < min_key){
                max_val = i.second;
                min_key = i.first;
            }
        }
        return (int) min_key;
    }
};