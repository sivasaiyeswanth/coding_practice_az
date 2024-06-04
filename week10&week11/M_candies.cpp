// Problem Statement
// There are 
// N children, numbered 
// 1,2,…,N.

// They have decided to share 
// K candies among themselves. Here, for each 
// i (
// 1≤i≤N), Child 
// i must receive between 
// 0 and 
// a 
// i
// ​
//   candies (inclusive). Also, no candies should be left over.

// Find the number of ways for them to share candies, modulo 
// 10 
// 9
//  +7. Here, two ways are said to be different when there exists a child who receives a different number of candies.

// Constraints
// All values in input are integers.
// 1≤N≤100
// 0≤K≤10 
// 5
 
// 0≤a 
// i
// ​
//  ≤K
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

int n,k;
int a[110];
int dp[110][100010];

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            dp[i][j]=0;
            if(i==n-1){
                if(j>a[i]){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=1;
                }
            }
            else{
                if(a[i]>=j){
                    dp[i][j]=dp[i+1][j];
                    
                }
                else{
                    dp[i][j]=((dp[i+1][j]%mod-dp[i+1][j-a[i]-1]%mod)+mod)%mod;
                }
                dp[i][j]%=mod;
            }
        }
        for(int t=1;t<=k;t++){
            dp[i][t]=(dp[i][t-1]%mod+dp[i][t]%mod)%mod;
        }
    }
        
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=k;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(k>0) cout<<((dp[0][k]%mod-dp[0][k-1]%mod)%mod+mod)%mod<<endl;
    else cout<<dp[0][k]<<endl;
    

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
    //cin>>t;
    
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}