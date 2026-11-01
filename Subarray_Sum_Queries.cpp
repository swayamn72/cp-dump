#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Node{
    ll pref, suff, sum, best;
    Node() : pref(0), suff(0), sum(0), best(0){}
    Node(ll v){
        pref = max(0LL,v);
        suff = max(0LL,v);
        best = max(0LL,v);
        sum = v;
    }
};
Node merge(const Node &a, const Node &b){
    Node res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref,a.sum+b.pref);
    res.suff = max(b.suff,b.sum+a.suff);
    res.best = max({a.best,b.best,a.suff+b.pref});
    return res;
}
struct SegTree{
    ll n; vector<Node> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1);
    }
    void build(ll node, ll l, ll r, vi &arr){
        if(l==r){
            seg[node] = Node(arr[l]);
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = Node(v);
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        SegTree st(n);
        st.build(1,0,n-1,arr);
        while(m--){
            ll i,x; cin >> i >> x; i--;
            st.update(1,0,n-1,i,x);
            cout << st.seg[1].best << "\n";
        }
    }
}