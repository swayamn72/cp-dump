#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg, maxv;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1);
        maxv.resize(4*n+1);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = arr[l];
            maxv[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = seg[2*node] + seg[2*node+1];
        maxv[node] = max(maxv[2*node],maxv[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r && maxv[node]<=1) return;
        if(l==r){
            seg[node] = sqrt(seg[node]);
            maxv[node] = seg[node];
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node,l,m,ql,qr);
        update(2*node+1,m+1,r,ql,qr);
        seg[node] = seg[2*node] + seg[2*node+1];
        maxv[node] = max(maxv[2*node],maxv[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    ll tc = 1;
    while(cin >> n){
        cout << "Case #" << tc++ << ":" << "\n";
        vi arr(n); for(auto &x : arr) cin >> x;
        ll m; cin >> m;
        SegTree st(n);
        st.build(1,0,n-1,arr);
        while(m--){
            ll type; cin >> type;
            ll l,r; cin >> l >> r;
            l--; r--;
            if(l>r) swap(l,r);
            if(type==0){
                st.update(1,0,n-1,l,r);
            }else{
                cout << st.query(1,0,n-1,l,r) << "\n";
            }
        }
        cout << "\n";
    }
} 