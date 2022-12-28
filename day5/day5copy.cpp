//CHANGE # OF FIXED COLUMNS BEFORE RUNNING!!!!
#include<iostream>
#include<fstream>
#include<vector>
#include<deque>
#include<regex>
#include<sstream>
using namespace std;
void printAll(vector<deque<char>>);
void moveIt(int,int,int,vector<deque<char>>&);
bool extractInts(string,int&,int&,int&);
int main(){

//---------------------------variables----------------------------------
    string line;
    int numCols = 9;
    vector<deque<char>> columns;
    fstream file;
    file.open("input.txt", ios::in);
//----------------------------------------------------------------------

    deque<char> *column;
    vector<deque<char>> diagram;

//initialize vector of deques
    for(int i=0; i<numCols;++i){
        column = new deque<char>;
        diagram.push_back(*column);
    }

//grab all the lines
    while(getline(file, line)){
        
        int counting = 0;

        if(line[1] == '1')
            break;
            
//place them in their corresponding position in the vector
        for(int i=1; i< line.length();i+=4){
            if(line[i] != ' '){
                diagram[counting].push_back(line[i]);
            }
            counting++;
        }
    }

//extract all the 'move's, the 'from's, and the 'to's
    while(getline(file,line)){
        int mv, frm, to = 0;

//TODO: extract them and place them in the vars, then send over to function
        if(extractInts(line,mv,frm,to) == true)
            moveIt(mv,frm,to,diagram);
    }

    for(int i=0; i<numCols;++i){
        cout << diagram[i].at(0);
    }
    cout << endl;

    return 0;
}

void printAll(vector<deque<char>> diagram){
    // using begin() to print deque
    for(int i=0; i<diagram.size();++i){
        for (auto it = diagram[i].begin(); it != diagram[i].end(); ++it)
            cout << ' ' << *it;
        cout << endl;
    }
}

void moveIt(int mv, int frm, int to, vector<deque<char>>&diagram){
    //mv is amount to move from top
    //frm is the index of vector
    //to is to the top of another deque vector index

    for(int i=0; i<mv;++i){
        diagram[to-1].push_front(diagram[frm-1].at(i));
    }
    for(int i=0; i<mv;++i){
        diagram[frm-1].pop_front();
    }

}

bool extractInts(string str, int& mv, int& frm, int& to){
    stringstream ss;

    //store string into string stream
    ss << str;

    //loop until end of stream
    string tmp;
    int found = 0;
    int count = 0;
    while(!ss.eof()){
        count++;
        //extract word by word from stream
        ss >> tmp;
        //check if int
        if(stringstream(tmp) >> found){
            switch(count){
                case 2:
                    mv = found;
                    break;
                case 4:
                    frm = found;
                    break;
                case 6:
                    to = found;
            };
        }
        tmp = "";
    }
    if(count < 6)
        return false;
    return true;
}