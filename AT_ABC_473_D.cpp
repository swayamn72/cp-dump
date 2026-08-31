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
        ll n,k; cin >> n >> k;

        // vector<vector<ll>> res;
        vector<ll> temp;
        auto func = [&](auto &&self, ll i, ll sum)->void{
            if(i==n){
                ll rem = k-sum;
                if(rem%n==0){
                    for(auto &a : temp) cout << a << " ";
                    cout << rem/n << "\n";
                }
                return;
            }
            for(ll j=0; sum+j*i<=k; j++){
                temp.push_back(j);
                self(self,i+1,sum+i*j);
                temp.pop_back();
            }
        };
        func(func,1,0);
        // sort(res.begin(),res.end());
        // for(auto &a : res){
        //     for(auto &b : a) cout << b << " ";
        //     cout << "\n";
        // }
    }
} 