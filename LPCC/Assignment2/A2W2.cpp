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

string removeCommas (string str){
    int i;
    string commaReplaced = "";
    for(i = 0; i < str.length(); i ++){
        if(str[i] == ','){
            commaReplaced += " ";
        }
        else{
            commaReplaced += str[i];
        }
    }

    return commaReplaced;
}

string removeSpaces (string str){
    int i;
    string tabReplaced = "", spaceReplaced = " ";
    for(i = 0; i < str.length(); i ++){
        if(str[i] == '\t'){
            tabReplaced += " ";
        }
        else{
            tabReplaced += str[i];
        }
    }

    for(i = 0; i < tabReplaced.length(); i ++){
        if(tabReplaced[i] == ' '){
            if( spaceReplaced[spaceReplaced.length() - 1] != ' ' ){
                spaceReplaced += " ";
            }
        }
        else{
            spaceReplaced += tabReplaced[i];
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


int handleMacro (
    int i, 
    vector< string > inputLines,
    vector< vector<string> > inputLinesSplit,
    vector<mntStruct> &mnt,
    vector<string> &mdt
){
    int j, k;
    string toAdd;
    map <string, int>  m;
    mntStruct newMacro;

    newMacro.macroName = inputLinesSplit[i][1];
    newMacro.mdtPointer = mdt.size();
    mnt.push_back(newMacro);
    mdt.push_back( makeSubStr(inputLines[i], 6, inputLines[i].length()) );


    for(j = 2; j < inputLinesSplit[i].size(); j ++){
        toAdd = inputLinesSplit[i][j];

        for(k = 0; k < inputLinesSplit[i][j].length(); k ++){
            if(inputLinesSplit[i][j][k] == '='){
                toAdd = makeSubStr(inputLinesSplit[i][j], 0, k);
                break;
            }
        }
        m[toAdd] = j - 1; 
    }
    
    while(inputLinesSplit[i][0] != "MEND"){
        i += 1;
        toAdd = inputLinesSplit[i][0] + " ";
        // mdt.push_back( inputLinesSplit[i][0] );

        for(j = 1; j < inputLinesSplit[i].size(); j ++){
            if(m[ inputLinesSplit[i][j] ] == 0){
                toAdd += inputLinesSplit[i][j];
            }
            else{
                toAdd += "#" + to_string(m[ inputLinesSplit[i][j] ] );
            }

            if(j != inputLinesSplit[i].size() - 1){
                toAdd += ", ";
            }
        }

        mdt.push_back( toAdd );
    }
    return i;
}


int main(){
    vector< vector<string> > inputLinesSplit;
    vector< string > inputLines;
    string line;
    ifstream InputFile("InputA2W2.txt");
    if(InputFile.is_open()){
        while (getline(InputFile, line)) {
            // cout << line << "\n";
            inputLines.push_back( removeSpaces(line) );
            inputLinesSplit.push_back( splitStringBySpace( removeSpaces( removeCommas(line) ) ) );
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

        // cout << inputLines[i] << "\n";
        if(inputLinesSplit[i][0] == "MACRO"){
            i = handleMacro(i, inputLines, inputLinesSplit, mnt, mdt);
        }
        else{
            ic.push_back(inputLines[i]);
        }

    }

    fstream outputFile;
    outputFile.open("OutputA2W2.txt", ios::out);

    cout << "\nIC :-\n-------------------------------------------\n";
    outputFile << "\nIC :-\n-------------------------------------------\n";
    for(i = 0; i < ic.size(); i ++){
        cout << ic[i] << "\n";
        outputFile << ic[i] << "\n";
    }
    // cout << i;

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


// for(i = 0; i < inputLinesSplit.size(); i ++){
//     cout << inputLinesSplit[i].size() << " - ";
//     for(j = 0; j < inputLinesSplit[i].size(); j ++){

//     cout << "'" << inputLinesSplit[i][j] << "',";
//     // outputFile << ic[i] << "\n";
//     }
//     cout << "\n";
// }
// return 0;