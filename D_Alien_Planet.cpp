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
    cin >> t;
    while(t--){
        ll k; cin >> k;
        if(k==1){
            cout << 1 << "\n";
            continue;
        }
        vector<pair<ll,ll>> res;  
        auto dfs = [&](auto &&self, ll x, ll d, pair<ll,ll> p)->void{
            if(x==k){
                res.push_back(p);
                return;
            }
            ll pow2 = 1LL<<(d-1);
            ll gap = k-x;
            if(gap%pow2!=0) return;
            ll val = gap/pow2;
            val = abs(val);
            if(val%2){
                if(x>pow2){
                    self(self,x-pow2,d+1,{p.first,p.second+1});
                }
            }else{
                self(self,x,d+1,{p.first,p.second+1});
                self(self,x+(1LL<<d),d+1,{p.first,p.second+1});
            }
        };
        dfs(dfs,1,1,{1,0});
        if(res.empty()){
            cout << 0 << "\n";
            continue;
        }
        ll maxden = 0;
        for(auto a : res) maxden = max(maxden,a.second);
        ll num = 0;
        for(auto a : res){
            ll temp = 1;
            for(ll i=0; i<maxden-a.second; i++) temp *= 3;
            num += temp;
        }
        while(num>0 && num%3==0){
            num/=3; maxden--;
        }
        if(num==0) maxden = 0;
        cout << (num+maxden)%mod << "\n";
    }
} 