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
vector<vector<int>> sol;
vector<int> ans;
int n;
map<int,int> m;
void rec(int level){
     if(level==n){
        sol.push_back(ans);
        return;
     }
     for(auto it:m){
        int hi=it.first;
        if(m[hi]>0){
            m[hi]--;
            ans.push_back(hi);
            rec(level+1);
            ans.pop_back();
            m[hi]++;
        }
     }
}
void solve(){
    int k;
    cin>>n;
    int a[n];
    
    fo(k,n){
        cin>>a[k];
        m[a[k]]++;
    }
    rec(0);
    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
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
    //cin>>t;
    t=1;
    while (t--)
    {
        
        solve();
    }
    return 0;
}