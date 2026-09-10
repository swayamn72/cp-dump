#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi pref(n), suff(n);
        for(auto &a : pref) cin >> a;
        for(auto &a : suff) cin >> a;
        bool flag = true;
        if(!is_sorted(pref.rbegin(),pref.rend())) flag = false;
        if(!is_sorted(suff.begin(),suff.end())) flag = false;
        if(pref[n-1]!=suff[0]) flag = false; 
        ll total = pref[n-1];
        for(ll i=0; i<n; i++){
            ll gcdv = gcd(pref[i],suff[i]);
            if(gcdv!=total) flag = false;
        }
        for(ll i=0; i<n-1; i++){
            ll gcdv = gcd(pref[i],suff[i+1]);
            if(gcdv!=total) flag = false;
        }
        for(ll i=1; i<n; i++){
            if(pref[i-1]%pref[i]!=0) flag = false;
        }
        for(ll i=n-2; i>=0; i--){
            if(suff[i+1]%suff[i]!=0) flag = false;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
} 