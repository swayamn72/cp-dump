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
        string s; cin >> s;
        if(n%2==0){
            vi even(26,0), odd(26,0);
            for(ll i=0; i<n; i++){
                if(i%2) odd[s[i]-'a']++;
                else even[s[i]-'a']++;
            }
            ll maxv1 = *max_element(even.begin(),even.end());
            ll maxv2 = *max_element(odd.begin(),odd.end());
            cout << n-maxv1-maxv2 << "\n";
            continue;
        }
        if(n<=3){
            cout << 1 << "\n";
            continue;
        }
        vector<vector<ll>> pref(n,vi(26,0));
        for(ll i=0; i<n; i++){
            pref[i][s[i]-'a']++;
            if(i>1){
                for(ll j=0; j<26; j++){
                    pref[i][j] += pref[i-2][j];
                }
            }
        }
        vector<vector<ll>> suff(n,vi(26,0));
        for(ll i=n-1; i>=0; i--){
            suff[i][s[i]-'a']++;
            if(i<n-2){
                for(ll j=0; j<26; j++){
                    suff[i][j] += suff[i+2][j];
                }
            }
        }
        ll maxv = 0;
        for(ll i=1; i<n-1; i++){
            vi one = pref[i-1];
            vi two = suff[i+1];
            if(i-2>=0){
                for(ll j=0; j<26; j++){
                    two[j] += pref[i-2][j];
                }
            }
            if(i+2<n){
                for(ll j=0; j<26; j++){
                    one[j] += suff[i+2][j];
                }
            }
            ll maxv1 = *max_element(one.begin(),one.end());
            ll maxv2 = *max_element(two.begin(),two.end());
            maxv = max(maxv, maxv1+maxv2);
        }
        ll maxv1 = *max_element(pref[n-3].begin(),pref[n-3].end());
        ll maxv2 = *max_element(pref[n-2].begin(),pref[n-2].end());
        maxv = max(maxv, maxv1+maxv2);
        maxv1 = *max_element(suff[1].begin(),suff[1].end());
        maxv2 = *max_element(suff[2].begin(),suff[2].end());
        maxv = max(maxv, maxv1+maxv2);
        cout << n-maxv << "\n";
    }
}