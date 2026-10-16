#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = s.size();
        ll soloones = 0, solozeros = 0;
        for(ll i=1; i<n-1; i++){
            if(s[i]=='0'&&s[i-1]=='1'&&s[i+1]=='1'){
                soloones++;
            }
            if(s[i]=='1'&&s[i-1]=='0'&&s[i+1]=='0'){
                solozeros++;
            }
        }    
        ll res = 1;
        if(soloones||solozeros) res++;
        ll temp = 1, maxv = 1;
        for(ll i=1; i<n; i++){
            if(s[i]==s[i-1]){
                temp++;
                maxv = max(maxv,temp);
            }else{
                temp = 1;
            }
        }
        if(maxv>2) res++;
        cout << res << "\n";
    }
}