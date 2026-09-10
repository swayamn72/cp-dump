#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
struct SegTree{
    ll n; vector<pair<ll,ll>> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,{0,0});
    }
    pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b){
        pair<ll,ll> ans;
        ans.first = a.first + b.first;
        ans.second = a.second + b.second;
        return ans;
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node].first += v;
            seg[node].second++;
            return;
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    pair<ll,ll> query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l || ql>qr) return {0,0};
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        pair<ll,ll> a = query(2*node,l,m,ql,qr);
        pair<ll,ll> b = query(2*node+1,m+1,r,ql,qr);
        return merge(a,b);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> v(n);
        for(ll i=0; i<n; i++) cin >> v[i].first;
        for(ll i=0; i<n; i++) cin >> v[i].second;
        sort(v.begin(),v.end());

        vi temp; for(auto a : v) temp.push_back(a.second);
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        map<ll,ll> mp; ll idx = 0;
        for(auto a : temp){
            mp[a] = idx++;
        }
        ll res = 0;
        SegTree st(n);
        for(ll i=0; i<n; i++){
            ll idx = mp[v[i].second];
            pair<ll,ll> p = st.query(1,0,n-1,0,idx);
            res += p.second * v[i].first;
            res -= p.first;
            st.update(1,0,n-1,idx,v[i].first);
        }
        cout << res;
        
    }
} 