#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n = s.size();
    ll temp = 1;
    ll res = 0;
    for(ll i=1; i<n; i++){
        if(s[i]!=s[i-1]){
            temp++;
        }else{
            ll toadd = (temp*(temp+1)/2) % mod;
            res = (res+toadd)%mod;
            temp = 1;
        }
    }
    ll toadd = (temp*(temp+1)/2) % mod;
    res = (res+toadd)%mod;
    cout << res;
}