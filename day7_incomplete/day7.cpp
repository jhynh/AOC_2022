//although treated as a filesystem, a linked list seems like the best datastructure, however,
//a graph would best represent this
#include "fileSys.hpp"
#include<sstream>
#include<string>
//contents  = files
//children  = directories
//parent    = for "cd .."
vector<string> split(string);

int main(){

    fstream file;
    string line;

//all directories with files at most 100000, find the total size 
    int fsSize = 0;
    bool fileFlag = 0;

    file.open("test", ios::in);
    
//files which don't start with "$" or "dir", are added to the total size
    fileSys fs;

    while(getline(file,line, '\n')){
        vector<string> words(split(line));
        
        if(words[1] == "ls"){
            fileFlag = 1;
            continue;
        }else if(words[0] == "$")
            fileFlag = 0;
        if(fileFlag == 1 && words[0] != "dir"){
            fs.addFile(words[1],stoi(words[0]));
        }else if(fileFlag == 1){
            fs.addDir(words[1]);
        }

        if(words[1] == "cd")
            fs.chDir(words[2]);
            
    }
    
    fs.printAll();

    return 0;
}

vector<string> split(string line){
    vector<string> words;
//init isstringstream
    istringstream iss(line);

    do{
        string subs;
        iss >> subs;
        if(subs.empty())
            continue;
        words.push_back(subs);
    
    } while(iss);

    return words;
}