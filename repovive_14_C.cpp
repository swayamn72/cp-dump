#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,q; cin >> n >> q;
    string s; cin >> s;
    vi pref(n+1,0);
    vi pref0(n+1,0), pref1(n+1,0);
    for(ll i=1; i<n; i++){
        pref[i] = pref[i-1];
        pref0[i] = pref0[i-1];
        pref1[i] = pref1[i-1];
        if(s[i-1]=='0') pref0[i]++;
        if(s[i-1]=='1') pref1[i]++;
        if((s[i-1]==s[i])) pref[i]++;
    }
    pref[n] = pref[n-1];
    pref0[n] = pref0[n-1];
    pref1[n] = pref1[n-1];
    // for(auto a : pref) cout << a << " ";
    // cout << "\n";
    // for(auto a : pref1) cout << a << " ";
    // cout << "\n";
    // for(auto a : pref0) cout << a << " ";
    // cout << "\n";
    while(q--){
        ll l,r; cin >> l >> r;
        ll sum = pref[r] - pref[l-1];
        if(((pref1[r]-pref1[l-1])==0) || ((pref0[r]-pref0[l-1])==0)){
            cout << sum << "\n";
            continue;
        }
        ll len = r-l+1;
        if(sum==len-2){
            cout << max(0LL,sum-1) << "\n";
        }else{
            cout << max(0LL,sum-2) << "\n";
        }
    }
}