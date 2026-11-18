#include <bits/stdc++.h>
using namespace std;
// --- Companion macros required for this debugger ---
typedef long long ll;
#define f first
#define s second
// --- Master Debugger Block ---
// Debug Overloads
#ifdef SanG_05
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class... Args> void _print(unordered_set <Args...> v);
template <class... Args> void _print(unordered_multiset <Args...> v);
template <class... Args> void _print(unordered_map <Args...> v);
template <class... Args> void _print(unordered_multimap <Args...> v);
template <class... Args> void _print(list <Args...> v);
template <class... Args> void _print(forward_list <Args...> v);
template <class... Args> void _print(stack <Args...> v);
template <class... Args> void _print(queue <Args...> v);
template <class... Args> void _print(priority_queue <Args...> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_set <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multiset <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_map <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(unordered_multimap <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(forward_list <Args...> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class... Args> void _print(stack <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class... Args> void _print(priority_queue <Args...> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}

class maxheap{
    private: int *arr; int curr_size,total_size;
    public: //curr_size is where my next element is inserted. 0 based array implementation
    maxheap(int total):total_size(total),curr_size(0) {arr=new int[total];}
    void insert(int x){ //insertion at curr_size
        //tc is o(logn) per single insertion and uses heapify up
        //for top-down construction-since we do it n times,tc is o(nlogn)-uses heapify up
        if(curr_size>=total_size){cout<<"overlfow already";return;} 
        arr[curr_size]=x; curr_size++;
        heapifyup(curr_size-1);
    } 
    void heapifyup(int index){ //per operation takes only o(logn)-used for insertion and top-down construction of heap from unsorted array
        if(index<=0){return;} //if parent don't exist
        int parent=(index-1)/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            heapifyup(parent);
        }
        else{return;}
    }
    void extract_max(){
        //is the same as delting top guy
        //tc is o(logn),involves heapifydown
        if(curr_size<=0){cout<<"underflow already"; return;}
        arr[0]=arr[curr_size-1];
        curr_size--;
        heapifydown(0);
    }
    void heapifydown(int index){
        //tc is o(logn)per operation
        //used for deleting/extract_max, bottom-up heap construction(takes o(n) tc rather than o(nlogn)) and to heapsort(o(nlogn))
        if(index>=curr_size){return;} //if myself at index dont exist yet as a new element gets inserted at curr_size
        if(2*index+1>=curr_size && 2*index+2>=curr_size){return;}//when both children don't exist, nothing to comapre with
        int big_idx,big_val=INT_MIN,left=2*index+1,right=2*index+2;
        if(left<curr_size && left>=0){
            if(arr[left]>=big_val){big_val=arr[left]; big_idx=left;}
        }
        if(right<curr_size && right>=0){
            if(arr[right]>=big_val){big_val=arr[right]; big_idx=right;}
        }
        if(arr[index]<big_val){
            swap(arr[index],arr[big_idx]); heapifydown(big_idx);
        }
    }
    void build_heapifydown(int* arr){ //Building  a heap from heapify down-requires that at i index- the left and right subtree are already valid heaps. so we begin iterating from backwards.
        //and even in that skip iterating over leaf nodes-as they can't be heapified down any further
        for(int i=(curr_size/2)-1;i>=0;i--){
            heapifydown(i);
        }
    }
    void build_heapifyup(int* arr){ //Building  a heap from heapify up-requires that i index- ancestor chain is valid heap on its own-else element moving up will end up comparing itself
        //with non valid guys. so iterate from 0 to back.
        //-ensure every node is worked upon-as any element can move upwards to any valid place
        for(int i=0;i<curr_size;i++){
            heapifyup(i);
        }
    }
    void heapsort(){
        int active_size=curr_size;
        curr_size--; //before this line-curr_size was waiting to insert a new element at its location
        for(int i=0;i<active_size-1;i++){ //we do it active_size-1 time, can also do it active_size times.
            swap(arr[0],arr[curr_size]);  
            curr_size--; //important to shrink boundary of current active heap
            heapifydown(0);
        }
        //now it is sorted
        curr_size=active_size;
        //set curr_size back to usual, so printheap etc function work fine
    }
    void printheap(){
        for(int i=0;i<curr_size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    ~ maxheap(){
        delete []arr; arr=nullptr;
    }

};
int main(){
    int n; cin>>n; int unsort_arr[n];
    for(int i=0;i<n;i++){
        cin>>unsort_arr[i]; 
    }
    maxheap obj(n);
    obj.build_heapifydown(arr); 
    //builds heap using hepaify down-total tc is o(n)
    obj.build_heapifyup(arr);
    //builds heap using hepaify up-total tc is o(nlogn)
}  
