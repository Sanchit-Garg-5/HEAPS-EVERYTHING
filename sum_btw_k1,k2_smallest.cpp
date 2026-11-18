
q)https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1
Heaps
ans)simply we maintain 1 heaps of size k2(k1<k2).finally after processing, we get in pq2- all elements which are less than or equal to the k2th smallest element.
In [2,2,5] they treat 2 as 1st smallest and 2 as 2nd smallest and 5 as 3rd smallest. So elements greater than 1st smallest mean 1- 2 and 1- 5.
So keep removing elements from pq2, till size ==k1 and dont add the very top of pq2 to sum.Tc is +(n-k2)(logk2)+(k1logk2)+o(k2) So approx (n-k2)(logk2).

  
class Solution {
  public:
    long long sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        if(k1>k2){
            int temp=k1;
            k1=k2;
            k2=temp;
        } int n=arr.size();
        priority_queue<int>pq2(arr.begin(),arr.begin()+k2);
        for(int i=k2;i<n;i++){
            pq2.push(arr[i]);
            while(pq2.size()>k2){
                pq2.pop();
            }
        } 
        long long sum=0; pq2.pop();
        while(pq2.size()>k1){
            sum+=pq2.top();
            pq2.pop();
        }
        return sum;
    
    }
};
