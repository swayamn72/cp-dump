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
        ll n,k; cin >> n >> k;
        if(k==n-1){
            cout << -1 << "\n";
            continue;
        }
        
        ll blocks = n-k;
        
        ll zeros = n/2;
        ll ones = n - zeros;

        ll zblock = blocks/2;
        ll oblock = blocks - zblock;


        string res = "";
        bool used1 = false;
        bool used2 = false;
        for(ll i=0; i<blocks; i++){
            if(i%2==0){
                if(!used1){
                    used1 = true;
                    ll num = ones - oblock + 1;
                    for(int j=0; j<num; j++) res += '1';
                }else{
                    res += '1';
                }
            }else{
                if(!used2){
                    used2 = true;
                    ll num = zeros - zblock + 1;
                    for(int j=0; j<num; j++) res += '0';
                }else{
                    res += '0';
                }
            }
        }
        cout << res << "\n";
    }
}