#include<iostream>
#include<map>
#include<fstream>
using namespace std;

struct arsenal{
    int points;
    int win;
    int loss;
};

int main(){
    fstream file;
    string line;
    file.open("input", ios::in);
    arsenal rock, paper, scissors, opp;
    
    rock.points = 1;
    rock.win = 2;
    rock.loss = 3;

    paper.points = 2;
    paper.win = 3;
    paper.loss = 1;
    
    scissors.points = 3;
    scissors.win = 1;
    scissors.loss = 2;


    map<char, arsenal> catalog;
    catalog.insert(pair<char, arsenal>('A', rock));
    catalog.insert(pair<char, arsenal>('B', paper));
    catalog.insert(pair<char, arsenal>('C', scissors));

    char ch;
    char ch1;
    int total = 0;
    int yourChoice = 0;
    while(file >> ch,file >> ch1){
        opp = catalog[ch];
        
        switch(ch1){
            case 'X':
                yourChoice = opp.loss;
                break;
            case 'Y':
                yourChoice = opp.points;
                total += 3;
                break;
            case 'Z':
                yourChoice = opp.win;
                total += 6;
        };
        total += yourChoice;
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