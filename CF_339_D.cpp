#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1);
    }
    void build(ll node, ll l, ll r, vi &arr, bool flag){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr,!flag);
        build(2*node+1,m+1,r,arr,!flag);
        if(flag) seg[node] = seg[2*node] | seg[2*node+1];
        else seg[node] = seg[2*node] ^ seg[2*node+1];
    }
    void update(ll node, ll l, ll r, ll index, ll val, bool flag){
        if(l==r){
            seg[node] = val;
            return;
        }
        ll m = l + (r-l)/2;
        if(index<=m) update(2*node,l,m,index,val,!flag);
        else update(2*node+1,m+1,r,index,val,!flag);
        if(flag) seg[node] = seg[2*node] | seg[2*node+1];
        else seg[node] = seg[2*node] ^ seg[2*node+1];
    }
    ll query(){
        return seg[1];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m; 
    ll temp = n;
    n = pow(2,n);
    vi arr(n); for(auto &x : arr) cin >> x;
    SegTree st(n); 
    if(temp%2==1) st.build(1,0,n-1,arr,true);
    else st.build(1,0,n-1,arr,false);
    while(m--){
        ll index,val; cin >> index >> val;
        if(temp%2==1) st.update(1,0,n-1,index-1,val,true);
        else st.update(1,0,n-1,index-1,val,false);
        cout << st.query() << "\n";
    }
}