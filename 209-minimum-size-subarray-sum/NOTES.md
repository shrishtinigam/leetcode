Sliding Window

The O(n) solution is to use two pointers: l and r. First we move r until we get a sum >= s, then we move l to the right until sum < s. In this process, store the minimum length between l and r. Since each element in nums will be visited by l and r for at most once. This algorithm is of O(n) time.