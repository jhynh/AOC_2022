//sliding window problem of 4 char width on a string
//find nonconsecutive substring
#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;

int main(){
    //sliding window utilizes two pointers, one for the back and another for the front
    //after each itteration, we increment the pointers by 4 and "slide" our "window"
    int endPtr = 0;
    int startPtr = 0;
    int counter = 0;

    string line;
    string trueKey;

    fstream file;
    bool flag = 0;
    file.open("input",ios::in);
    getline(file, line);


    for(int i=0; i<line.length()-14;++i){
        flag = 0;
        unordered_map<char, int> table;
        string key;
        startPtr = i;
        endPtr = i+14;

//keep track of duplicates
        for(int i=startPtr; i<endPtr;++i){
            table[line[i]]++;
            
            cout <<  line[i] << ": "<< table[line[i]] << endl;
            key += line[i];

            if(table[line[i]] > 1)
                flag = 1;
        }
        cout << "----\n";
        
        if(flag == 0){
            cout << "";
            trueKey = key;
            counter = line.find(key)+14;
            break;
        }
    }
    cout << "spaces: " << counter << endl;
    cout << "key is: " << trueKey << endl;

    return 0;
}