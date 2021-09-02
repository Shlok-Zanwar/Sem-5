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

// OUTPUT 

// PS C:\Users\princ\Documents\GitHub\Sem-5\DAA> cd "c:\Users\princ\Documents\GitHub\Sem-5\DAA\" ; if ($?) { g++ 71_LongestPrefix_CPP.cpp -o 71_LongestPrefix_CPP } ; if ($?) { .\71_LongestPrefix_CPP }
// Enter length of array   : 3
// Enter elements of array : apple ape april

// Input Array           : apple ape april 
// Longest common prefix : ap


// PS C:\Users\princ\Documents\GitHub\Sem-5\DAA> cd "c:\Users\princ\Documents\GitHub\Sem-5\DAA\" ; if ($?) { g++ 71_LongestPrefix_CPP.cpp -o 71_LongestPrefix_CPP } ; if ($?) { .\71_LongestPrefix_CPP }
// Enter length of array   : 4    
// Enter elements of array : flower fly flight flow

// Input Array           : flower fly flight flow 
// Longest common prefix : fl


// PS C:\Users\princ\Documents\GitHub\Sem-5\DAA> cd "c:\Users\princ\Documents\GitHub\Sem-5\DAA\" ; if ($?) { g++ 71_LongestPrefix_CPP.cpp -o 71_LongestPrefix_CPP } ; if ($?) { .\71_LongestPrefix_CPP }
// Enter length of array   : 3
// Enter elements of array : after academy mindorks  

// Input Array           : after academy mindorks 
// Longest common prefix : -1