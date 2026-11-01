#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+5);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node, l, m, i, v);
        else update(2*node+1, m+1, r, i, v);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);
    }
    ll kth(ll node, ll l, ll r, ll k){
        if(l==r) return l;
        ll m = l + (r-l)/2;
        if(seg[2*node]>=k) return kth(2*node,l,m,k);
        else return kth(2*node+1,m+1,r,k-seg[2*node]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll q; cin >> q;
        vector<pair<char,ll>> queries;
        set<ll> s;
        while(q--){
            char ch; cin >> ch;
            ll a; cin >> a;
            queries.push_back({ch,a});
            s.insert(a);
        }
        ll temp = 1;
        map<ll,ll> mp;
        for(auto a : s) mp[a] = temp++;
        vi rev(temp);
        for(auto a : mp) rev[a.second] = a.first;
        SegTree st(temp-1);
        for(auto a : queries){
            char op = a.first;
            ll v = a.second;
            if(op=='I'){
                st.update(1, 1, st.n, mp[v], 1);
            }else if(op=='D'){
                st.update(1,1,st.n,mp[v],0);
            }else if(op=='C'){
                cout << st.query(1,1,st.n,1,mp[v]-1) << "\n";
            }else if(op=='K'){
                if(st.seg[1]<v){
                    cout << "invalid" << "\n";
                }else{
                    ll idx = st.kth(1,1,st.n,v);
                    cout << rev[idx] << "\n";
                }
            }
        }
    }
}