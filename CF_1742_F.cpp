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
        ll q; cin >> q;
        vi s1(26,0); s1[0] = 1;
        vi s2(26,0); s2[0] = 1;
        while(q--){
            ll d,k; cin >> d >> k;
            string x; cin >> x;
            vi v(26,0);
            for(auto a : x){
                v[a-'a'] += k;
            }
            auto check = [&]()->bool{
                for(ll i=1; i<26; i++){
                    if(s2[i]>0) return true;
                }
                for(ll i=1; i<26; i++){
                    if(s1[i]>0) return false;
                }
                return s1[0]<s2[0];

            };
            if(d==1){
                for(ll i=0; i<26; i++){
                    s1[i] += v[i];
                }
                if(check()){
                    cout << "YES" << "\n";
                }else{
                    cout << "NO" << "\n";
                }
            }else{
                for(ll i=0; i<26; i++){
                    s2[i] += v[i];
                }
                if(check()){
                    cout << "YES" << "\n";
                }else{
                    cout << "NO" << "\n";
                }
            }
        }        
    }
}