#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct DSU{
    ll n; vector<ll> parent,size;
    DSU(ll n){
        this->n = n;
        parent.resize(n+1); 
        size.resize(n+1,1);
        for(ll i=0; i<=n; i++) parent[i] = i;
    }
    ll find(ll i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(ll i, ll j){
        ll rooti = find(i);
        ll rootj = find(j);
        if(rooti != rootj){
            if(size[rooti]<size[rootj]) swap(rooti,rootj);
            parent[rootj] = rooti;
            size[rooti] += size[rootj];
            n--;
            return true;
        }
        return false;
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
            dsu.unite(a,b);
        }else{
            ll a,b; cin >> a >> b;
            ll aparent = dsu.find(a);
            ll bparent = dsu.find(b);
            cout << ((aparent == bparent) ? "YES" : "NO");
            cout << "\n";
        }
    }
}