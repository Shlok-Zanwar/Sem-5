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
