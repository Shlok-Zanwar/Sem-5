#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int binarySearch(ll arr[], ll len, ll search ){
    ll mid, low = 0, high = len-1;

    while (low <= high){
        mid = low + int((high - low) / 2);

        if(arr[mid] == search){
            return mid;
        }

        if(search > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return -1;
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll len, i, search;

    cout << "Length off array : ";
    cin >> len;
    ll arr[len];
    
    cout << "Array (Sorted)   : ";
    for(i = 0; i < len; i ++){
        cin >> arr[i];
    }

    cout << "To search        : ";
    cin >> search;
    ll index = binarySearch(arr, len, search);

    if(index == -1) {
        cout << search << " not found !!";
        return 0;
    }

    cout << search << " found at index " << index << ".";
    return 0;
}
