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
        if(n==2){
            cout << "1 2 2 1 1 2 1 2" << "\n";
            continue;
        }
        if(n==3){
            cout << "1 1 2 1 2 3 1 3 2 2 3 3" << "\n";
            continue;
        }
        vi arr(4*n,-1);
       
        
        if(n%2==0){
            ll left = 0, right = 4*n-1;
            bool flag = true;
            for(ll i=1; i<=n-2; i++){
                arr[left] = i;
                arr[left+1] = i;
                arr[right] = i;
                arr[right-2] = i;
                left += 2;
                if(flag){
                    flag = false;
                    right--;
                }else{
                    flag = true;
                    right -= 3;
                }
            }   
            ll val1 = n, val2 = n-1;
            ll temp = (n-2)*2;
            ll idx = 0;
            for(ll i=temp; i<4*n-temp; i++){
                if(idx==0 || idx==3 || idx==4 || idx==6) arr[i] = val1;
                else arr[i] = val2;
                idx++;
            }
            for(auto a : arr) cout << a << " ";
            cout << "\n";
        }else{
            ll left = 0, right = 4*n-1;
            bool flag = true;
            for(ll i=1; i<=n-3; i++){
                arr[left] = i;
                arr[left+1] = i;
                arr[right] = i;
                arr[right-2] = i;
                left += 2;
                if(flag){
                    flag = false;
                    right--;
                }else{
                    flag = true;
                    right -= 3;
                }
            }   
            ll val1 = n, val2 = n-1, val3 = n-2;
            ll temp = (n-3)*2;
            ll idx = 0;
            for(ll i=temp; i<4*n-temp; i++){
                if(idx==0 || idx==1 || idx==3 || idx==6) arr[i] = val1;
                else if(idx==2 || idx==4 || idx==8 || idx==9) arr[i] = val2;
                else arr[i] = val3;
                idx++;
            }
            for(auto a : arr) cout << a << " ";
            cout << "\n";
        }
        

    }
}