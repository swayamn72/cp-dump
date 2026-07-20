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
        ll unique = 0;
        vi freq(26,0);
        for(auto a : s){
            freq[a-'a']++;
            if(freq[a-'a']==1) unique++;
        }
        vector<pair<ll, ll>> sortedfreq(26);
        for(ll j=0; j<26; j++){
            sortedfreq[j] = {freq[j],j}; 
        }
        sort(sortedfreq.rbegin(), sortedfreq.rend());
        // i : no. of char
        // div : freq of each
        string ss; 
        ll res = LLONG_MAX;
        for(ll i=1; i<=26; i++){
            if(n%i!=0) continue;
            ll div = n/i;
            
            vi v(26,0);
            
            vector<pair<ll,ll>> pending;
            for(ll j=0; j<i; j++){
                ll idx = sortedfreq[j].second;
                v[idx] = div;
                if(freq[idx]<div){
                    pending.push_back({idx,div-freq[idx]});
                }
            }
            ll ans = 0;
            string temp = s;
            vi have(26,0);
            for(ll j=0; j<n; j++){
                auto a = temp[j];
                ll idx = a - 'a';
                if(v[idx]>0 && have[idx]<v[idx]){
                    have[idx]++;
                    continue;
                }
                ll val = pending.back().first;
                ans++;
                temp[j] = val + 'a';
                if(pending.back().second==1) pending.pop_back();
                else pending.back().second--;
            }
            if(ans<res){
                res = ans;
                ss = temp;
            }
        }    
        cout << res << "\n";
        cout << ss << "\n";    
    }
}