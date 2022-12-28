#include<iostream>
#include<fstream>
#include<vector>
#include<deque>
#include<regex>
using namespace std;
void extractCols(vector<deque<char>>, vector<string>);
int main(){
//variables----------------------------------
    string line;
    vector<deque<char>> columns;
    smatch m;
    regex rx("\\[([^\\][]*)]");
    
    fstream file;
    file.open("input.txt", ios::in);
//variables----------------------------------

//REGEX APPROACH
//**************************************************************************
/*     while(getline(file, line,'\n')){
        if(line[1] == '1')
            break;
        while(regex_search(line,m,rx)){

            cout << m[1] << " ";

            line = m.suffix().str();
        }
        cout << "\n--------------------------\n";
    } */
//**************************************************************************
deque<char> column1, column2, column3, column4, column5, column6, column7, column8, column9;

//FIXED INDEX APPROACH

//grab all the lines
    while(getline(file, line, '\n')){
        if(line[1] == '1')
            break;

        for(int i =0; i<line.length(); ++i){
            if(line[i] != ' ' || line[i] != '[' || line[i] != ']'){
                if(i == 1)
                    column1.push_back(line[i]);
                else if (i == 5)
                    column2.push_back(line[i]);
                else if (i == 9)
                    column3.push_back(line[i]);
                else if (i == 13)
                    column4.push_back(line[i]);
                else if (i == 17)
                    column5.push_back(line[i]);
                else if (i == 21)
                    column6.push_back(line[i]);
                else if (i == 25)
                    column7.push_back(line[i]);
                else if (i == 29)
                    column8.push_back(line[i]);
                else if (i == 33)
                    column9.push_back(line[i]);
            }
        }
    }

    // using begin() to print deque
    for (auto it = column1.begin(); it != column1.end(); ++it)
        cout << ' ' << *it;

    return 0;
}

//    smatch m;
//    regex rx("\\[([^\\][]*)]");
//variables----------------------------------

//REGEX APPROACH
//**************************************************************************
/*     while(getline(file, line,'\n')){
        if(line[1] == '1')
            break;
        while(regex_search(line,m,rx)){

            cout << m[1] << " ";

            line = m.suffix().str();
        }
        cout << "\n--------------------------\n";
    } */
//**************************************************************************