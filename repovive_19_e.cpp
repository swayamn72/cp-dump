#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q; cin >> n >> q;
    string s; cin >> s;

    ll totalplus = 0;
    for(auto a : s) if(a=='+') totalplus++;
    ll totalminus = n - totalplus;

    ll curr = 0;

    vi res(n);
    for(ll i=0; i<n; i++){
        if(s[i]=='+') curr++;

        if(s[i]=='+'){
            ll leftplus = curr-1;
            ll leftminus = i+1 - curr;
            ll rightminus = totalminus - leftminus;

            if(rightminus>leftplus){
                res[i] = 0;
            }else{
                res[i] = 1;
            }
        }else{
            ll leftplus = curr;
            ll leftminus = i+1-curr;
            ll rightminus = totalminus - leftminus;

            if(rightminus>=leftplus){
                res[i] = 0;
            }else{
                res[i] = 1;
            }
        }
    }

    vi pref(n+1); pref[0] = 0;
    for(ll i=1; i<=n; i++){
        pref[i] = pref[i-1];
        if(res[i-1]==0) pref[i]++;
    }
    // for(auto a : res) cout << a << " ";
    // cout << "\n";
    while(q--){
        ll l,r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }
}