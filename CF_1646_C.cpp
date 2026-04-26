#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi powerset;
    ll val = 1;
    powerset.push_back(val);
    while (val <= (LLONG_MAX) / 2)
    {
        powerset.push_back(val * 2);
        val *= 2;
    }
    vi factorialset;
    val = 1;
    ll i = 1;
    while (i <= 20)
    {
        val *= i;
        i++;
        factorialset.push_back(val);
    }
    ll t; cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll res = 0;
        while(n!=0){
            ll l=0; ll r=powerset.size()-1;
            ll val=1;
            while(l<=r){
                ll m = l+(r-l)/2;
                if(powerset[m]<=n){
                    val = max(val, powerset[m]);
                    l++;
                }else{
                    r--;
                }
            }
            l = 0; r = factorialset.size()-1;
            while(l<=r){
                ll m = l + (r-l)/2;
                if(factorialset[m]<=n){
                    val = max(val, factorialset[m]);
                    l++;
                }else{
                    r--;
                }
            }
            n-=val;
            res++;
        }
        cout << res << "\n";
    }
}