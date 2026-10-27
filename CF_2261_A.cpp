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
        ll n; cin >> n;
        string s; cin >> s;
        ll minv = LLONG_MAX, maxv = LLONG_MIN;
        for(ll i=0; i<n; i++){
            if(s[i]=='1'){
                minv = min(minv,i+1);
                maxv = max(maxv,i+1);
            }
        }
        vi ss,kk;
        for(ll i=0; i<n; i++){
            if(s[i]=='1') ss.push_back(i);
            else kk.push_back(i);
        }
        if(ss.size()==1){
            cout << 0 << "\n";
            continue;
        }        
        if(ss.size()>2){
            cout << maxv-minv << "\n";
            continue;
        }
        cout << 1 << "\n";
    }
}