/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node * clone(Node* node, map <Node*, Node*> & nodes){
        // If the node is already present in our map, that means we have already created a deep copy of that node, and we simply return that deep copy.
        if(nodes.find(node) != nodes.end())
            return nodes[node];
        
        // We create a deep copy of the node. 
        
        // To do so we use new to declare a new node and make the val equal to val of the original node.
        Node * node_copy = new Node(node->val);
        nodes[node] = node_copy;
        
        // Next, we start adding all the neighbors of the original to the neighbor list of the newly created deep copy. 
        // We do so recursively. **
        
        for(auto neighbor : node->neighbors)
            node_copy->neighbors.push_back(clone(neighbor, nodes));
        
        // Return the newly created deep copy.
        return node_copy;
    }
    
    Node* cloneGraph(Node* node) {
        
        if(!node) return NULL;
        
        map <Node*, Node*> nodes;
        return clone(node, nodes);
    }
};

// ** If you follow this code with an example, you'll see each time we either encounter a node that's already been created (and is present in our map), then the first return statement will return the deep copy. Else it will create a deep copy of the node first, then return it. I watched Neetcode's video https://www.youtube.com/watch?v=mQeF6bN8hMk for clarity on the recursion.