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
        ll n; cin >> n;
        string s; cin >> s;
        ll x=0,y=0; 
        for(auto a : s){
            if(a=='N') y++;
            else if(a=='S') y--;
            else if(a=='W') x--;
            else x++;
        }        
        if(x%2 || y%2){
            cout << "NO" << "\n";
            continue;
        }
        vector<ll> turn = {0,0,1,1};
        string res = "";
        bool flag1 = false, flag2 = false;
        for(auto a : s){
            ll idx = 0;
            if(a=='S') idx=1;
            else if(a=='E') idx=2;
            else if(a=='W') idx=3;
            if(turn[idx]==1){
                res += 'R';
                flag1 = true;
            }else{
                res += 'H';
                flag2 = true;
            }
            turn[idx] = 1 - abs(turn[idx]);
        }
        if(!flag1 || !flag2){
            cout << "NO" << "\n";
            continue;
        }
        cout << res << "\n";
    }
}