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
    Node *head, *tail;
    int capacity, size;
    unordered_map<int, Node *> m;
public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    void remove(Node *p)
    {
        if(p->left != NULL)
            p->left->right = p->right;
        else
            head = p->right;
        
        if(p->right != NULL)
            p->right->left = p->left;
        else
            tail = p -> left;
        
        p->left = NULL;
        p->right = NULL;
    }
    
    void insert(Node *q)
    {
        if (head == NULL)
            head = tail = q;
        else
        {
            tail->right = q;
            q->left = tail;
            tail = q;
        }
    }
    /*
    Logic for get function:
    -> if key not found return -1
    ->if found then return val
    */
    int get(int key) 
    {
        if (m.find(key) == m.end())
            return -1;
        Node *x = m[key];
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
        Node *y = new Node(key,value);
        if(m.find(key)!=m.end())
        {
            m[key]->value = value;
            remove(m[key]);
            insert(m[key]);
        }
        else
        {
            m[key] = y;
            if(size == capacity)
            {
                m.erase(head->key);//remove the least recently used value from map
                remove(head);
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