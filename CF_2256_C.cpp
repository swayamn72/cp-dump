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
        n*=2;
        string s; cin >> s;
        ll red = 0, blue = 0;
        for(ll i=0; i<n-1; i++){
            if(s[i]=='1' && s[i+1]=='1'){
                if(i%2==0) red++;
                else blue++;
            }else if(s[i]=='1'){
                if(i%2) red++;
                else blue++;
            }
        }
        if(s[n-1]=='1' && s[0]=='1'){
            if((n-1)%2==0) red++;
            else blue++;
        }else if(s[n-1]=='1'){
            if((n-1)%2) red++;
            else blue++;
        }   
        cout << blue << " " << red << "\n";     
    }
}