#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l+(r-l)/2;
        if(i<=m) update(2*node, l, m, i);
        else update(2*node+1, m+1, r, i);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr){cin >> x; x--;} 
        vector<vi> dp(2,vi(n+1));
                
    }
}