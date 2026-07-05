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

    vi pref11(n+1,0);
    vi pref00(n+1,0);
    vi pref(n+1,0);
    for(ll i=1; i<n; i++){
        pref[i+1] = pref[i];
        pref11[i+1] = pref11[i];
        pref00[i+1] = pref00[i];
        if(s[i]==s[i-1]){
            pref[i+1]++;
            if(s[i]=='0') pref00[i+1]++;
            else pref11[i+1]++;
        }
    }
    while(q--){
        ll l,r; cin >> l >> r;
        if(l==r){
            cout << 0 << "\n";
            continue;
        }
        ll res = pref[r] - pref[l];
        ll z00 = pref00[r] - pref00[l];
        ll z11 = pref11[r] - pref11[l];
        if(z00>0 && z11>0){
            cout << res-2 << "\n";
        }else if(z00>0 || z11>0){
            if(z00>0){
                if(s[l-1]=='1' || s[r-1]=='1'){
                    cout << res-1 << "\n";
                }else{
                    cout << res << "\n";
                }
            }else{
                if(s[l-1]=='0' || s[r-1]=='0'){
                    cout << res-1 << "\n";
                }else{
                    cout << res << "\n";
                }
            }
        }else{
            cout << 0 << "\n";
        }
    }
}