class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int balls = grid[0].size();
        int flag = 0;
        vector <int> answers;
        //cout << grid.size();
        //cout << "\n";
        for(int j1 = 0; j1 < balls; j1++){
            int i = 0;
            int j = j1;
            int dirn = 0;
            while(true){
                //cout << i;
                if(i >= grid.size()){
                    answers.push_back(j);
                    break;
                } 
                if(j == 0 and grid[i][j] == -1){
                    answers.push_back(-1);
                    break;
                }
                if(j == balls-1 and grid[i][j] == 1){
                    answers.push_back(-1);
                    break;
                }
                if(j < balls and grid[i][j] == 1 and grid[i][j] != grid[i][j+1]){
                    answers.push_back(-1);
                    break;
                }
                if(j > 0 and grid[i][j] == -1 and grid[i][j] != grid[i][j-1]){
                    answers.push_back(-1);
                    break;
                }
                
                if(grid[i][j] == 1){
                    j++;
                }
                if(grid[i][j] == -1){
                    j--;
                }
                i++;
            }
        }
        return answers;
    }
};