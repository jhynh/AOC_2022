#include<iostream>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream file;
    file.open("input", ios::in);

    string line;
    vector<int> elves;
    
    int num = 0;
    int total = 0;
    int topTotal = 0;
    int count = 0;

    while(getline(file,line, '\n')){
        if(line == ""){
            elves.push_back(total);
            total = 0;
            continue;
        }else{
            total += stoi(line);
        }
    }

    sort(elves.begin(), elves.end());
    for(auto i=elves.end()-3; i != elves.end(); i++){
        cout << *i << '\n';
        topTotal += *i;
    }

    cout << "top 3 total: " << topTotal << endl;
    return 0;
}