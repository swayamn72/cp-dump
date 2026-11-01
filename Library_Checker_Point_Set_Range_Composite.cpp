#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;
struct Node{
    ll a,b;
    // identity function f(x) = 1*x + 0
    Node() : a(1), b(0) {}
    Node(ll a, ll b){
        this->a = a%mod;
        this->b = b%mod;
    }
};
Node merge(const Node &n1, const Node &n2){
    Node res;
    res.a = (n1.a*n2.a)%mod;
    res.b = ((n1.b*n2.a)%mod+n2.b)%mod;
    return res;
}
struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int n, const vector<pair<ll, ll>>& arr) {
        this->n = n;
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int l, int r, const vector<pair<ll, ll>>& arr) {
        if (l == r) {
            tree[node] = Node(arr[l].first, arr[l].second);
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, ll c, ll d) {
        if (l == r) {
            tree[node] = Node(c, d);
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, c, d);
        else update(2 * node + 1, mid + 1, r, idx, c, d);
        
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return Node(); // Returns identity function
        if (ql <= l && r <= qr) return tree[node];
        
        int mid = l + (r - l) / 2;
        return merge(query(2 * node, l, mid, ql, qr), 
                     query(2 * node + 1, mid + 1, r, ql, qr));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;z
    while(t--){
        ll n,q; cin >> n >> q;
        vector<pair<ll,ll>> arr(n);
        for(auto &[a,b] : arr) cin >> a >> b;
        SegTree st(n,arr);
        for(ll i=0; i<q; i++){
            ll type; cin >> type;
            if(type==0){
                ll p,c,d; cin >> p >> c >> d;
                st.update(1,0,n-1,p,c,d);
            }else{
                ll l,r,x; cin >> l >> r >> x;
                Node res = st.query(1,0,n-1,l,r-1);
                ll ans = (res.a*x%mod + res.b)%mod;
                cout << ans << "\n";
            }
        }
    }
}