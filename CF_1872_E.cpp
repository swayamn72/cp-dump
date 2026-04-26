#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi pref(n+1,0);
        for(ll i=0; i<n; i++){
            pref[i+1] = pref[i]^arr[i];
        }
        string s; cin >> s;
        ll sum0 = 0; ll sum1 = 0;
        for(ll i=0; i<s.size(); i++){
            char a = s[i];
            if(a=='0') sum0^=arr[i];
            else sum1^=arr[i];
        }
        ll m; cin >> m;
        while(m--){
            ll type; cin >> type;
            if(type==1){
                ll l,r; cin >> l >> r;
                ll rangexor = pref[l-1]^pref[r];
                sum0 ^= rangexor; sum1 ^= rangexor;
            }else{
                ll val; cin >> val;
                if(val==0) cout << sum0 << " ";
                else cout << sum1 << " "; 
            }
        }
        cout << endl;
    }
}