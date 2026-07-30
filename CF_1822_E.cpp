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
        map<char,ll> mp; for(auto a : s) mp[a]++;
        ll maxv = 0;
        for(auto a : mp) maxv = max(maxv,a.second);
        if(n%2 || maxv>n/2){
            cout << -1 << "\n";
            continue;
        }        
        ll count = 0;
        ll ptr = 0, ptr2 = n-1;
        map<char,ll> mp2;
        maxv = 0;
        while(ptr<ptr2){
            if(s[ptr]==s[ptr2]){
                count++;
                mp2[s[ptr]]++;
                maxv = max(maxv,mp2[s[ptr]]);
            } 
            ptr++; ptr2--;
        }
        ll res = max(maxv,(count+1)/2);
        cout << res << "\n";
    }
}