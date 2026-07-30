#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n = s.size();
    ll res = 0;
    for(ll i=0; i<n; i++){
        ll count = 0;
        for(ll j=0; j<n; j++){
            if(i-j<0 || i+j>=n) break;
            if(s[i-j]!=s[i+j]) count++;
            if(count>1) break;
            res++;
        }
    }
    for(ll i=0; i<n-1; i++){
        ll count = 0;
        for(ll j=0; j<n; j++){
            if(i-j<0 || i+j+1>=n) break;
            if(s[i-j]!=s[i+j+1]) count++;
            if(count>1) break;
            res++;
        }
    }
    cout << res;
}