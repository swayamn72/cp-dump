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
        string s; cin >> s;
        map<char,ll> mp; for(auto a : s) mp[a]++;
        priority_queue<pair<ll,char>> pq;
        for(auto a : mp) pq.push({a.second,a.first});
        string res = "";
        bool flag = true;
        char curr = '#';
        while(!pq.empty()){
            auto a = pq.top(); pq.pop();
            if(a.second != curr){
                res += a.second;
                curr = a.second;
                if(a.first!=1) pq.push({a.first-1,a.second});
            }else{
                if(pq.empty()){
                    flag = false;
                    break;
                }else{
                    auto b = pq.top(); pq.pop();
                    res += b.second;
                    curr = b.second;
                    if(a.first!=0) pq.push({a.first,a.second});
                    if(b.first!=1) pq.push({b.first-1,b.second});
                }
            }
        }
        if(!flag){
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
        cout << res << "\n";
    }
}