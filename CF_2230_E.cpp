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
    void build(ll node, ll l, ll r, vector<ll>&arr){
        if(l==r){
            seg[node] = arr[l];
            return;
        }
        ll m = l + (r-l)/2;
        build(2*node,l,m,arr);
        build(2*node+1,m+1,r,arr);
        seg[node] = min(seg[2*node],seg[2*node+1]);
    }
    ll query(ll node, ll l, ll r, ll ql, ll qr){
        if(ql>r || qr<l) return LLONG_MAX;
        if(ql<=l && qr>=r) return seg[node];
        ll m = l + (r-l)/2;
        return min(query(2*node,l,m,ql,qr),query(2*node+1,m+1,r,ql,qr));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi p(n); for(auto &x : p) cin >> x;
    vi c(n); for(auto &x : c) cin >> x;
    ll m; cin >> m;
    vi tp(m); for(auto &x : tp) cin >> x;
    vi tc(m); for(auto &x : tc) cin >> x;
    vi d(m); for(auto &x : d) cin >> x;
    vi res(m);

    vector<vector<ll>> v1; for(ll i=0; i<n; i++) v1.push_back({p[i],c[i]});
    vector<vector<ll>> v2; for(ll i=0; i<n; i++) v2.push_back({c[i],p[i]});
    sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
    vi prefminv1(n); prefminv1[0] = v1[0][1]; for(ll i=1; i<n; i++) prefminv1[i] = min(prefminv1[i-1],v1[i][1]);
    vi prefminv2(n); prefminv2[0] = v2[0][1]; for(ll i=1; i<n; i++) prefminv2[i] = min(prefminv2[i-1],v2[i][1]);
    vi suffminv1(n); suffminv1[n-1] = v1[n-1][1]; for(ll i=n-2; i>=0; i--) suffminv1[i] = min(suffminv1[i+1],v1[i][1]);
    vi suffminv2(n); suffminv2[n-1] = v2[n-1][1]; for(ll i=n-2; i>=0; i--) suffminv2[i] = min(suffminv2[i+1],v2[i][1]);

    vi sums(n); for(ll i=0; i<n; i++) sums[i] = v1[i][0]+v1[i][1];
    SegTree st(n);
    st.build(1,0,n-1,sums);

    for(ll i=0; i<m; i++){
        ll currtp = tp[i], currtc = tc[i], currd = d[i];

        ll res1 = LLONG_MAX;
        auto it1 = lower_bound(v1.begin(),v1.end(),currtp,[](vector<ll>&row, ll val){return row[0]<val;});
        if(it1!=v1.begin()){
            it1--;
            ll index = it1 - v1.begin();
            ll temp = prefminv1[index];
            if(temp >= currtc && temp < currtc + currd) res1 = temp;
            else if(temp >= currtc + currd) res1 = currtc + currd; 
            else if(temp < currtc) res1 = 0;
        }

        ll res2 = LLONG_MAX;
        auto it2 = lower_bound(v2.begin(),v2.end(),currtc,[](vector<ll>&row, ll val){return row[0]<val;});
        if(it2!=v2.begin()){
            it2--;
            ll index = it2 - v2.begin();
            ll temp = prefminv2[index];
            if(temp >= currtp && temp < currtp + currd) res2 = temp;
            else if(temp >= currtp + currd) res2 = currtp + currd; 
            else if(temp < currtp) res2 = 0;
        }

        ll res3 = LLONG_MAX;
        auto it3 = lower_bound(v1.begin(),v1.end(),currtp+currd,[](vector<ll>&row, ll val){return row[0]<val;});
        if(it3!=v1.end()){        
            ll index = it3 - v1.begin();
            ll temp = suffminv1[index];
            ll ip = currtp + currd;
            if(temp < currtc) res3 = ip;
            else if(temp < currtc + currd) res3 = ip + temp;
            else res3 = ip + currtc + currd;
        }

        ll res4 = LLONG_MAX;
        auto it4 = lower_bound(v2.begin(),v2.end(),currtc+currd,[](vector<ll>&row, ll val){return row[0]<val;});
        if(it4!=v2.end()){
            ll index = it4 - v2.begin();
            ll temp = suffminv2[index]; 
            ll ic = currtc + currd;   
            if(temp < currtp) res4 = ic + 0;
            else if(temp < currtp + currd) res4 = ic + temp;
            else res4 = ic + currtp + currd;
        }

        ll res5 = LLONG_MAX;

        res[i] = min({res1,res2,res3,res4});
        auto itl = lower_bound(v1.begin(),v1.end(),currtp,[](vector<ll>&row, ll val){return row[0]<val;});
        auto itr = lower_bound(v1.begin(),v1.end(),currtp+currd,[](vector<ll>&row, ll val){return row[0]<val;});
        if(itl!=v1.end()){
            ll l = itl - v1.begin(), r = itr - v1.begin() - 1;
            if(l<=r) res5 = st.query(1,0,n-1,l,r);
        }

        res[i] = min({res1,res2,res3,res4,res5});
    }
    for(auto a : res) cout << a << "\n";
}