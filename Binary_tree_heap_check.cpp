Q)CHECK IF BINARY TREE IS A HEAP
HEAPS
ANS)TO CHECK PROPERTY IS EASY.. simply go and compare value with left,right,if both of them hold true, then check if i hold true. if one or both of them fails-then return false. if i fail-then return false. 
To check completeness of a tree:

method1) using bfs: think level wise:
Clearly if at some level-we get to see null first(if we insert blindly-null or non null-doesn’t matter) and later we get to see(at any level-same or below level)any non null node-then it is not complete.
Ofcourse we can later see null nodes-that is not an issue(for ex at last level-2 nodes existed and later all can be null).tc: o(n) and sc:o(max width of a level) for queue.

method2)using dfs:first we count the number of nodes(n). Clearly for 0 based array-heap, the size must be n-1 and all nodes should be placed without a gap. So simply try to place left child at 2i+1 and right at 2i+2. If any gap finally left or it exceeds n-1 size, then not a heap. tc:o(n),sc o(n)for array and o(H) for dfs.

method1)
class Solution {
  public:
    bool checkcomp(Node* root){
        bool seennull=false;
        queue<Node*>q; q.push(root);
        while(!q.empty()){
            if(!q.front()){
                seennull=true;
            }
            else{
                if(seennull){return false;}
                q.push(q.front()->left); q.push(q.front()->right);
            }
            q.pop();
        }
        return true;
    }
    bool checkprop(Node* root){
        if(!root){return true;}
        bool flag1=checkprop(root->left);
        if(!flag1){
            return false;
        }
        bool flag2=checkprop(root->right);
        if(!flag2){
            return false;
        }
        if(root->left && root->data<root->left->data){
            return false;
        }
        if(root->right && root->data<root->right->data){
            return false;
        }
        return true;
    }
    bool isHeap(Node* root) {
        if(!checkprop(root)){return false;}
        if(!checkcomp(root)){return false;}
        return true;
        
    }

method2)

class Solution {
  public:
    bool travel(vector<Node*>&arr,Node* root,int n,int idx){
        if(idx>=n){return false;}
        arr[idx]=root; bool flag1=true,flag2=true;
        if(root->left){
            flag1=travel(arr,root->left,n,2*idx+1);
        }
        if(root->right){
            flag2=travel(arr,root->right,n,2*idx+2);
        }
        if(!flag1|| !flag2){
            return false;
        }
        return true;
    }
    void bfs(Node* root,long long& n){
        if(!root){return;} bfs(root->left,n); bfs(root->right,n);
        n++; return;
    }
    bool checkcomp(Node* root){
        long long n=0;
        bfs(root,n);
        vector<Node*>arr(n,nullptr);
        if(!travel(arr,root,n,0)){return false;}
        for(int i=0;i<n;i++){
            if(!arr[i]){return false;}
        }
        return true;
    }
    bool checkprop(Node* root){
        if(!root){return true;}
        bool flag1=checkprop(root->left);
        if(!flag1){
            return false;
        }
        bool flag2=checkprop(root->right);
        if(!flag2){
            return false;
        }
        if(root->left && root->data<root->left->data){
            return false;
        }
        if(root->right && root->data<root->right->data){
            return false;
        }
        return true;
    }
    bool isHeap(Node* root) {
        if(!checkprop(root)){return false;}
        if(!checkcomp(root)){return false;}
        return true;
        
    }
};
};
