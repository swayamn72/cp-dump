#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll maxn = 2e5+1;
    vi spf(maxn);
    for(ll i=0; i<maxn; i++) spf[i] = i;
    for(ll i=2; i<maxn; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<maxn; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    // for(ll i=0; i<20; i++) cout << spf[i] << " ";

    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    
    vector<vector<ll>> v(maxn);
    for(auto a : arr){
        while(a>1){
            ll p = spf[a];
            ll count = 0;
            while(a%p==0){
                a/=p;
                count++;
            }
            v[p].push_back(count);
        }
    }
    ll res = 1;
    for(ll i=2; i<maxn; i++){
        if(v[i].size()<n-1) continue;
        if(v[i].size()==n-1){
            sort(v[i].begin(),v[i].end());
            ll c = v[i][0];
            for(ll j=0; j<c; j++){
                res *= i;
            }
        }
        if(v[i].size()==n){
            sort(v[i].begin(),v[i].end());
            ll c = v[i][1];
            for(ll j=0; j<c; j++){
                res *= i;
            }
        }
    }
    cout << res;

}