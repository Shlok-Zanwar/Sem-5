#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void printArray(ll arr[], ll len){
    for(ll i = 0; i < len; i ++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertionSort(ll arr[], ll len){
    ll i, key, j;
    for (i = 1; i < len; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll len, i;
    cout << "Enter length of array   : ";
    cin >> len;
    ll arr[len];
    
    cout << "Enter elements of array : ";
    for(i = 0; i < len; i ++){
        cin >> arr[i];
    }

    cout << "\nInput Array  : ";
    printArray(arr, len);
    insertionSort(arr, len);
    cout << "Sorted Array : ";
    printArray(arr, len);

}


// OUTPUT

// PS C:\Users\princ\Documents\GitHub\Sem-5> cd "c:\Users\princ\Documents\GitHub\Sem-5\DAA\" ; if ($?) { g++ 71_InsertionSort_CPP.cpp -o 71_InsertionSort_CPP } ; if ($?) { .\71_InsertionSort_CPP }

// Enter length of array   : 5
// Enter elements of array : 6 4 2 8 1

// Input Array  : 6 4 2 8 1 
// Sorted Array : 1 2 4 6 8 



// PS C:\Users\princ\Documents\GitHub\Sem-5\DAA> cd "c:\Users\princ\Documents\GitHub\Sem-5\DAA\" ; if ($?) { g++ 71_InsertionSort_CPP.cpp -o 71_InsertionSort_CPP } ; if ($?) { .\71_InsertionSort_CPP }
// Enter length of array   : 4
// Enter elements of array : 3 8 4 6

// Input Array  : 3 8 4 6
// Sorted Array : 3 4 6 8