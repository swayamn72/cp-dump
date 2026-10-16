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
        ll a,b,c; cin >> a >> b >> c;
        bool flag = true;
        
        vector<pair<ll,ll>> res;
        ll div3 = c/3;
        ll left = 1;
        left += (div3*3);

        ll temp = 1;
        for(ll i=0; i<div3; i++){
            res.push_back({temp,temp+3});
            res.push_back({temp+1,temp+4});
            res.push_back({temp+2,temp+5});
            temp = temp+6;
        }
        c%=3;
        if(c==2){
            if(a>=2){
                res.push_back({temp,temp+3});
                res.push_back({temp+1,temp+2});
                temp+=4;
                res.push_back({temp,temp+3});
                res.push_back({temp+1,temp+2});
                temp+=4;
                a-=2;
                c-=2;
            }else if(b>=2){
                res.push_back({temp, temp+2});
                res.push_back({temp+1, temp+4});
                res.push_back({temp+3, temp+6});
                res.push_back({temp+5, temp+7});
                temp+=8;
                b-=2;
            }else{
                flag = false;
            }
        }else if(c==1){
            if(a>=1){
                res.push_back({temp,temp+3});
                res.push_back({temp+1,temp+2});
                temp+=4;
                a--;
                c--;
            }else if(b>=2){
                res.push_back({temp, temp+2});
                res.push_back({temp+1, temp+4});
                res.push_back({temp+3, temp+5});
                temp+=6;
                b-=2;
            }else{
                flag = false;
            }
        }
        if(b%2) flag = false;
        while(b>0){
            res.push_back({temp,temp+2});
            res.push_back({temp+1,temp+3});
            temp+=4;
            b-=2;
        }
        while(a>0){
            res.push_back({temp,temp+1});
            temp+=2;
            a--;
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        
        for(auto [x,y] : res) cout << x << " " << y << "\n";
    }
}