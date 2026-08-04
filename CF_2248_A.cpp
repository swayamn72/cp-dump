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
        string s; cin >> s;
        ll n = s.size();
        vector<bool> vis(n,true);
        for(ll i=0; i<n; i++){
            if(s[i]=='1'){
                vis[i] = false;
                break;
            }
        }
        for(ll i=0; i<n; i++){
            if(s[i]=='0'){
                vis[i] = false;
                break;
            }
        }
        string res = "";
        for(ll i=0; i<n; i++){
            if(vis[i]) res += s[i];
        }
        cout << res << "\n";
    }
}