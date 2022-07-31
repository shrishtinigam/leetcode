/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
	// Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
        return buildTree(ss);
    }
    
private:
    TreeNode* buildTree(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "null")
			return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
            
        return node;
    }
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/* Code I wrote previously - its bad but goddamint i wrote it on my own */
/* 
class Codec {
public:
    
    vector<int> stringToArray(string s){
        vector<int>v;
        int i = 0;
        int x = 0;
        int d = 0;
        int n = 0;
        cout <<  "\n";
        while(i < s.size())
        {
            if(s[i] == 'N'){
                v.push_back(-1001);
                x = 0;
                d = 0;
            }
            else if(s[i] == ',' and s[i-1] != 'N'){
                if(n == 1){ 
                    v.push_back((x * -1));
                    n = 0;
                }
                else
                    v.push_back(x);
                x = 0;
                d = 0;
            }
            else if(s[i] == ',' and s[i-1] == 'N'){}
            else if(s[i] == '-')
                n = 1;
            else{
                if(x == 0){
                    x = int(s[i] - '0');
                    d++;
                }
                else
                    x = (x * pow(10, d)) + (int(s[i] - '0'));
            }
            i++;
        }
        return v;
    }
    // Encodes a tree to a single string.
    void Preorder(TreeNode* root, string * s){
        if(root == NULL){
            *s += "N,"; // any number that is not in possible list of values
            return;
        }

        string x = string(to_string(root->val));
        x += ",";
        *s += x;

        Preorder(root->left, s);
        Preorder(root->right, s);
    }
    
    string serialize(TreeNode* root) {
        string s;
        Preorder(root, &s);
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode * buildTree(vector<int> v, int * s){
        if(v[*s] == -1001){
            (*s)++;
            return NULL;
        }
        TreeNode * node = new TreeNode(v[*s]);
        (*s)++;
        node->left = buildTree(v, s);
        node->right = buildTree(v, s);
        return node;
    }
    
    TreeNode* deserialize(string data) {
        vector<int> v = stringToArray(data);
        int i = 0;
        TreeNode* result = buildTree(v, &i);
        return result;
    }
};

*/