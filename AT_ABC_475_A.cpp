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
    // cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = s.size();
        string res = ""; res += s[0];
        for(ll i=1; i<n; i++){
            res += 'o';
            res += s[i];
        }        
        cout << res;
    }
} 