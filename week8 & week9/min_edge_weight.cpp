//adding a min weight edge between nodes(diff trees)
// having all edges weifgts greater than this
//increases count by that (u_tree_nodes*v_tree_nodes)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int gcd(int a,int b){return (a%b==0)?b:gcd(b,a%b);}
int lcm(int a,int b){int i=1;while(a*i%b){i++;}return a*i;}
#define F first
#define S second
using state = pair<int, int>;
using lli = long long;
#define int long long

lli binpow(lli a, lli b, lli mod) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return a * binpow(a, b - 1, mod) % mod;
    } else {
        lli temp = binpow(a, b / 2, mod);
        return temp * temp % mod;
    }
}

struct UnionFind{
    int n, set_size, *parent, *rank;
    UnionFind(){};
    UnionFind(int a){
        n=set_size=a;
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i=1; i<=n; i++) parent[i]=i, rank[i]=1;
    }
    
    int Find(int x){
        if(x!=parent[x]) return parent[x]=Find(parent[x]);
        return x;
    }
    
    void merge(int x, int y){
        int xroot=Find(x), yroot=Find(y);
        if(xroot!=yroot){
            if(rank[xroot]>=rank[yroot]){
                parent[yroot]=xroot;
                rank[xroot]+=rank[yroot];
            } else {
                parent[xroot]=yroot;
                rank[yroot]+=rank[xroot];
            }
            set_size-=1;
        }
    }
    bool check(int x, int y){
        int xroot=Find(x), yroot=Find(y);
        if(xroot==yroot) return 1;
        else return 0;
    }
    
    void reset(){
        set_size=n;
        for(int i=1; i<=n; i++) parent[i]=i, rank[i]=1;
    }
    
    int size(){return set_size;}
    void print(){
        for(int i=1; i<=n; i++) {
            cout<<i<<"->"<<parent[i]<<endl;
        }
    }
};

void solve(){
    int n;
    cin>>n;
    UnionFind uf(n);
    uf.reset();
    vector<pair<int,state>> edge;
    for(int i=1; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        edge.push_back({c,{a,b}});
    }
    
    sort(edge.begin(), edge.end());
    reverse(edge.begin(), edge.end());
    int ans=0;
    for(auto v:edge){
        
        int x=v.S.F, y=v.S.S;
        //cout<<v.F<<" "<<x<<" "<<y<<endl;
        int xroot=uf.Find(x);
        int yroot=uf.Find(y);
        
        ans+=v.F*(uf.rank[xroot]*uf.rank[yroot]);
        uf.merge(x,y);
    }
    
    cout<<ans<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin>>t; while(t--)
    solve();
}


.