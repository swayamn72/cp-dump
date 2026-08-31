#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct SegTree{
    ll n; vector<pair<ll,ll>> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+5);
    }
    void build(ll node, ll l, ll r, string &s){
        if(l==r){
            ll val = (s[l]=='A') ? 1 : -1;
            seg[node] = {val,val};
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,s);
        build(2*node+1,m+1,r,s);
        seg[node].first = seg[2*node].first + seg[2*node+1].first;
        seg[node].second = min(seg[2*node].second, seg[2*node+1].second + seg[2*node].first); 
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = {v,v};
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node].first = seg[2*node].first + seg[2*node+1].first;
        seg[node].second = min(seg[2*node].second, seg[2*node+1].second + seg[2*node].first); 
    }
    pair<ll,ll> query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return {0LL,1e18};
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        auto left = query(2*node,l,m,ql,qr);
        auto right = query(2*node+1,m+1,r,ql,qr);
        return {left.first+right.first,min(left.second,left.first+right.second)};
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;

        SegTree st(n);
        st.build(1,0,n-1,s);
        ll q; cin >> q;
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll i; char c; cin >> i >> c;
                i--;
                if(s[i]==c) continue;
                s[i] = c;
                ll v = (c=='A') ? 1 : -1;
                st.update(1,0,n-1,i,v);
            }else{
                ll l,r; cin >> l >> r;
                l--; r--;
                
                auto v = st.query(1,0,n-1,l,r);
                if(v.second>=0) cout << "Yes" << "\n";
                else cout << "No" << "\n";
            }
        }
    }
} 