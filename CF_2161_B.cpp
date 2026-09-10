#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<char>> arr(n,vector<char>(n));
        for(auto &a : arr) for(auto &b : a) cin >> b;

        ll r = -1, c = -1;
        ll count = 0;
        for(ll i=0; i<n; i++) for(ll j=0; j<n; j++){
            if(arr[i][j]=='#'){
                if(r==-1){
                    r = i, c = j;
                } 
                count++;
            }
        }
        bool flag = false;
        if(count==4 && r<n-1 && c<n-1){
            if(arr[r+1][c+1]=='#' && arr[r+1][c]=='#' && arr[r][c+1]=='#'){
                flag = true;
            }
        }
        if(count==0) flag = true;
        if(flag){
            cout << "YES" << "\n";
            continue;
        }

        ll count1 = 0;
        ll i = r, j = c;
        bool temp = false;
        while(i<n && j<n){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j++;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }

        count1 = 0;
        i = r; j = c;
        temp = true;
        while(i<n && j<n){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j++;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }

        count1 = 0;
        i = r; j = c;
        temp = true;
        while(i<n && j>=0){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j--;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }

        count1 = 0;
        i = r; j = c;
        temp = false;
        while(i<n && j>=0){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j--;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }

        // other
        r = -1; c = -1;
        for(ll i=0; i<n; i++){
            for(ll j=n-1; j>=0; j--){
                if(arr[i][j]=='#'){
                    if(r==-1){
                        r = i, c = j;
                    }
                }
            }
        }
        count1 = 0;
        i = r, j = c;
        temp = false;
        while(i<n && j<n){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j++;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }

        count1 = 0;
        i = r; j = c;
        temp = true;
        while(i<n && j<n){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j++;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }

        count1 = 0;
        i = r; j = c;
        temp = true;
        while(i<n && j>=0){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j--;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }

        count1 = 0;
        i = r; j = c;
        temp = false;
        while(i<n && j>=0){
            if(arr[i][j]=='#') count1++;
            if(temp) i++;
            else j--;
            temp = !temp;
        }
        if(count1 == count){
            cout << "YES" << "\n";
            continue;
        }
        cout << "NO" << "\n";
    }
} 