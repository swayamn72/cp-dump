#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        if(k>n/2){
            cout << -1 << "\n";
            continue;
        }        
        ll res = 0;
        for(ll i=0; i<k; i++){
            if(s[i]=='L') res++;
        }
        for(ll i=n-k; i<n; i++){
            if(s[i]=='R') res++;
        }
        cout << res << "\n";
    }
}