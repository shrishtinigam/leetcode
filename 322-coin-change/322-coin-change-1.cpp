// Original Solution
// BFS Solution
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        // Base case:
        if(amount == 0)
            return 0;

        // Keep track of minimum number of levels it took to reach an amount x
        vector <int> arr (amount, -1);

        // Let the currently we have selected 0 coins.
        // At the start of BFS, we are at level 1. 
        // We keep track of search levels to know how many coins it took us to reach a particular correct answer (which is what the question requires).
        // As we are doing BFS, the first correct answer we reach will also be the shortest path, i.e, least number of coins.

        int curr = 0;
        int curr_level = 1;

        // BFS queue. It keeps track of an intermediate sum and its level.
        queue <pair<int,int>> bfs_queue;
        bfs_queue.push({curr, curr_level}); // Initialize with 0, 1
        bool flag = true; // This means that we haven't yet found the least number of coins for 'amount'

        while(flag){
            // For every coin i
            for(int i = 0; i < coins.size(); i++){
                // Ignore it if its greater than amount
                if(coins[i] > amount)
                    continue;
                // Update the arr with level of the new value
                // Push the new into the queue
                // The conditions prevent the same value from being pushed into the array twice
                if(curr + coins[i] - 1 < arr.size()){
                    if(arr[curr + coins[i] - 1] == -1){
                        arr[curr + coins[i] - 1] = curr_level;
                        bfs_queue.push({curr + coins[i], curr_level + 1});
                    }
                }
            }

            // If we found the level for amount x, set flag to false to break while loop
            if(arr[amount - 1] != -1)
                flag = false;

            // If we have not reached the end condition yet and the queue is empty, that means the answer does not exist, return -1
            if(bfs_queue.empty() and flag == true)
                return -1;

            // Continue BFS by popping the front value
            curr = bfs_queue.front().first;
            curr_level =  bfs_queue.front().second;
            bfs_queue.pop();
            
        }
        return arr[amount-1];
    }
};