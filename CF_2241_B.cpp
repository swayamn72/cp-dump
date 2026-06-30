#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    auto countdigit = [&](ll n)->ll{
        bool vis[10] = {false};
        while(n>0){
            vis[n%10] = true;;
            n/=10;
        }
        ll count = 0;
        for(ll i=0; i<10; i++) if(vis[i]) count++;
        return count;
    };
    // vi v;
    // queue<ll> q;
    // for(ll i=1; i<=9; i++) q.push(i);
    // while(!q.empty()){
    //     ll curr = q.front();
    //     q.pop();
    //     if(curr>=2) v.push_back(curr);
    //     for(ll j=0; j<=9; j++){
    //         ll num = curr*10 + j;
    //         if(num<=1e7 && countdigit(num)<=2){
    //             q.push(num);
    //         }
    //     }
    // }
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll temp = n;
        ll digits = 0;
        while(temp>0){
            digits++;
            temp/=10;
        }
        ll val = 1;
        for(ll i=0; i<digits; i++){
            val*=10;
        }
        val++;
        cout << val << "\n";
        // if(countdigit(val*n)<=2) cout << "YES" << "\n";
    }
}