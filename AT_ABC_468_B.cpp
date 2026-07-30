#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,d; cin >> n >> d;
    string s; cin >> s;
    vector<ll> v(n,0);
    ll prev = -1e9;
    for(ll i=0; i<n; i++){
        if(s[i]=='G'){
            prev = i;
        }
        if((i-prev)>d) v[i]++;
    }
    prev = 1e9;
    for(ll i=n-1; i>=0; i--){
        if(s[i]=='G') prev = i;
        if((prev-i)>d) v[i]++;
    }
    // for(auto a : v) cout << a << " ";
    // cout << "\n";
    ll res = 0;
    for(ll i=0; i<n; i++) if(v[i]==2) res++;
    cout << res;
}