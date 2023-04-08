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
    unordered_map<int, Node*> map;
Node* cloneGraph(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    Node* root = new Node(node->val, {});
    map[node->val] = root;
    for (Node* neighbor : node->neighbors) {
        if (map.find(neighbor->val) == map.end()) {
            root->neighbors.push_back(cloneGraph(neighbor));
        } else {
            root->neighbors.push_back(map[neighbor->val]);
        }
    }
    return root;
}

        
    
};
