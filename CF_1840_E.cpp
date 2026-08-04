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
        string s1,s2; cin >> s1 >> s2;
        ll time, q; cin >> time >> q;
        ll n = s1.size();
        ll count = 0;
        vector<bool> isequal(n,false);
        map<ll,vi> mp;
        for(ll i=0; i<n; i++){
            if(s1[i]==s2[i]){
                isequal[i] = true;
                count++;
            }
        }
        ll i = 0;
        while(q--){
            ll type; cin >> type;
            for(auto a : mp[i]){
                if(s1[a]==s2[a]) count++;
            }
            mp.erase(i);
            if(type==1){
                ll x; cin >> x; x--;
                mp[i+time].push_back(x);
                if(s1[x]==s2[x]) count--;
            }else if(type==2){
                ll a,b,c,d; cin >> a >> b >> c >> d;
                b--; d--;
                if(a==c){
                    if(a==1){
                        ll curr = 0;
                        if(s1[b]==s2[b]) curr++;
                        if(s1[d]==s2[d]) curr++;
                        swap(s1[b],s1[d]);
                        ll next = 0;
                        if(s1[b]==s2[b]) next++;
                        if(s1[d]==s2[d]) next++;

                        count -= (curr-next);
                    }else{
                        ll curr = 0;
                        if(s1[b]==s2[b]) curr++;
                        if(s1[d]==s2[d]) curr++;
                        swap(s2[b],s2[d]);
                        ll next = 0;
                        if(s1[b]==s2[b]) next++;
                        if(s1[d]==s2[d]) next++;

                        count -= (curr-next);
                    }
                }else{
                    if(a==1){
                        ll curr = 0;
                        if(s1[b]==s2[b]) curr++;
                        if(s1[d]==s2[d]) curr++;
                        swap(s1[b],s2[d]);
                        ll next = 0;
                        if(s1[b]==s2[b]) next++;
                        if(s1[d]==s2[d]) next++;

                        count -= (curr-next);
                    }else{
                        ll curr = 0;
                        if(s1[b]==s2[b]) curr++;
                        if(s1[d]==s2[d]) curr++;
                        swap(s2[b],s1[d]);
                        ll next = 0;
                        if(s1[b]==s2[b]) next++;
                        if(s1[d]==s2[d]) next++;

                        count -= (curr-next);
                    }
                }
            }else{
                if(count+mp.size() == n){
                    cout << "YES" << "\n";
                }else{
                    cout << "NO" << "\n";
                }
            }
            i++;
        }
    }
}