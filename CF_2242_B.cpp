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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        bool flag = false;
        vi pref1(n+1,0), pref2(n+1,0), pref3(n+1,0);
        for(ll i=0; i<n-1; i++){
            pref1[i+1] = pref1[i] + (arr[i]==1);
            pref2[i+1] = pref2[i] + (arr[i]==2);
            pref3[i+1] = pref3[i] + (arr[i]==3);
        }
        ll idx = LLONG_MAX;
        for(ll i=1; i<n; i++){
            ll val = i - 2*pref3[i];
            if(val>=idx){
                flag = true;
                break;
            }
            if(i <= 2*pref1[i]){
                idx = min(idx,val);
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";

    }
}