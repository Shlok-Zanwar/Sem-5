#include <bits/stdc++.h>
using namespace std;


struct mntStruct{
    string macroName;
    int mdtPointer;
    int noOfParameters;
    map <string, int> parameters;
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


int isMacroPresent(vector<mntStruct> &mnt, string check){
    int i;
    for(i = 0; i < mnt.size(); i ++){
        if(mnt[i].macroName == check){
            return i;
        }
    }

    return -1;
}


void handleCallMacro(
    int i, 
    vector< string > inputLines,
    vector< vector<string> > inputLinesSplit,
    vector<mntStruct> &mnt,
    vector<string> &mdt,
    int macroMntIndex
){
    int j = mnt[macroMntIndex].mdtPointer, k;
    vector<string> splitString;
    string toAdd;

    while(removeSpaces(mdt[j]) != "MEND"){
        splitString = splitStringBySpace( removeSpaces(removeCommas(mdt[j])) );
        toAdd = splitString[0] + " ";

        for(k = 1; k < splitString.size(); k ++){
            if( splitString[k][0] == '#'){
                // cout << splitString[k][1] << " " << inputLinesSplit[i][1] <<  " -----\n";
                string s(1, splitString[k][1]);
                toAdd += inputLinesSplit[i][ stoi(s) ];
            }
            else{
                toAdd += splitString[k];
            }

            if(k != splitString.size() - 1){
                toAdd += ", ";
            }
        }

        j += 1;
        mdt.push_back(toAdd);
    }

}


int handleAddMacro (
    int i, 
    vector< string > inputLines,
    vector< vector<string> > inputLinesSplit,
    vector<mntStruct> &mnt,
    vector<string> &mdt
){
    int j, k, checkMacro;
    string toAdd;
    map <string, int>  m;
    mntStruct newMacro;

    newMacro.macroName = inputLinesSplit[i][1];
    newMacro.mdtPointer = mdt.size();
    newMacro.noOfParameters = inputLinesSplit[i].size() - 2;

    // mdt.push_back( makeSubStr(inputLines[i], 6, inputLines[i].length()) );


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
    
    newMacro.parameters = m; 
    mnt.push_back(newMacro);

    while(inputLinesSplit[i][0] != "MEND"){
        i += 1;
        checkMacro = isMacroPresent(mnt, inputLinesSplit[i][0]);
        if(checkMacro != -1 ){
            handleCallMacro(i, inputLines, inputLinesSplit, mnt, mdt, checkMacro);
            continue;
        }
        toAdd = inputLinesSplit[i][0] + " ";
        // mdt.push_back( inputLinesSplit[i][0] );

        for(j = 1; j < inputLinesSplit[i].size(); j ++){
            if(m[ inputLinesSplit[i][j] ] == 0){
                toAdd += inputLinesSplit[i][j];
            }
            else{
                toAdd += "#" + to_string(m[ inputLinesSplit[i][j] ]);
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
    ifstream InputFile("InputA2W3.txt");
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

        if(inputLinesSplit[i][0] == "MACRO"){
            i = handleAddMacro(i, inputLines, inputLinesSplit, mnt, mdt);
        }
        else{
            ic.push_back(inputLines[i]);
        }

    }

    fstream outputFile;
    outputFile.open("OutputA2W3.txt", ios::out);

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
    cout << "-------------------------------------------\nName\t\tPointer\t\tParameters\n-------------------------------------------\n";
    outputFile << "\n\nMNT :-\n";
    outputFile << "-------------------------------------------\nName\t\tPointer\t\tParameters\n-------------------------------------------\n";
    for(i = 0; i < mnt.size(); i ++){
        cout << mnt[i].macroName << "\t\t" << mnt[i].mdtPointer << "\t\t" << mnt[i].noOfParameters << "\n";
        outputFile << mnt[i].macroName << "\t\t" << mnt[i].mdtPointer << "\t\t" << mnt[i].noOfParameters << "\n";
    }

    cout << "\n\nMNT Variables :-\n-------------------------------------------\n";
    outputFile << "\n\nMNT Variables :-\n-------------------------------------------\n";
    for(i = 0; i < mnt.size(); i ++){
        if(mnt[i].noOfParameters == 0){
            continue;
        }
        cout << "\n";
        cout << mnt[i].macroName << " :-\n";
        cout << "--------------------------\n";
        cout << "Name\t\tValue\n";
        cout << "--------------------------\n";

        outputFile << "\n";
        outputFile << mnt[i].macroName << " :-\n";
        outputFile << "--------------------------\n";
        outputFile << "Name\t\tValue\n";
        outputFile << "--------------------------\n";

        for (auto i : mnt[i].parameters){
            cout << i.first << "\t\t#" << i.second << "\n";
            outputFile << i.first << "\t\t#" << i.second << "\n";
        }
        cout << "\n";
        outputFile << "\n";

    }

    InputFile.close();
    outputFile.close();    //close the file object

}