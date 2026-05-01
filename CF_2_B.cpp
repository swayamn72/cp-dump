#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct DSU{
    ll n; vector<ll> size, parent, mine, maxe;
    DSU(ll n){
        this->n = n;
        size.resize(n,1);
        parent.resize(n); for(ll i=0; i<n; i++) parent[i]=i;
        mine.resize(n); for(ll i=0; i<n; i++) mine[i]=i;
        maxe.resize(n); for(ll i=0; i<n; i++) maxe[i]=i;
    }
    ll find(ll i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    vector<ll> findmaxmin(ll u){
        ll parent = find(u);
        return {mine[parent],maxe[parent],size[parent]};
    }
    void unite(ll u, ll v){
        ll rootu = find(u);
        ll rootv = find(v);
        if(rootu!=rootv){
            if(size[rootu]>size[rootv]) swap(rootu,rootv);
            parent[rootu] = rootv;
            size[rootv] += size[rootu];
            maxe[rootv] = max(maxe[rootv],maxe[rootu]);
            mine[rootv] = min(mine[rootv],mine[rootu]);
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    DSU dsu(n);
    while(m--){
        string s; cin >> s;
        if(s=="union"){
            ll a,b; cin >> a >> b;
            dsu.unite(a-1,b-1);
        }else{
            ll a; cin >> a;
            vector<ll> res = dsu.findmaxmin(a-1);
            cout << res[0]+1 << " " << res[1]+1 << " " << res[2] << "\n";
        }
    }
}