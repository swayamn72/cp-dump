#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct Fenwick{
    ll n; vector<vi> tree;
    Fenwick(ll n){
        this->n = n;
        tree.assign(n+1,vi(n+1,0));
    }
    void add(ll x, ll y, ll v){
        for(ll i=x; i<=n; i+=(i&-i)){
            for(ll j=y; j<=n; j+=(j&-j)){
                tree[i][j] += v;
            }
        }
    }
    ll query(ll x, ll y){
        ll res = 0;
        for(ll i=x; i>=1; i-=(i&-i)){
            for(ll j=y; j>=1; j-=(j&-j)){
                res += tree[i][j];
            }
        }
        return res;
    }
    ll rangequery(ll x1, ll y1, ll x2, ll y2){
        return query(x2,y2)
        + query(x1-1,y1-1) 
        - query(x2,y1-1)
        - query(x1-1,y2);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        Fenwick ft(n);
        vector<vi> grid(n+1,vi(n+1,0));
        while(true){
            string s; cin >> s;
            if(s=="END") break;
            if(s=="SET"){
                ll x,y,v; cin >> x >> y >> v;
                x++; y++;
                ll diff = v - grid[x][y];
                grid[x][y] = v;
                ft.add(x,y,diff);
            }else{
                ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
                x1++; y1++; x2++; y2++;
                cout << ft.rangequery(x1,y1,x2,y2) << "\n";
            }
        }

    }
} 