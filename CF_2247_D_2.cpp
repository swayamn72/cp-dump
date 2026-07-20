#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
struct Node{
    ll maxv = -1, minv = 2e18;
    bool flag = false;
    Node(){
    }
    Node(ll n){
        maxv = n;
        minv = n;
        flag = false;
    }
};
struct SegTree{
    ll n; vector<Node> seg;
    vi bad;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1);
        bad.resize(21,0);
    }
    void pull(ll node, ll level){
        ll left = 2*node, right = 2*node+1;
        seg[node].maxv = max(seg[left].maxv,seg[right].maxv);
        seg[node].minv = min(seg[left].minv,seg[right].minv);
        bool isbad = (seg[left].maxv>seg[right].minv);
        if(isbad!=seg[node].flag){
            if(isbad) bad[level]++;
            else bad[level]--;
            seg[node].flag = isbad;
        }
    }
    void build(ll node, ll l, ll r, ll level, vector<ll>&arr){
        if(l==r){
            seg[node] = Node(arr[l]);
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,level-1,arr);
        build(2*node+1,m+1,r,level-1,arr);
        pull(node,level);
    }
    void update(ll node, ll l, ll r, ll level, ll i, ll x){
        if(l==r){
            seg[node] = Node(x);
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,level-1,i,x);
        else update(2*node+1,m+1,r,level-1,i,x);
        pull(node,level);
    }
    ll ans(){
        for(ll i=20; i>=1; i--){
            if(bad[i]>0) return (1LL<<(i-1));
        }
        return 0;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << log2(1e6);
    ll t; cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll temp = n;
        while(__builtin_popcountll(temp)!=1){
            temp++;
            arr.push_back(1e10);
        }  
        // cout << arr.size() << "\n"; 
        SegTree st(temp);
        ll level = log2(temp);
        // cout << level << "\n";
        st.build(1,0,temp-1,level,arr);   
        cout << st.ans() << "\n";  
        while(q--){
            ll i,x; cin >> i >> x;
            st.update(1,0,temp-1,level,i,x);
            cout << st.ans() << "\n";
        }
    }
}