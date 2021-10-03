#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string removeCommaSpaces (string str) {
    int i;
    string commaReplaced = "", tabReplaced = "", spaceReplaced = " ";
    for(i = 0; i < str.length(); i ++){
        if(str[i] == '\t'){
            tabReplaced += " ";
        }
        else{
            tabReplaced += str[i];
        }
    }


    for(i = 0; i < tabReplaced.length(); i ++){
        if(tabReplaced[i] == ','){
            commaReplaced += " ";
        }
        else{
            commaReplaced += tabReplaced[i];
        }
    }

    for(i = 0; i < commaReplaced.length(); i ++){
        if(commaReplaced[i] == ' '){
            if( spaceReplaced[spaceReplaced.length() - 1] != ' ' ){
                spaceReplaced += " ";
            }
        }
        else{
            spaceReplaced += commaReplaced[i];
        }
    }

    if(spaceReplaced[0] == ' '){
        spaceReplaced.erase (spaceReplaced.begin());
    }
    if(spaceReplaced[spaceReplaced.length() - 1] == ' '){
        spaceReplaced.erase (spaceReplaced.end() - 1);
    }
    // cout << spaceReplaced << " heyyy\n";

    return spaceReplaced;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // string str = "	MOVER 	&REG,&A";
    // for (int i=0; i < str.length(); i ++){
    //     if(str[i] == '\t'){
    //         cout << "yess\n";
    //     }
    //     cout <<  "'" << str[i] << "'\n";
    // }
    // cout << "----------------\n\n";
    // string newStr = removeCommaSpaces(str);
    // for (int i=0; i < newStr.length(); i ++){
    //     if(newStr[i] == '\t'){
    //         cout << "yess\n";
    //     }
    //     cout <<  "'" << newStr[i] << "'\n";
    // }

    // cout << "\n\n\n'" << newStr  << "'\n";

    map <string, int>  m;
    m["Shlok"]=3;


    cout << m["Shlok"];

}
