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
        string s; cin >> s;
        ll n = s.size();
        ll i = 0;
        vi suff(n);
        suff[n-1] = (s[n-1]=='0' ? 1 : 0);
        for(ll i=n-2; i>=0; i--){
            suff[i] = suff[i+1];
            if(s[i]=='0') suff[i]++;
        }
        string res = "";
        while(i<n){
            if(s[i]=='0'){
                res += '1';
                while(i<n && s[i]=='0') i++;
            }else{
                if(suff[i]>0){
                    res += '0';
                    i++;
                }else{
                    res += '0';
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}