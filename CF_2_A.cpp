#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct Node{
    ll sum = 0, pref = 0, suff = 0, best = 0;
    Node(){
        sum = pref = suff = best = 0;
    }
    Node(ll n){
        sum = n;
        pref = max(0LL,n);
        suff = max(0LL,n);
        best = max(0LL,n);
    }
};
struct SegTree{
    ll n; vector<Node> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n);
    }
    Node merge(Node a, Node b){
        Node node = Node();
        node.sum = a.sum + b.sum;
        node.pref = max(a.pref,a.sum+b.pref);
        node.suff = max(b.suff,b.sum+a.suff);
        node.best = max({a.best,b.best,a.suff+b.pref});
        return node;
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
    ll query(){
        return seg[1].best;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vi arr(n);
    for(auto &x : arr) cin >> x;
    SegTree st(n); st.build(1,0,n-1,arr);
    cout << st.query() << "\n";
    while(m--){
        ll i,v; cin >> i >> v;
        st.update(1,0,n-1,i,v);
        cout << st.query() << "\n";
    }
}