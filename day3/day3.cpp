#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void split(string,string&,string&);

int main(){
    fstream file;
    string line;
    int totalPoints = 0;
    file.open("input", ios::in);

    vector<char>duplicates;

    while(getline(file,line)){
        
        char duplicate;
        string sub1;
        string sub2;

        unordered_map<char,int> umap;

        split(line,sub1 ,sub2);
        
        //traverse and create a dictionary of the chars
        for(int i=0; i < sub1.length();++i){
            umap.insert(pair<char,int>(sub1[i], 1));
        }

        //go over next substring and find if it exists in the dictionary
        for(int i=0; i<sub2.length();++i){
            if(umap[sub2[i]] == 1){
                duplicate = sub2[i];
            }
        }

        //store the duplicate char in a vector
        duplicates.push_back(duplicate);
    }

    //itterate over vector and add up total priority #
    for(char i: duplicates){
        
        /*
            z = 122
            Z = 90

            z = 122 - 96 = 26
            Z = 90 - 38 = 52
        */
        //+96 for lowercase
        //-38 for uppercase

        int ascii = int(i);

        if(ascii <= 122 && ascii >= 97){
            int points = ascii -96;
            totalPoints += points;
        }else if(ascii <= 90 && ascii >= 65){
            int points = ascii - 38;
            totalPoints += points;
        }
    }

    cout << "total points: " << totalPoints << endl;


    return 0;
}

void split(string line, string& sub1, string& sub2){
    int size = 0;
    size = line.length();
    for(int i=0; i<size/2; i++){
        sub1 += line[i];
    }
    for(int i=size/2; i<size; i++){
        sub2 += line[i];
    }
}