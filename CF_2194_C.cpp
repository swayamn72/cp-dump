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
        ll n,k; cin >> n >> k;
        vector<string> arr(k); for(auto &x : arr) cin >> x;
        vector<ll> divisors;
        for(ll i=1; i<=n; i++) if(n%i==0) divisors.push_back(i);
        vector<vector<ll>> v(n, vector<ll>(26,0));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<k; j++){
                string s = arr[j];
                v[i][arr[j][i]-'a']=1;
            }
        }
        string res = "";
        for(auto d : divisors){
            bool flag = true;
            string ans = "";
            for(ll i=0; i<d; i++){
                vector<ll> temp = v[i];
                for(ll j=i+d; j<n; j+=d){
                    for(ll c=0; c<26; c++){
                        temp[c] = temp[c]&v[j][c];
                    }
                }
                bool tempflag = false;
                for(ll c=0; c<26; c++){
                    if(temp[c]==1){
                        ans += (c+'a');
                        tempflag = true;
                        break;
                    }
                }
                if(!tempflag){
                    flag = false;
                    break;
                } 
                
            }
            if(flag){
                for(ll i=0; i<n/d; i++) res += ans;
                break;
            }
        }
        cout << res << "\n";
    }
}