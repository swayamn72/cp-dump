#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll a,n; cin >> a >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(arr[0]>arr[1]) swap(arr[0],arr[1]);
        string res = "";
        string num = to_string(n);
        bool flag = false;
        for(int i=0; i<num.size(); i++){
            auto a = num[i];
            if(!flag && (a==arr[0]+'0' || a==arr[1]+'0')){
                res += a;
            }else{
                if(!flag){
                    flag = true;
                    res += arr[1]+'0';
                }else{
                    res += arr[0]+'0';
                }
            }
        }
        string res2 = "";
        flag = false;
        for(int i=0; i<num.size(); i++){
            auto a = num[i];
            if(!flag && (a==arr[0]+'0' || a==arr[1]+'0')){
                res += a;
            }else{
                if(!flag){
                    flag = true;
                    res += arr[0]+'0';
                }else{
                    res += arr[1]+'0';
                }
            }
        }
        int ans1 = stoi(res);
        int ans2 = stoi(res2);
        cout << min(abs(n-ans1),abs(n-ans2)) << "\n";
    }
}