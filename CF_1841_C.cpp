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
        string s; cin >> s;
        ll n = s.size();
        
        auto func = [](string &a)->ll{
            vi freq(5,0);
            for(auto b : a) freq[b-'A']++;
            ll ans = 0;
            for(auto b : a){
                ll val = b - 'A';
                bool pos = true;
                for(ll i=val+1; i<5; i++) if(freq[i]>0) pos = false;
                ll v = 1;
                for(ll i=0; i<val; i++) v*=10;
                if(pos) ans += v;
                else ans -= v;
                freq[val]--;
            }
            return ans;
        };
        
        auto func2 = [&](string &a, ll idx)->ll{
            string temp = a;
            ll ans = LLONG_MIN;
            for(ll i=0; i<5; i++){
                temp[idx] = 'A'+i;
                ans = max(ans,func(temp));
            }
            return ans;
        };

        ll res = func(s);
        vi freq(5,0);
        for(ll i=n-1; i>=0; i--){
            freq[s[i]-'A']++;
            if(freq[s[i]-'A']==1){
                res = max(res,func2(s,i));
            }
        }
        freq.assign(5,0);
        for(ll i=0; i<n; i++){
            freq[s[i]-'A']++;
            if(freq[s[i]-'A']==1) res = max(res,func2(s,i));
        }

        cout << res << "\n";
    }
}