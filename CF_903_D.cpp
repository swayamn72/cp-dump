#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
void print128(__int128_t n) {
    if (n < 0) { cout << "-"; n = -n; }
    if (n == 0) { cout << 0 << "\n"; return; }
    string s;
    while (n > 0) { s += (char)('0' + (n % 10)); n /= 10; }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}
struct SegTree{
    ll n; vector<pair<ll,ll>> seg;
    SegTree(ll n){
        this->n = n;
        seg.resize(4*n+1,{0,0});
    }
    pair<ll,ll> merge(pair<ll,ll>&a, pair<ll,ll>&b){
        pair<ll,ll> node;
        node.first = a.first+b.first;
        node.second = a.second+b.second;
        return node;
    }
    void update(ll node, ll l, ll r, ll i, ll v){
        if(l==r){
            seg[node] = {seg[node].first+v, seg[node].second+1};
            return; 
        }
        ll m = l + (r-l)/2;
        if(i<=m) update(2*node,l,m,i,v);
        else update(2*node+1,m+1,r,i,v);
        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }
    pair<ll,ll> query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l || ql>qr) return {0LL,0LL};
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
        vi arr(n); for(auto &x : arr) cin >> x;
        set<ll> s; for(auto a : arr) s.insert(a);
        map<ll,ll> mp; ll temp = 0;
        for(auto a : s) mp[a] = temp++;
        SegTree st(temp);
        __int128_t res = 0;
        for(auto a : arr){
            ll idx = mp[a];
            ll idx2 = idx-1;
            if(s.count(a-1)) idx2--;
            auto [u,v] = st.query(1,0,temp-1,0,idx2);
            res -= u;
            res += (v*a);
            
            ll idx3 = idx+1;
            if(s.count(a+1)) idx3++;
            auto [x,y] = st.query(1,0,temp-1,idx3,temp-1);
            res -= x;
            res += (y*a);

            st.update(1,0,temp-1,idx,a);
        }
        print128(res);
    }
} 