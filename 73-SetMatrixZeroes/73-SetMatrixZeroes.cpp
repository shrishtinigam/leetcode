// Last updated: 8/30/2025, 8:20:34 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> is;
        set<int> js;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    is.insert(i);
                    js.insert(j);
                }
            }
        }

        for (auto i : is) {
            //int i = (int) ik;
            //cout << i;
            for(int k = 0; k < matrix[0].size(); k++){
                matrix[i][k] = 0;
            }  
        }

        for (auto j : js) {
            //int j = (int) jk;
            //cout << j;
            for(int k = 0; k < matrix.size(); k++){
                matrix[k][j] = 0;
            }
        }


    }
};