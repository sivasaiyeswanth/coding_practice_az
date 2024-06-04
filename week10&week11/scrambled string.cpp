// /Description
// We can scramble a string 
// �
// s to get a string 
// �
// t using the following algorithm:

// If the length of the string is 
// 1
// 1, stop.

// If the length of the string is 
// >
// 1
// >1, do the following: 2.1 Split the string into two non-empty substrings at a random index, i.e., if the string is 
// �
// s, divide it to 
// �
// x and 
// �
// y where 
// �
// =
// �
// +
// �
// s=x+y. 2.2 Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, 
// �
// s may become 
// �
// =
// �
// +
// �
// s=x+y or 
// �
// =
// �
// +
// �
// s=y+x.

// Apply step 
// 1
// 1 recursively on each of the two substrings 
// �
// x and 
// �
// y.
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
void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
string s,t;
int dp[45][45][45];
int rec(int l,int r,int i){
    
    int j=i+r-l;
    if(l>r || i>j){
        return false;
    }
     if (l == r) {
        if (s[l] == t[i])return true;
        return false;
    }
    
    if (dp[l][r][i] != -1)return dp[l][r][i];

    int ans;
    ans = 0; 
    if (s.substr(l, r - l + 1) == t.substr(i, j - i + 1))return dp[l][r][i] = 1;
    
    for(int k=l;k<r;k++){
        ans=ans|((rec(l,k,i))&rec(k+1,r,(i+(k-l)+1)));
        ans=ans|(rec(l,k,(j-(k-l+1)+1))&rec(k+1,r,i));
    }
    return dp[l][r][i]=ans;

}
void solve(){
    cin>>s>>t;
    memset(dp, -1, sizeof(dp));
    if(rec(0,s.size()-1,0)){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    
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
    int t;
    //t=1;
    cin>>t;
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}