#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        for(ll i=0; i<n-k; i++){
            if(s[i]=='1'){
                s[i] = '0';
                if(s[i+k]=='1') s[i+k]='0';
                else s[i+k] = '1';
            }
        }
        bool flag = true;
        for(auto a : s) if(a=='1') flag = false;
        cout << (flag ? "YES" : "NO") << "\n";
    }
}