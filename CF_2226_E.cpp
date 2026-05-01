#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vector<ll> seg,lazy;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n);
        lazy.resize(4*n);
    }
    void push(ll node, ll l, ll r){
        if(lazy[node]!=0){
            seg[node] += lazy[node];
            if(l!=r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll val){
        push(node,l,r);
        if(r<ql || l>qr) return;
        if(ql<=l && qr>=r){
            lazy[node] += val;
            push(node,l,r);
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node,l,m,ql,qr,val);
        update(2*node+1,m+1,r,ql,qr,val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    ll query(){
        push(1,0,n);
        return seg[1];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        SegTree st(1e6+5);
        vector<ll> count(1e6,0);
        ll k = 0;
        for(ll i=0; i<n; i++){
            ll x = arr[i];
            if(x>0){
                ll lim = (x-1)/2;
                st.update(1,0,1e6,0,lim,1);
            }
            count[x]++;
            while(true){
                if(count[k]>0){
                    count[k]--;
                    if(k>0){
                        ll lim = (k-1)/2;
                        st.update(1,0,1e6,0,lim,-1);
                    }
                }else{
                    st.update(1,0,1e6,0,k,-1);
                }
                if()
            }
        }
    }
}