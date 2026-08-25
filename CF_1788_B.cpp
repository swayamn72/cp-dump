#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t-- > 0) {
        ll n;
        cin >> n;
        string s = to_string(n);
        string ans = "", ans2 = "";
        bool flag = false;
        for(auto a : s){
            ll num = a - '0';
            if(num%2==0){
                ll val = num/2;
                ans += (val+'0');
                ans2 += (val+'0');
            }else{
                flag = !flag;
                ll val1 = num/2;
                ll val2 = val1+1;
                if(flag){
                    ans += (val1+'0');
                    ans2 += (val2+'0');
                }else{
                    ans += (val2+'0');
                    ans2 += (val1+'0');
                }
            }
        }
        ll res1 = stoll(ans), res2 = stoll(ans2);
        cout << res1 << " " << res2 << "\n";
    }
    return 0;
} 