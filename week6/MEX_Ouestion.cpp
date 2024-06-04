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

int MOD= 998244353;
int power(int a, int b, int p) {
    if(b == 0) return 1;
    int t = power(a, b/2, p);
    t = (t * t)%p;
    if(b % 2) return (a * t)%p;
    return t;
}

void solve(){
    cout<<"hi"<<endl;
   int n;
   cin>>n;
   int a[n];
   int* mapping = new int[10000001];
    int* pref = new int[10000001];
    int* MEX = new int[10000001];
   int maxi=-1;
   for(int i=0;i<n;i++){
    cin>>a[i];
    mapping[a[i]]++;
    maxi=max(maxi,a[i]);
   }
   cout<<"Mapping: \n";
   for(int i=0;i<100;i++){
    cout<<mapping[i]<<" ";
   }
   cout<<endl;
   for(int i=1;i<10000001;i++){
    pref[i]=(mapping[i]%MOD+pref[i-1]%MOD)%MOD;
   }
   cout<<"pref: \n";
   for(int i=0;i<100;i++){
    cout<<pref[i]<<" ";
   }
   cout<<endl;
   
   maxi=(maxi+1);
   for(int i=1;i<10000001;i++){
    int EleLessThanI=pref[i-1];
    int EleGreaterThanI=(n-pref[i]);
    int ans=power(2,EleLessThanI,MOD)-1;
    ans=(ans*power(2,EleGreaterThanI,MOD))%MOD;
    MEX[i]+=ans;
    MEX[i]%=MOD;
    
   }
   cout<<"MEX: \n";
   for(int i=0;i<100;i++){
    cout<<MEX[i]<<" ";
   }
   
   for(int i=1000000;i>1;i--){
    MEX[i]-=MEX[i-1];
    MEX[i]=(MEX[i]+mod)%mod;
   }
   cout<<"MEX: "<<endl;
   for(int i=0;i<100;i++){
    cout<<MEX[i]<<" ";
   }
   MEX[1]++;
   for(int i=3;i<10000001;i++){
if(MEX[i]>0)
    MEX[i]-=1;
    
   }
   cout<<"MEX: \n";
   for(int i=0;i<100;i++){
    cout<<MEX[i]<<" ";
   }
   cout<<endl;
   int sum=0;
   for(int i=1;i<100;i++){
    cout<<sum<<endl;
    sum=(sum+(MEX[i]*i)%MOD)%MOD;
   }
   cout<<sum<<endl;
   delete[] mapping;
    delete[] pref;
    delete[] MEX;

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
    cin>>t;
    while (t--)
    {
        
        solve();
    }
    return 0;
}