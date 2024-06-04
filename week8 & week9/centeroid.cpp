#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl "\n"
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vector<vector<int>> out;

void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int n;
vector<vector<int>> v;
vector<int> childs;
int cent;
int cnt;
int f=false;
int dfs(int node, int parent) {
    childs[node]=1;
    bool centeroid=true;
     for (auto it : v[node]) {
        if(it!=parent){
            childs[node]+=dfs(it,node);
            if(childs[it]>n/2) {
                centeroid=false;
            }
        }           
    }
    if(n-childs[node]>n/2) centeroid=false;
    if(centeroid){
        cent=min(cent,node);
    }
    return childs[node];
}
    
   



void solve() {
    
    cin>>n;
    v.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cent=1e18;
    childs.resize(n+1);
    dfs(1,-1);
    cout<<cent<<endl;
    

    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
     //cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}