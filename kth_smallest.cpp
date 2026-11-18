/*
q)https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
Heaps
ans)method1:
Maintain a min priority queue over all n elements and then start removing the top turn by turn. So the element removed at kth turn is clearly the kth smallest element.
Tc- o(n)+(klogn), sc-o(n)
Explanation of tc: to construct priority queue(using heapifydown-once all over elements)-it takes o(n) not o(nlogn) and then removing k elements demand heapifydown k times-so o(klogn) extra.

Method2)(preferred heap method)
Maintain a max heap of size k. Whenever size exceeds k, remove top. Clearly this will end up removing the top(hence max elements). So all elements greater than the kth smallest element will get removed once a time. So at last-we left with only smaller elements than those (n-k) bigger elements. And at top will be the kth smallest element. Dry run on some random unsorted arr.
tc -o(k)+(n-k)logk. sc:o(k)
Explanation- constructing pq of size k takes o(K) and then for remaining elements we add and remove so 2*(n-k)logk.
Method3: quickselect(best average tc among these methods). 
Instead of quicksort-which sorts entire array in o(nlogn), why dont we use the foundational property of quicksort- which was that it always placed the chosen pivot at its correct place(all smaller and equal on its left and larger on right) and returned the correct index where the element was placed and we then used this index as the new pivot. Since the kth smallest element will be at (k-1 index for 0 based array)-we will repeat the process on the returned index accordingly- if index==k-1, stop. If index<k-1, then we need to go to right half only and so on. Tc is O(n)-average case and worst case is O(n^2) always(because of bad pivot selection in a given sorted input)(choosing random pivot-theoretically still has o(n^2) worst case)). Why average case of quick select is o(n) and not O(nlogn)? In quick sort-we ran recursion logn times and each time did n work. In quickselect-we run logn time only-but work decreases as n,n/2,n/4… so o(n).
Method4:(not practical always)
some other sorting method-fastest choices if range of elements is small would be COUNTING AND RADIX sort.
*/
method2
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>pq(arr.begin(),arr.begin()+k);
        int n=arr.size(); 
        for(int i=k;i<n;i++){
            pq.push(arr[i]);
            while(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
method1
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        for(int i=0;i<k;i++){
            int x=pq.top();
            pq.pop();
            if(i==k-1){return x;}
        }
    }
};
method3
class Solution {
  public:
     int placer(vector<int>&given, int left, int right, int num){ 
         int n=given.size();
         int i=left, j=left;
         while(j<=right && j<n){
             if(given[j]<num){swap(given[i],given[j]); i++; j++;}
             else{j++;}
         }
         return i;
     }
    int quickselect(vector<int> &arr, int left,int right,int k){
        if(left>=right){return arr[k-1];}
        int num=arr[right];
        int pivot=placer(arr,left,right-1,num);
        swap(arr[pivot], arr[right]);
        if(pivot==k-1){return arr[k-1];}
        if(pivot>k-1){return quickselect(arr,left,pivot-1,k);}
        if(pivot<k-1){return quickselect(arr,pivot+1,right,k);}
    }
    int kthSmallest(vector<int> &arr, int k) {
        int n=arr.size();
        return quickselect(arr,0,n-1,k);

    }
};
