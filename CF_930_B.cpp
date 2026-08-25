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
    // cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = s.size();
        vector<vi> pos(26);
        for(ll i=0; i<n; i++){
            pos[s[i]-'a'].push_back(i);
        }
        ll wins = 0;
        for(ll c=0; c<26; c++){
            if(pos[c].empty()) continue;
            ll maxunique = 0;
            for(ll offset=1; offset<n; offset++){
                vi freq(26,0);
                for(auto p : pos[c]){
                    ll nextidx = (p+offset)%n;
                    freq[s[nextidx]-'a']++;
                }
                ll curunique = 0;
                for(auto count : freq){
                    if(count==1) curunique++;
                }
                maxunique = max(maxunique,curunique);
            }
            wins += maxunique;
        }
        cout << fixed << setprecision(6) << (double)wins/n;
    }
} 