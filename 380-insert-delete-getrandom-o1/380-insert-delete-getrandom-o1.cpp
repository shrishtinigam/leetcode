class RandomizedSet {
    unordered_map<int ,int> mpp;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end()) return false;
        nums.push_back(val);
        mpp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val) == mpp.end()) return false;
        int last = nums.back();
        nums[mpp[val]] = last;
        mpp[last] = mpp[val];
        nums.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

static int noio = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();