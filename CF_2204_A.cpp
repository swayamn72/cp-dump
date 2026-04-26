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
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='L') break;
            else ans = i+1;
        }        
        cout << ans+1 << "\n";
    }
}