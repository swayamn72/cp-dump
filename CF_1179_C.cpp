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
    void push(ll node){
        if(lazy[node]!=0){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
            seg[2*node] += lazy[node];
            seg[2*node+1] += lazy[node];
            lazy[node]=0;
        }
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll v){
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            seg[node] += v;
            lazy[node] += v;
            return;
        }
        push(node);
        ll m = l + (r-l)/2;
        update(2*node, l, m, ql, qr, v);
        update(2*node+1, m+1, r, ql, qr, v);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    ll walk(ll node, ll l, ll r){
        if(l==r) return l;
        push(node);
        ll m = l + (r-l)/2;
        if(seg[2*node+1]>0) return walk(2*node+1, m+1, r);
        else return walk(2*node,l,m);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;
        ll maxv = 1e6+1;
        SegTree st(maxv);
        for(ll i=0; i<n; i++){
            st.update(1, 1, maxv, 1, a[i], 1);
        }
        for(ll i=0; i<m; i++){
            st.update(1, 1, maxv, 1, b[i], -1);
        }
        ll q; cin >> q;
        while(q--){
            ll type; cin >> type;
            ll i,x; cin >> i >> x; i--;
            if(type==1){
                st.update(1, 1, maxv, 1, a[i], -1);
                a[i] = x;
                st.update(1, 1, maxv, 1, a[i], 1);
            }else{
                st.update(1, 1, maxv, 1, b[i], 1);
                b[i] = x;
                st.update(1, 1, maxv, 1, b[i], -1);
            }
            if(st.seg[1]>0){
                cout << st.walk(1, 1, maxv) << "\n";
            }else{
                cout << -1 << "\n";
            }
        }        
    }
}