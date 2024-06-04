#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[510][510];
int back[510][510];
string s,t;
int n,m;
int a;
int prevs,prevt;
int rec(int l1,int l2){
  if(l1==s.size() || l2==t.size()){
    return 0;
  }
  
  if(dp[l1][l2]!=-1) return dp[l1][l2];
  int ans=-1e9;
  int p=rec(l1+1,l2);
    if(ans<p){
      ans=p;
      back[l1][l2]=0;
    }
  
  int q=rec(l1,l2+1);
    if(ans<q){
      ans=q;
      back[l1][l2]=1;
    }
  
  
    if(s[l1]==t[l2]){
      int r=rec(l1+1,l2+1);
      if(ans<r+1){
        ans=r+1;
        back[l1][l2]=2;
      }
    }
  
  return dp[l1][l2]=ans;
}
void gen(int i,int j){
  if(i==s.size() || j==t.size()){
    return;
  }
  if(back[i][j]==0){
    gen(i+1,j);
  }
  else if(back[i][j]==1){
    gen(i,j+1);
  }
  else if(back[i][j]==2){
    cout<<"i: "<<i<<" j: "<<j<<endl;
    if(prevs==-1 && prevt==-1){
      int f=max(i,j);
      a=a+f;
      prevs=i;prevt=j;
      cout<<a<<" "<<endl;
    }
    else{
      a+=(max(i-prevs-1,j-prevt-1));
      prevs=i;prevt=j;
      cout<<a<<endl;
    }
    
    gen(i+1,j+1);
  }
}
void solve(){
  cin>>s>>t;
  n=s.size();m=t.size();

  for(int i=0;i<n+5;i++){
    for(int j=0;j<m+5;j++){
      dp[i][j]=-1;
    }
  }
  int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)ans = max(ans, rec(i, j));
    }

  prevs=-1;prevt=-1;
  gen(0,0);
  cout<<a<<endl;
  cout<<prevs<<" "<<prevt<<endl;
  cout<<(n-1-prevs)<<" "<<m-1-prevt<<endl;
 cout<<a+(max((n-prevs-1),(m-prevt-1)))<<endl;
}
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  solve();
return 0;
  
}
  
  
  
