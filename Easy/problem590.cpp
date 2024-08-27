class Solution {
public:
    // Vector to store the result of the postorder traversal
    vector<int> ans;

    // Main function to perform postorder traversal
    vector<int> postorder(Node* root) {
        traversal(root); // Start the traversal from the root node
        return ans;      // Return the resulting vector after traversal
    }

    // Helper function to recursively traverse the tree in postorder
    void traversal(Node* root) {
        if (!root)       // Base case: If the current node is null, return immediately
            return;

        // Get the list of children nodes for the current node
        vector<Node*> children = root->children;

        // Recursively perform postorder traversal for each child
        for (auto k : children)
            traversal(k);

        // After traversing all children, add the current node's value to the result
        ans.push_back(root->val);
    }
};
