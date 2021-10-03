#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1000][1000];

ll maximum(ll a, ll b){
    return a >= b ? a : b;
}


ll knapsackMemo(ll weights[], ll values[], ll w, ll n){
    if(w == 0 || n == 0){
        return 0;
    }

    if(dp[w][n] != -1){
        return dp[w][n];
    }

    if(weights[n-1] > w){
        dp[w][n] = knapsackMemo(weights, values, w, n-1);
    }
    else{
        dp[w][n] = maximum( 
                values[n-1] + knapsackMemo(weights, values, w-weights[n-1], n-1),
                knapsackMemo(weights, values, w, n-1)
            );
    }

    return dp[w][n];
}


ll knapsackGreedy(ll weights[], ll values[], ll w, ll n){
    if(w == 0 || n == 0){
        return 0;
    }

    if(weights[n-1] > w){
        return knapsackGreedy(weights, values, w, n-1);
    }
    else{
        return maximum( 
                values[n-1] + knapsackGreedy(weights, values, w-weights[n-1], n-1),
                knapsackGreedy(weights, values, w, n-1)
            );
    }

}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    

    ll len, i, j;
    cout << "Enter no of items (len) : ";
    cin >> len;

    ll weights[len], values[len], maxWeight;

    cout << "Enter weight - value (Space Seperated) :\n";
    for(i = 0; i < len; i ++){
        cout << i + 1 << " : ";
        cin >> weights[i] >> values[i];
    }

    cout << "\nEnter max weight (W) : ";
    cin >> maxWeight;

    cout << "Greedy     : " << knapsackGreedy(weights, values, maxWeight, len) << "\n";

    for(i = 0; i < 1000; i ++){
        for(j = 0; j < 1000; j ++){
            dp[i][j] = -1;
        }
    }
    cout << "Memoization : " << knapsackMemo(weights, values, maxWeight, len) << "\n";
}

