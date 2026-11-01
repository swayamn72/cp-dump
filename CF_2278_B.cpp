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
        ll r,s,p; cin >> r >> s >> p;
        ll n = r+s+p;
        string res = "";
        if(r>=s && r>=p){
            for(ll i=0; i<n; i++) res += 'P';
        }else if(s>=r && s>=p){
            for(ll i=0; i<n; i++) res += 'R';
        }else{
            for(ll i=0; i<n; i++) res += 'S';
        }     
        cout << res << "\n";   
    }
}