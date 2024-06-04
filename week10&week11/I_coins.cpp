// Problem Statement
// Let 
// N be a positive odd number.

// There are 
// N coins, numbered 
// 1,2,…,N. For each 
// i (
// 1≤i≤N), when Coin 
// i is tossed, it comes up heads with probability 
// p 
// i
// ​
//   and tails with probability 
// 1−p 
// i
// ​
//  .

// Taro has tossed all the 
// N coins. Find the probability of having more heads than tails.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n;
long double a[3030];
long double dp[3030][3030];
int vis[3030][3030];
long double rec(int level,int heads){
  
  if(level>n){
    //cout<<"level: "<<level<<endl;
    //cout<<"heads: "<<heads<<endl;
    if(heads>=((n+1)/2)){
      //cout<<"heads: "<<heads<<endl;
      return 1;
    }
    else return 0;
  }
  
  if(vis[level][heads]!=0) return dp[level][heads];
  vis[level][heads]=1;
  
  double ans;
  ans=rec(level+1,heads+1)*a[level];
  //cout<<"level: "<<level<<" forhead: "<<ans<<endl;
  double p=ans;
  ans+=rec(level+1,heads)*(1-a[level]);
  //cout<<"level: "<<level<<" fortail: "<<ans-p<<endl;
  return dp[level][heads]=ans;
}

void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<=n;j++){
      vis[i][j]=0;
    }
  }
  cout<<fixed<<setprecision(10)<<rec(1,0)<<endl;
  
}
int32_t main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  solve();
}