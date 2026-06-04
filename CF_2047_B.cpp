#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        map<char,ll> mp; for(auto a : s) mp[a]++;
        if(mp.size()==1){
            cout << s << "\n";
            continue;
        }   
        ll minv = LLONG_MAX; char minch = '#';     
        for(auto a : mp){
            if(a.second<minv){
                minv = a.second;
                minch = a.first;
            }
        }
        char maxch = '#'; ll maxv = 0;
        for(auto a : mp){
            if(a.second>maxv && a.first!=minch){
                maxv = a.second;
                maxch = a.first;
            }
        }
        for(auto &a : s){
            if(a==minch){
                a = maxch;
                break;
            }
        }
        cout << s << "\n";
    }
}