//if we want to find positive cycle--
//negative the costs so positive cycle becomes 
//negative and we can find it
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
struct Unionfind{
    vector<int> rank,parent;int set_size;
    Unionfind(int n){
        rank.assign(n,1);
        set_size=n;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        else return find(parent[x]);
    }
    void unite(int x,int y){
        int a=find(x);int b=find(y);
        
        if(a!=b){
            if(rank[a]<rank[b]){
                parent[a]=b;
                rank[b]+=rank[a];
            }
            else{
                parent[b]=a;
                rank[a]+=rank[b];
            }
            set_size--;
        }
        

    }
    int same(int x,int y){
        int a=find(x);int b=find(y);
        if(a!=b) return 0;
        else return 1;
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    Unionfind u(n);
    while(q--){
        int com,x,y;
        cin>>com>>x>>y;
        if(com==0){
            u.unite(x,y);
        }
        else{
            cout<<u.same(x,y)<<endl;
        }
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
    t=1;
    //cin>>t;
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}