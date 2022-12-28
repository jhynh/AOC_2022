#include<iostream>
#include<map>
#include<fstream>
using namespace std;

struct arsenal{
    int points;
};

int main(){
    fstream file;
    string line;
    file.open("input", ios::in);
    arsenal rock, paper, scissors, opp, you;
    
    rock.points = 1;
    paper.points = 2;
    scissors.points = 3;

    map<char, arsenal> catalog;
    catalog.insert(pair<char, arsenal>('A', rock));
    catalog.insert(pair<char, arsenal>('B', paper));
    catalog.insert(pair<char, arsenal>('C', scissors));
    catalog.insert(pair<char, arsenal>('X', rock));
    catalog.insert(pair<char, arsenal>('Y', paper));
    catalog.insert(pair<char, arsenal>('Z', scissors));

    char ch;
    char ch1;
    int total = 0;
    while(file >> ch,file >> ch1){
        opp = catalog[ch];
        you = catalog[ch1];

        switch(ch){
            case 'A':
            if(ch1 == 'Y')
                total +=6;
            else if(ch1 == 'X')
                total += 3;
            break;

            case 'B':
            if(ch1 == 'Z')
                total += 6;
            else if(ch1 == 'Y')
                total += 3;
            break;
            
            case 'C':
            if(ch1 == 'X')
                total += 6;
            else if(ch1 == 'Z')
                total += 3;
        };
        total += you.points;
    }
    cout << total << endl;

//===traversing===
/*     map<char, arsenal>::iterator cur;
    for(cur = catalog.begin(); cur != catalog.end(); ++cur){
        
    }*/

//===alternative===
/*     map<char,arsenal> mymap = {
        {'A', rock},
        {'Y', paper},
        {'Z', scissors}
    }; */

    return 0;
}