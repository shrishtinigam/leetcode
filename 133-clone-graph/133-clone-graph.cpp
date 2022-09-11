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
        if(nodes.find(node) != nodes.end())
            return nodes[node];
        
        Node * node_copy = new Node(node->val);
        nodes[node] = node_copy;
        for(auto neighbor : node->neighbors){
            node_copy->neighbors.push_back(clone(neighbor, nodes));
        }
        return node_copy;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        map <Node*, Node*> nodes;
        return clone(node, nodes);
    }
};