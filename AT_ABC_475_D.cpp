#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> isprime(1e7,true);
    isprime[0] = isprime[1] = false;
    for(ll i=2; i<1e7; i++){
        if(isprime[i]){
            for(ll j=i*i; j<1e7; j+=i){
                isprime[j] = false;
            }
        }
    }

    ll t=1; 
    // cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = s.size();
        ll a = 1;
        for(ll i=0; i<n-1; i++) a*=10;
        ll b = a*10-1;
        
        bool flag = false;
        ll res;
        auto check = [&](ll i)->bool{
            vector<bool> used(10,false);
            vector<char> temp(26,'#');
            string ss = to_string(i);
            for(ll j=0; j<n; j++){
                char ch = s[j];
                if(temp[ch-'a']=='#'){
                    if(used[ss[j]-'0']) return false;
                    temp[ch-'a'] = ss[j];
                    used[ss[j]-'0'] = true;
                }else{
                    if(temp[ch-'a']!=ss[j]){
                        return false;
                    }
                }
            }
            return true;
        };
        for(ll i=a; i<=b; i++){
            if(!isprime[i]) continue;
            bool valid = check(i);
            if(!valid) continue;
            res = i;
            flag = true;
            break;
        }

        cout << (flag ? res : -1);
    }
} 