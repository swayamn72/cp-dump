#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll>> arr(3, vector<ll>(6));
    for (auto &a : arr)
        for (auto &b : a)
            cin >> b;
    // for(auto a : arr){
    //     for(auto b : a) cout << b << " ";
    //     cout << "\n";
    // }
    double first4 = 0, first5 = 0, first6 = 0;
    for (ll j = 0; j < 6; j++)
    {
        if (arr[0][j] == 4)
            first4++;
        else if (arr[0][j] == 5)
            first5++;
        else if (arr[0][j] == 6)
            first6++;
    }
    first4 /= 6;
    first5 /= 6;
    first6 /= 6;

    double second4 = 0, second5 = 0, second6 = 0;
    for (ll j = 0; j < 6; j++)
    {
        if (arr[1][j] == 4)
            second4++;
        else if (arr[1][j] == 5)
            second5++;
        else if (arr[1][j] == 6)
            second6++;
    }
    second4 /= 6;
    second5 /= 6;
    second6 /= 6;

    double third4 = 0, third5 = 0, third6 = 0;
    for (ll j = 0; j < 6; j++)
    {
        if (arr[2][j] == 4)
            third4++;
        else if (arr[2][j] == 5)
            third5++;
        else if (arr[2][j] == 6)
            third6++;
    }
    third4 /= 6;
    third5 /= 6;
    third6 /= 6;
    double res = 0;
    res += (first4 * second5 * third6);
    res += (first4 * second6 * third5);
    res += (first5 * second4 * third6);
    res += (first5 * second6 * third4);
    res += (first6 * second4 * third5);
    res += (first6 * second5 * third4);

    cout << setprecision(8) << res;
}