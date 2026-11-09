#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg, lazy;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void push(ll node, ll l, ll r){
        if(lazy[node]!=0){
            seg[node] += lazy[node]*(r-l+1);
            if(l!=r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll v){
        push(node,l,r);
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            lazy[node] += v;
            push(node,l,r);
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node, l, m, ql, qr, v);
        update(2*node+1, m+1, r, ql, qr, v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        push(node,l,r);
        if(ql>r || qr<l) return 0LL;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,p; cin >> n >> p;    
        SegTree st(n);
        while(p--){
            ll type; cin >> type;
            if(type==0){
                ll l,r,v; cin >> l >> r >> v; l--; r--;
                st.update(1, 0, n-1, l, r, v);
            }else{
                ll l,r; cin >> l >> r; l--; r--;
                cout << st.query(1,0,n-1,l,r) << "\n";
            }
        }    
    }
}