#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        ll zeros = 0;
        for(auto a : arr) if(!a) zeros++;

        if(zeros==0){
            cout << "YES" << "\n";
            string res = string(n,'A');
            cout << res << "\n";
            continue;
        }
        if(zeros==1){
            cout << "NO" << "\n";
            continue;
        }
        map<ll,vi> mp;
        for(ll i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        string res(n,'.');
        bool flag = false;
        for(auto a : mp[0]){
            if(flag) res[a] = 'B';
            else res[a] = 'A';
            flag = !flag; 
        }
        for(ll i=0; i<n; i++){
            if(res[i]=='.') res[i] = 'C';
        }
        cout << "YES" << "\n";
        cout << res << "\n";
    }
} 