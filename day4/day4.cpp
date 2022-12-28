#include<iostream>
#include<fstream>
#include<vector>
#include<regex>
using namespace std;

int main(){
//variables----------------------------------------------
    fstream file;
    string line;
    smatch m;
    file.open("input", ios::in);
    int start1, end1, start2, end2 = 0;
    int counter = 0;
//variables----------------------------------------------

    std::regex rx("[0-9]+"); // Declare the regex with a raw string literal

    while(getline(file,line)){
        int mod = 0;

        while (regex_search(line, m, rx)) {
    
            if(mod%4 == 0)
                start1 = stoi(m[0]);
            else if (mod%4 == 1)
                end1 = stoi(m[0]);
            else if (mod%4 == 2)
                start2 = stoi(m[0]);
            else if(mod%4 == 3)
                end2 = stoi(m[0]);

            line = m.suffix().str(); // Proceed to the next match

            mod++;
        }

//check first interval is contained in second or vise versa

//  2:3             1:4
//  1:4     or      2:3

        if((end1 < end2 && start1 > start2) || (end1 > end2 && start1 < start2)){
            counter++;

//  3:5             2:5
//  1:5     or      3:5

        }else if((end1 == end2 && start1 > start2) || (start1 < start2 && end1 == end2)){
            counter++;

//  5:4             5:3
//  5:2     or      5:4

        }else if((start1 == start2 && end1 > end2) || (start1 == start2 && end1 < end2)){
            counter++;
        

//  6:6             6:5
//  5:6     or      6:6
        
        }else if((start1 == end2 && end1 == end2) || (start2 == start1 && end2 == end1)){
            counter++;
        }

    }
    cout << "matches: " << counter <<endl;
    return 0;
}