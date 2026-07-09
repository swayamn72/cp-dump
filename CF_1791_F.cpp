#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
struct SegTree{
    ll n; vi seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,0);
    }
    void update(ll node, ll l, ll r, ll ql, ll qr, ll v){
        if(qr<l || ql>r) return;
        if(ql<=l && qr>=r){
            seg[node] += v;
            return;
        }
        ll m = l + (r-l)/2;
        update(2*node,l,m,ql,qr,v);
        update(2*node+1,m+1,r,ql,qr,v);
    }
    ll query(ll node, ll l, ll r, ll i){
        if(l==r) return seg[node];
        ll m = l + (r-l)/2;
        if(i<=m) return seg[node] + query(2*node,l,m,i);
        else return seg[node] + query(2*node+1,m+1,r,i);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        SegTree st(n);
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll l,r; cin >> l >> r;
                l--; r--;
                st.update(1,0,n-1,l,r,1);
            }else{
                ll idx; cin >> idx; idx--;
                ll count = st.query(1,0,n-1,idx);
                ll num = arr[idx];
                for(ll i=0; i<count; i++){
                    if(num<10) break;
                    ll ans = 0;
                    while(num>0){
                        ll digit = num%10;
                        ans += digit;
                        num/=10;
                    }
                    num = ans;
                }
                cout << num << "\n";
            }
        }
    }
}