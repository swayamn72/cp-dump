#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    map<string, ll> mp;
    for(ll i=0; i<n; i++){
        string s; cin >> s;
        if(mp.find(s)==mp.end()){
            cout << "OK" << "\n";
            mp[s]++;
        }else{
            mp[s]++;
            s += to_string(mp[s]-1);
            cout << s << "\n";
        }
    }
}