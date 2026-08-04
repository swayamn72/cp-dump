#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; string s; cin >> n >> s;
    ll buffer = 0;
    vi res(n,n);
    
    vi pref(n,0);
    if(s[0]=='o') pref[0] = 1;
    for(ll i=1; i<n; i++){
        pref[i] = pref[i-1];
        if(s[i]=='o') pref[i]++;
    }
    // for(auto a : pref) cout << a << " ";
    for(ll i=0; i<n; i++){
        if(s[i]=='x'){
            res[buffer] = i+1;
            buffer++;
        }
    }
    for(auto a : res) cout << a << "\n";
}