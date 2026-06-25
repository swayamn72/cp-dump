#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg, lazyadd, lazyassign;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
        lazyadd.resize(4*n+1,0);
        lazyassign.resize(4*n+1,-1);
    }
    void applyassign(ll node, ll l, ll r, ll val){
        lazyassign[node] = val;
        lazyadd[node] = 0;
        seg[node] = val * (r-l+1);
    }
    void applyadd(ll node, ll l, ll r, ll val){
        lazyadd[node] += val;
        seg[node] += val * (r-l+1);
    }
    void push(ll node, ll l, ll r){
        if(l==r) return;
        ll m = l + (r-l)/2;
        if(lazyassign[node]!=-1){
            applyassign(2*node,l,m,lazyassign[node]);
            applyassign(2*node+1,m+1,r,lazyassign[node]);
            lazyassign[node] = -1;
        }
        if(lazyadd[node]!=0){
            applyadd(2*node,l,m,lazyadd[node]);
            applyadd(2*node+1,m+1,r,lazyadd[node]);
            lazyadd[node] = 0;
        }
    }
    void updateadd(ll node, ll l, ll r, ll ql, ll qr, ll v){
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            applyadd(node,l,r,v);
            return;
        }
        push(node, l, r);
        ll m = l + (r-l)/2;
        updateadd(2*node,l,m,ql,qr,v);
        updateadd(2*node+1,m+1,r,ql,qr,v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    void updateassign(ll node, ll l, ll r, ll ql, ll qr, ll v){
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            applyassign(node,l,r,v);
            return;
        }
        push(node, l, r);
        ll m = l + (r-l)/2;
        updateassign(2*node,l,m,ql,qr,v);
        updateassign(2*node+1,m+1,r,ql,qr,v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && qr>=r){
            return seg[node];
        }
        push(node,l,r);
        ll m = l + (r-l)/2;
        return query(2*node,l,m,ql,qr) + query(2*node+1,m+1,r,ql,qr);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    SegTree st(n);
    while(m--){
        ll type; cin >> type;
        if(type==1){
            ll l,r,v; cin >> l >> r >> v;
            st.updateassign(1,0,n-1,l,r-1,v);
        }else if(type==2){
            ll l,r,v; cin >> l >> r >> v;
            st.updateadd(1,0,n-1,l,r-1,v);
        }else{
            ll l,r; cin >> l >> r;
            cout << st.query(1,0,n-1,l,r-1) << "\n";
        }
    }
}