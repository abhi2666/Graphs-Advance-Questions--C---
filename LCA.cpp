BinaryTreeNode<int>* lca(BinaryTreeNode<int>*root, int p, int q){
    if(root == NULL || root->data == p || root->data == q) return root;

    // go to left and right in tree
    BinaryTreeNode<int>* left = lca(root->left, p, q);
    BinaryTreeNode<int>* right = lca(root->right, p, q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root; // means neither of them is null implies 
    /*that for current node we got p and q from left and right and
    the current node is the LCA of p and q
    */
    
}

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    // we will find the common ancestor for node1 and node2 
    // and then with node3 and CA of node1 and node2.
    BinaryTreeNode<int>* firstLca = lca(root, node1, node2);
    BinaryTreeNode<int>* finalLca = lca(lroot, firstLca->data, node3);
    return finalLca;
}