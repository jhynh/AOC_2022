#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

struct file{
    string name;
    int size;
};

struct dir{
    int dSize;
    string nameDir;
    vector<file>contents;
    vector<dir>children;
    dir*parent;
};
//vector consists of smart ptrs, no need for destructor
class fileSys{
    private:
    dir root;
    dir*cur;
    int fsSize;
    
    public:
    fileSys();
    void addDir(string);
    void chDir(string);
    void addFile(string, int);
    void printContents();
    void printAll();
    
};