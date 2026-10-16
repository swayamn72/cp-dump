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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi odd,even;
        for(ll i=0; i<n; i++){
            if(i%2) odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }        
        vi veven(n), vodd(n);
        map<ll,ll> mpeven, mpodd;
        ll res = 0;
        for(ll i=0; i<even.size()-1; i++){
            if(i==even.size()-2){
                break;
            }
            veven[i] = even[i]+even[i+1]-even[i+2];
            res += mpeven[veven[i]];
            if(i>1) mpeven[veven[i-2]]++;
        }
        
        
        for(ll i=0; i<odd.size()-1; i++){
            if(i==odd.size()-2){
                break;
            }
            vodd[i] = odd[i]+odd[i+1]-odd[i+2];
            res += mpodd[vodd[i]];
            if(i>1) mpodd[vodd[i-2]]++;
        }
        mpeven.clear(); mpodd.clear();
        for(ll i=0; i<even.size()-2; i++) mpeven[veven[i]]++;
        for(ll i=0; i<odd.size()-2; i++) mpodd[vodd[i]]++;
        for(auto a : mpeven) res += a.second * mpodd[a.first];
        
        
        cout << res << "\n";
    }
}