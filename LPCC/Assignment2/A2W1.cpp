#include <bits/stdc++.h>
using namespace std;


struct mntStruct{
    string macroName;
    int mdtPointer;
};


string makeSubStr(string str, int start, int end){
    string ans = "";
    for(int i = start; i < end; i ++){
        ans += str[i];
    }
    return ans;
}


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


vector<string> splitStringBySpace (string str){
    vector<string> split;
    int i, lastSpace = -1;
    for(i = 0; i < str.length(); i ++){
        if(str[i] == ' '){
            split.push_back( makeSubStr(str, lastSpace + 1, i) );
            lastSpace = i;
        }
    }
    split.push_back( makeSubStr(str, lastSpace + 1, i) );

    return split;
}


int main(){
    vector< vector<string> > inputLinesSplit;
    vector< string > inputLines;
    string line;
    ifstream InputFile("InputA2W1.txt");
    if(InputFile.is_open()){
        while (getline(InputFile, line)) {
            // cout << line << "\n";
            inputLines.push_back( removeCommaSpaces(line) );
            inputLinesSplit.push_back( splitStringBySpace( removeCommaSpaces(line) ) );
        }
    }
    else{
        cout << "Error in opening input file.\n";
    }

    int i, j;
    vector<string> mdt;
    vector<string> ic;
    vector<mntStruct> mnt;

    for(i = 0; i < inputLinesSplit.size(); i ++){

        if(inputLinesSplit[i][0] == "MACRO"){
            mntStruct newMacro;
            newMacro.macroName = inputLinesSplit[i][1];
            newMacro.mdtPointer = mdt.size();
            mnt.push_back(newMacro);
            // cout << inputLinesSplit[i][1] << "\n";

            while(inputLinesSplit[i][0] != "MEND"){
                i += 1;
                mdt.push_back(inputLines[i]);
            }
        }
        else{
            ic.push_back(inputLines[i]);
        }

    }

    fstream outputFile;
    outputFile.open("OutputA2W1.txt", ios::out);

    cout << "\nIC :-\n-------------------------------------------\n";
    outputFile << "\nIC :-\n-------------------------------------------\n";
    for(i = 0; i < ic.size(); i ++){
        cout << ic[i] << "\n";
        outputFile << ic[i] << "\n";
    }

    cout << "\n\nMDT :-\n";
    cout << "-------------------------------------------\nIndex\t\tLine\n-------------------------------------------\n";
    outputFile << "\n\nMDT :-\n";
    outputFile << "-------------------------------------------\nIndex\t\tLine\n-------------------------------------------\n";
    for(i = 0; i < mdt.size(); i ++){
        cout << i << "\t\t" << mdt[i] << "\n";
        outputFile << i << "\t\t" << mdt[i] << "\n";
    }

    // cout << "\nlen - " << mnt.size();
    cout << "\n\nMNT :-\n";
    cout << "-------------------------------------------\nName\t\tPointer\n-------------------------------------------\n";
    outputFile << "\n\nMNT :-\n";
    outputFile << "-------------------------------------------\nName\t\tPointer\n-------------------------------------------\n";
    for(i = 0; i < mnt.size(); i ++){
        cout << mnt[i].macroName << "\t\t" << mnt[i].mdtPointer << "\n";
        outputFile << mnt[i].macroName << "\t\t" << mnt[i].mdtPointer << "\n";
    }

    InputFile.close();
    outputFile.close();    //close the file object

}


// for(i = 0; i < inputLinesSplit.size(); i ++){
//     for(j = 0; j < inputLinesSplit[i].size(); j ++){
//         cout << inputLinesSplit[i][j] << "-";
//     }
//     cout << "\n";
// }