class Node{
    public:
    int key, value;
    Node *right, *left;
    
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};
class LRUCache {
private:
    Node *LRU, *MRU;
    int capacity, size;
    unordered_map<int, Node *> hashmap;
public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
        this->size = 0;
        this->LRU = NULL;
        this->MRU = NULL;
    }
    void remove(Node *p)
    {
        if(p->left != NULL)
            p->left->right = p->right;
        else
            LRU = p->right;
        
        if(p->right != NULL)
            p->right->left = p->left;
        else
            MRU = p -> left;
        
        p->left = NULL;
        p->right = NULL;
    }
    
    void insert(Node *q)
    {
        if (LRU == NULL)
            LRU = MRU = q;
        else
        {
            MRU->right = q;
            q->left = MRU;
            MRU = q;
        }
    }
    /*
    Logic for get function:
    -> if key not found return -1
    ->if found then return val
    */
    int get(int key) 
    {
        if (hashmap.find(key) == hashmap.end())
            return -1;
        Node *x = hashmap[key];
        remove(x);
        insert(x);
        //insert the node at last
        return x->value;
    }
    /*Logic for Put function:
    ->if key already present thenchange the value of the key insert it at last
    ->if key not present
        Case1:if size== capacity then first value removed in LRU Cache
        Case2:if size!=capacity value inserted at last  
    */
    void put(int key, int value) 
    {
        if(hashmap.find(key) != hashmap.end()) // if key is already present
        {
            hashmap[key]->value = value; // update value
            remove(hashmap[key]);
            insert(hashmap[key]);
        }
        else
        {
            Node * y = new Node(key, value);
            hashmap[key] = y;
            if(size == capacity)
            {
                hashmap.erase(LRU->key); //remove the least recently used value from map
                remove(LRU);
                insert(y);
            }
            else
            {
                size++;//size of window increase
                insert(y);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */