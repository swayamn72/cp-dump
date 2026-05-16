#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n = s.size();
    ll res = 0;
    for(ll i=0; i<n; i++){
        if(s[i]=='C'){
            ll behind = i, front = n - (i+1);
            ll minv = min(behind,front);
            ll val = minv;
            res += (val+1);
        }
    }
    cout << res;
}