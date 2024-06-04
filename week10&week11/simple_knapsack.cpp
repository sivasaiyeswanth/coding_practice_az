// Problem Statement
// There are 
// N items, numbered 
// 1,2,…,N. For each 
// i (
// 1≤i≤N), Item 
// i has a weight of 
// w 
// i
// ​
//   and a value of 
// v 
// i
// ​
//  .

// Taro has decided to choose some of the 
// N items and carry them home in a knapsack. The capacity of the knapsack is 
// W, which means that the sum of the weights of items taken must be at most 
// W.

// Find the maximum possible sum of the values of items that Taro takes home.
#include <bits/stdc++.h>
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
int value[101];
int weights[101];
int dp[101][100001];
int val;
int rec(int level,int weight,int val){
    //pruning (invalid)
    // if(weight>=w){
    //     return -1;
    // }
    //base case
    if(level==n){
        return 0;
    }
    //cache (if already stored)
    if(dp[level][weight]!=-1){
        return dp[level][weight];
    }
    int a=rec(level+1,weight,val);
    //recursive case
    
    if(weight+weights[level]<=w){
        a=max(a,value[level]+rec(level+1,weight+weights[level],val));
        
    }
    
    
    //save and mabe return
    return dp[level][weight]=a;


}
void solve(){
    
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>weights[i]>>value[i];
    }
    val=0;
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,0,0)<<endl;

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