#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
ll inf = 1e18;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+10);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = min(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node, l, m, i, v);
        else update(2*node+1, m+1, r, i, v);
        seg[node] = min(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return inf;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        ll leftmin = query(2*node,l,m,ql,qr);
        ll rightmin = query(2*node+1,m+1,r,ql,qr);
        return min(leftmin,rightmin);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi v1(n); for(ll i=0; i<n; i++) v1[i] = arr[i]-i;
        vi v2(n); for(ll i=0; i<n; i++) v2[i] = arr[i]+i;
        SegTree left(n); left.build(1,0,n-1,v1);
        SegTree right(n); right.build(1,0,n-1,v2);
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll i,x; cin >> i >> x; i--;
                left.update(1,0,n-1,i,x-i);
                right.update(1,0,n-1,i,x+i);
                arr[i] = x;
            }else{
                ll i; cin >> i; i--;
                ll leftres = left.query(1,0,n-1,0,i);
                ll rightres = right.query(1,0,n-1,i,n-1);
                cout << min(leftres+i,rightres-i) << "\n";
            }
        }        
    }
}