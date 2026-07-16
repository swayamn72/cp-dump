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
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = v;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return 0LL;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return max(query(2*node,l,m,ql,qr),query(2*node+1,m+1,r,ql,qr));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        SegTree st(n);
        map<ll,vector<pair<ll,ll>>> mp;
        vi dp(n); 
        dp[0] = arr[0];
        mp[arr[0]+1].push_back({dp[0],0});
        for(ll i=1; i<n; i++){
            for(auto [a,b] : mp[i]){
                st.update(1,0,n-1,b,a);
            }
            ll idx = i - arr[i] - 1;
            ll maxv = 0;
            if(idx>=0){
                maxv += st.query(1,0,n-1,0,idx);
            }
            dp[i] = max(dp[i-1],arr[i]+maxv);
            mp[i+arr[i]+1].push_back({arr[i]+maxv,i});
        }
        cout << dp[n-1] << "\n";
    }
}