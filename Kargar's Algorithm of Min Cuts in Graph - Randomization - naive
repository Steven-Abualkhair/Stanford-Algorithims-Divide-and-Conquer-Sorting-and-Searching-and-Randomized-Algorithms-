#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define debug(x) cout<<#x<<" = "<<x <<  '\n';

int Rand(int l, int r){
  static mt19937 
  rng(chrono::steady_clock::now().time_since_epoch().count());

  uniform_int_distribution<int> ludo(l, r); 
  return ludo(rng);
}
vector<pair<int,int>> Edges ; 
ll MinCuts(int vertices){
 vector<pair<int,int>> edges = Edges ; 
 int sz = vertices; 
 int ans = edges.size() ;
 while(sz > 2){
    // random idx
    int idx = Rand(0, edges.size() - 1) ;
    // contract
    int u = edges[idx].first ;
    int v = edges[idx].second ; 
    for(int i = 0 ; i < edges.size(); i++){
        if(edges[i].first == u) edges[i].first = v ; 
        if(edges[i].second == u) edges[i].second = v ;
        //erase self loops
        if(edges[i].first == edges[i].second ) edges.erase(edges.begin()+i) , ans-- ,i-- ; 
    }
    sz-- ;
 }
 return edges.size() ;
}
int main(){
  gojo();
  int N = 200; 
//   cin >> N ;
  // take input as a file of rows and columns(n rows and unkown number of columns in every row)
  for(int i = 0 ; i < N ; i++){
    string s; 
    getline(cin , s) ; 
    stringstream ss(s) ; 
    int n = -1 , u =-1, v = -1;
    int first = false ; 
    while(ss >> n){
        if(first == 0) u = n ;
        else v = n ; 
        if(~u and ~v){
             for(auto x : Edges){
                if(x.first == u and x.second == v or x.first == v and x.second == u) goto end;
             }
             Edges.push_back(make_pair(u , v)) ;
             end:;
        }
        first = true ;
    }
  }

  //monteCarlo
  int trials = N * N ;
  int ans = 1e9 ; 
  while(trials--){ // O( trials * n * m * m )
    int cur = MinCuts(N) ; 
    ans = min(cur , ans) ; 
  }
  cout << ans << endl;
 return 0 ; 
}
        
