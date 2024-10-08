
#include<bits/stdc++.h>
using namespace std ;
#define ll long long

ll ans  ; 
vector<ll> arr ; 
int findMid(int l , int r){
    int n = r - l  ; 
    ll arr2[] = {arr[l] , arr[r] , arr[l + n / 2 ]} ; 
    if(arr2[0]<=max(arr2[1] , arr2[2]) and arr2[0]>=min(arr2[1] ,arr2[2]))return l;
    if(arr2[1]<=max(arr2[2] , arr2[0]) and arr2[1]>=min(arr2[0] ,arr2[2])) return r;
    if(arr2[2]<=max(arr2[1] , arr2[0]) and arr2[2]>=min(arr2[1] ,arr2[0])) return l + n/2;
}
int QuickSort(int l , int r ){
 int pivot = l ;
 int i = pivot + 1 ; // indix of first element greater than pivot  
 for(int j = pivot + 1 ; j <= r ; j++){
  if(arr[j] < arr[pivot]){
    swap(arr[i] , arr[j]) ;
    i++ ; 
  }
 }
 swap(arr[i - 1] , arr[pivot]) ; 
 return i  - 1  ; 
}
void divide(int l , int r){
  if(l>=r) return ; 
  int mid = findMid(l , r) ;
  if(mid == r)
  swap(arr[r] , arr[l]);
  else if(mid != l)
  swap(arr[mid] , arr[l]);
  ans += (r - l) ; // count number of comparisons
  int pivot = QuickSort(l , r) ; 
  divide(l , pivot - 1) ; 
  divide(pivot + 1 , r) ; 
}
int main(){
  gojo();
  int N = 10000; 
//   cin >> N ;
  arr.assign(N , {}) ; 
  for(auto &x : arr) cin >> x;  
  divide(0 , N - 1) ;
  // for(auto x : arr) cout << x << ' ' ; 
  // cout << endl ;
  cout << ans << endl;

    
  
 return 0 ; 
}
        
