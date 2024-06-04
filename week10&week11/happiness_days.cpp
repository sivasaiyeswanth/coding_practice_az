// C - Vacation  / 
// Time Limit: 2 sec / Memory Limit: 1024 MB

// Score : 
// 100 points

// Problem Statement
// Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

// The vacation consists of 
// N days. For each 
// i (
// 1≤i≤N), Taro will choose one of the following activities and do it on the 
// i-th day:

// A: Swim in the sea. Gain 
// a 
// i
// ​
//   points of happiness.
// B: Catch bugs in the mountains. Gain 
// b 
// i
// ​
//   points of happiness.
// C: Do homework at home. Gain 
// c 
// i
// ​
//   points of happiness.
// As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

// Find the maximum possible total points of happiness that Taro gains.

// Constraints
// All values in input are integers.
// 1≤N≤10 
// 5
 
// Input
// Input is given from Standard Input in the following format:

// Output
// Print the maximum possible total points of happiness that Taro gains#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define int long long
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
#define mod 1000000007
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int n,w;
int a[100001];
int b[100001];
int c[100001];
int dp[100000][4];
int val;
int rec(int level,int prev){
    //pruning (invalid)
    
    //base case
    if(level==n){
        return 0;
    }
    //cache (if already stored)
    if(dp[level][prev]!=-1) return dp[level][prev];
    //recursive case
    int ans;
    if(prev==1){
        ans=b[level]+rec(level+1,2);
        ans=max(ans,c[level]+rec(level+1,3));
    }
    else if(prev==2){
        ans=a[level]+rec(level+1,1);
        ans=max(ans,c[level]+rec(level+1,3));
    }
    else if(prev==3){
        ans=a[level]+rec(level+1,1);
        ans=max(ans,b[level]+rec(level+1,2));
    }
    else{
        ans=a[level]+rec(level+1,1);
        ans=max(ans,b[level]+rec(level+1,2));
        ans=max(ans,c[level]+rec(level+1,3));
    }
    
    //save and mabe return
    return dp[level][prev]=ans;
    


}
void solve(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,0)<<endl;

}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N=100;
    int t=1;
    
    
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}