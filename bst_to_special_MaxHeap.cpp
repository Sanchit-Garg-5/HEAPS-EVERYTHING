https://www.geeksforgeeks.org/problems/bst-to-max-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions
inorder of bst is always sorted and if we fill an array with sorted elements-we get that special max heap.
But here we CAN'T USE ARRAY-rather have to return in the tree itself. Observe placing those sorted elements post-order wise works.
  tc-o(n) for both inorder and postorder traversals and sc-o(n) for storing the inorder

void inorder(Node* root, vector<int>&arr){
    if(!root){return;}
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
    return;
}
void postorder(Node* root, vector<int>arr,int& i){
    if(!root){return;}
    postorder(root->left,arr,i);
    postorder(root->right,arr,i);
    root->data=arr[i++]; 
    
    return;
}
class Solution {
  public:
    void convertToMaxHeap(Node* root) {
        vector<int>arr;
        inorder(root,arr); int i=0;
        postorder(root,arr,i); return;
    }
};
