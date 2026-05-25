#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
    }
    void update(ll node, ll l, ll r, ll index, ll val){
        if(l==r){
            seg[node] += val;
            return;
        }
        ll m = l + (r-l)/2;
        if(index<=m) update(2*node,l,m,index,val);
        else update(2*node+1,m+1,r,index,val);
        seg[node] = seg[2*node] + seg[2*node+1];
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
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,q; cin >> n >> q;
    vi arr(n,0);
    ll sub = 0;
    SegTree st(q);
    st.update(1,0,q-1,0,n);
    ll tempq = q;
    while(tempq--){
        ll t, x; cin >> t >> x; x--;
        if(t==1){
            arr[x]++;
            st.update(1,0,q-1,arr[x]-1,-1);
            st.update(1,0,q-1,arr[x],1);
            ll zeros = st.query(1,0,q-1,sub,sub);
            if(zeros==0) sub++;
        }else{
            x++;
            ll temp = x + sub;
            cout << st.query(1,0,q-1,temp,q-1) << "\n";
        }
    }
}