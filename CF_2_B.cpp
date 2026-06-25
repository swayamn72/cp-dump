#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg, lazya, lazyd;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
        lazya.resize(4*n+1,0);
        lazyd.resize(4*n+1,0);
    }
    void applyap(ll node, ll l, ll r, ll a, ll d){
        ll len = r-l+1;
        seg[node] += (len * (2*a+(len-1)*d))/2;
        lazya[node] += a;
        lazyd[node] += d;
    }
    void push(ll node, ll l, ll r){
        if(l==r) return;
        if(lazya[node]!=0 || lazyd[node]!=0){
            ll m = l + (r-l)/2;
            applyap(2*node,l,m,lazya[node],lazyd[node]);
            ll leftlen = m-l+1;
            ll righta = lazya[node] + leftlen * lazyd[node];
            applyap(2*node+1,m+1,r,righta,lazyd[node]);
            lazya[node] = 0;
            lazyd[node] = 0;
        }
    }
    void updateap(ll node, ll l, ll r, ll ql, ll qr, ll a, ll d){
        if(ql>r || qr<l) return;
        if(ql<=l && qr>=r){
            ll offset = l - ql;
            ll curra = a + offset*d;
            applyap(node,l,r,curra,d);
            return;
        }
        push(node,l,r);
        ll m = l + (r-l)/2;
        updateap(2*node,l,m,ql,qr,a,d);
        updateap(2*node+1,m+1,r,ql,qr,a,d);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll x){
        if(l==r) return seg[node];
        push(node,l,r);
        ll m = l + (r-l)/2;
        if(x<=m) return query(2*node,l,m,x);
        else return query(2*node+1,m+1,r,x);
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
            ll l,r,a,d; cin >> l >> r >> a >> d;
            st.updateap(1,0,n-1,l-1,r-1,a,d);
        }else{
            ll x; cin >> x;
            cout << st.query(1,0,n-1,x-1) << "\n";
        }
    }
}