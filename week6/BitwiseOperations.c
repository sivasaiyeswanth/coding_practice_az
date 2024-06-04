#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
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

void solve(){
   int n,x;
   cin>>n;
   vector<int> a;
   for(int i=0;i<n;i++){
    int j;cin>>j;a.push_back(j);
   }
   
   int count[20];
   for(int i=0;i<20;i++){
    int cnt=0;
    for(auto j:a){
        if((j>>i)%2==1){
            cnt++;
            //cout<<"bit no: "<<i<<" count: "<<cnt<<endl;
            
        }
    }
    count[i]=cnt;
    // cout<<"a's elements: ";
    // for(auto p:a){
    //  cout<<p<<" ";
    // }
    // cout<<endl;
   }
//    for(auto p:count){
//      cout<<p<<" ";
//     }
//     cout<<endl;
   int ans=0;
   for(int i=0;i<n;i++){
    int num=0;
   for(int i=0;i<20;i++){
    
    if(count[i]){
        num|=(1ll<<i);
        count[i]--;
    }
    
   }
   //cout<<num<<endl;
   ans+=num*num;
   }
   
   cout<<ans<<endl;
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
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    return 0;
}