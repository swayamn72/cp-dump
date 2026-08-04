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
        ll n,q; cin >> n >> q;
        string a,b; cin >> a >> b;

        vi pref0(n+1,0);
        vi pref1(n+1,0);
        vi pref01(n+1,0);
        vi pref10(n+1,0);

        for(ll i=0; i<n; i++){
            pref0[i+1] = pref0[i];
            pref1[i+1] = pref1[i];
            pref01[i+1] = pref01[i];
            pref10[i+1] = pref10[i];
            if(a[i]=='0' && b[i]=='0') pref0[i+1]++;
            else if(a[i]=='1' && b[i]=='1') pref1[i+1]++;
            else if(a[i]=='0') pref01[i+1]++;
            else pref10[i+1]++;
        }

        while(q--){
            ll l,r; cin >> l >> r;
            ll ones = pref1[r] - pref1[l-1];
            ll zeros = pref0[r] - pref0[l-1];
            ll buffer = ones + zeros;

            ll zeroones = pref01[r] - pref01[l-1];
            ll onezeros = pref10[r] - pref10[l-1];

            ll minv = min(zeroones,onezeros);
            zeroones -= minv;
            onezeros -= minv;

            ll val = zeroones + onezeros;
            if(val>buffer){
                cout << "NO" << "\n";
            }else{
                cout << "YES" << "\n";
            }
        }        
    }
}