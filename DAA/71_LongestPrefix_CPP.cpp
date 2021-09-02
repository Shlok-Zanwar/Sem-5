#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void printArray(string arr[], ll len){
    for(ll i = 0; i < len; i ++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

        
string longestCommonPrefix(string arr[], ll len){
    ll i, j;
    string longestPrefix = arr[0], newPrefix;
    for(i = 1; i < len; i ++){
        newPrefix = "";
        for(j = 0; j < arr[i].length(); j ++){
            if(arr[i][j] == longestPrefix[j]){
                newPrefix += longestPrefix[j];
            }
            else{
                break;
            }
        }

        if(newPrefix == ""){
            return "-1";
        }
        longestPrefix = newPrefix;
    }


    return longestPrefix;
}



int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll len, i;
    cout << "Enter length of array   : ";
    cin >> len;
    string arr[len];
    
    cout << "Enter elements of array : ";
    for(i = 0; i < len; i ++){
        cin >> arr[i];
    }

    cout << "\nInput Array           : ";
    printArray(arr, len);

    cout << "Longest common prefix : " << longestCommonPrefix(arr, len);

}
