// Last updated: 8/30/2025, 8:18:18 PM
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int balls = grid[0].size();
        vector <int> answers;
        for(int j1 = 0; j1 < balls; j1++){
            int i = 0;
            int j = j1;
            while(true){
                if(i >= grid.size()){
                    answers.push_back(j);
                    break;
                } 
                if(j == 0 and grid[i][j] == - 1){ // STUCK ON LEFT COLUMN
                    answers.push_back(-1);
                    break;
                }
                if(j == balls-1 and grid[i][j] == 1){ // STUCK ON RIGHT COLUMN
                    answers.push_back(-1);
                    break;
                }
                if(j < balls and grid[i][j] == 1 and grid[i][j] != grid[i][j+1]){ // STUCK IN THE MIDDLE
                    answers.push_back(-1);
                    break;
                }
                if(j > 0 and grid[i][j] == -1 and grid[i][j] != grid[i][j-1]){ // STUCK IN THE MIDDLE
                    answers.push_back(-1);
                    break;
                }
                
                if(grid[i][j] == 1)
                    j++;
                
                if(grid[i][j] == -1)
                    j--;
                
                i++;
            }
        }
        return answers;
    }
};