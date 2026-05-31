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
        ll n,x,k; cin >> n >> x >> k;
        string s; cin >> s;        
        ll res = 0;
        
        ll bufferfore = 0;
        ll totaltable = x;
        ll remainingi = 0;

        ll aingroup = 0;

        for(auto a : s){
            if(a=='I'){
                if(totaltable>0){
                    res++;
                    totaltable--;
                    bufferfore += (k-1);
                }else{
                    remainingi++;
                }
            }else if(a=='E'){
                if(bufferfore>0){
                    res++;
                    bufferfore--;
                }else{
                    if(aingroup>0 && totaltable>0){
                        aingroup--;
                        totaltable--;
                        bufferfore += (k-1);
                        res++;
                    }
                }
            }else{
                if(bufferfore>0){
                    res++;
                    bufferfore--;
                    aingroup++;
                }else if(totaltable>0){
                    totaltable--;
                    res++;
                    bufferfore += (k-1);
                }
            }
        }
        

        cout << res << "\n";
    }
}