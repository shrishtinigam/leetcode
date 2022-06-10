class RandomizedSet {
public:
    RandomizedSet() {
    }
    unordered_map<int, int> hashmap; // 1st int is the number, 2nd int is the index in vector
    vector <int> arr;
    bool insert(int val) {
        if(hashmap.find(val) != hashmap.end())
            return false;
        arr.push_back(val);
        hashmap[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) 
    {
        if(hashmap.find(val) == hashmap.end())
            return false;
        int index = hashmap[val];
        arr[index] = arr[arr.size()-1];
        hashmap[arr[index]] = index; 
        arr.pop_back();
        hashmap.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */