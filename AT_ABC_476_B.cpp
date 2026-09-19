#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        string s,t; cin >> s >> t;
        bool flag = true;
        for(ll i=0; i<n; i++){
            if(s[i]==t[i]) continue;
            if(t[i]=='*') continue;
            flag = false;
            break;
        }
        cout << (flag ? "Yes" : "No");
    }
}