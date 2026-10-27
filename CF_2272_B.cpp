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
        string s1,s2; cin >> s1 >> s2;
        vector<vector<char>> grid(2,vector<char>(n));
        for(ll i=0; i<n; i++) grid[0][i] = s1[i];
        for(ll i=0; i<n; i++) grid[1][i] = s2[i];
        ll res = 0;
        
        // bool prev = false;
        // if(grid[0][0]=='f' || grid[1][0]=='f') prev = true;
        // for(ll i=1; i<n; i++){
        //     if(grid[0][i]=='f' && grid[1][i]=='f'){
        //         continue;
        //     }else if(grid[0][i]=='f' || grid[1][i]=='f'){
        //         if(prev){
        //             prev = false;
        //         }else{
        //             prev = true;
        //         }
        //     }else{
        //         if(prev){
        //             res++;
        //             prev = false;
        //         }
        //     }
        // }
        // if(prev) res++;
        ll odd = 0, even = 0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<2; j++){
                if(grid[j][i]=='f'){
                    if((i+j)%2) odd++;
                    else even++;
                }
            }
        }
        res = (even+odd)%2;

        cout << res << "\n";
    }
}