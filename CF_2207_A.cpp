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
       string s; cin >> s;
       ll count = 0;
       ll maxval;
       for(auto a : s) if(a=='1') count++;
       maxval = count;
       for(ll i=1; i<n-1; i++){
            if(s[i]=='0' && s[i-1]=='1' && s[i+1]=='1'){
                s[i] = '1'; maxval++;
            }
       } 
       ll minval = maxval;
       ll curr = 0;
       for(ll i=0; i<n; i++){
        if(s[i]=='1'){
            curr++;
        }else{
            minval -= (curr-1)/2;
            curr = 0;
        }
       }
       minval -= (curr-1)/2;
       cout << minval << " " << maxval << "\n";
    }
}