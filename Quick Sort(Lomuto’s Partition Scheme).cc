#include<bits/stdc++.h>
using namespace std ;
#define ll long long

ll ans  ; 
vector<ll> arr ; 

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
  ans += (r - l) ;//number of comparisons  
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
        
