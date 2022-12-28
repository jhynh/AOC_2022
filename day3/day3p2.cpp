//same as before, but analyze three bags and identify the common item in each
//save all the duplicates into another dictionary, the char and the occurance. look for an occurance of 3 and this will be the answer, identify
//the point group and add to totalPoints

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void split(string,string&,string&);
void listAdd(vector<char>,int&);

int main(){
    fstream file;
    string line;
    vector<char>duplicates;                                     //vector holding chars to add up
    unordered_map<char,int> umap;
    int totalPoints = 0;
    int counter = 0;
    int streak = 0;

    file.open("input2", ios::in);

    while(getline(file,line)){
        for(int i=0; i<line.length();++i){

            //first line
            if(counter%3 == 0)
                umap.insert(pair<char,int>(line[i], 1));
            //second line
            if(counter%3 == 1){
                if(umap.find(line[i]) != umap.end())
                    umap[line[i]] = 2;
            }
            //third line
            if(counter%3 == 2)
                if(umap.find(line[i]) != umap.end())
                    if(umap[line[i]] == 2){
                        umap[line[i]] = 3;
                        duplicates.push_back(line[i]);
                        umap.clear();
                    }
        }
        counter++;
    }

    listAdd(duplicates, totalPoints);

    cout << "total points: " << totalPoints << endl;


    return 0;
}
void listAdd(vector<char> duplicates, int&totalPoints){
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


/*        // Iterating over the map till map end.
        std::for_each(umap.begin(), umap.end(),
                [](pair<char, int> key_value)
                {
                    // Accessing the key
                    char word = key_value.first;
                    // Accessing the value
                    int count = key_value.second;
                    std::cout<<word<<" :: "<<count<<std::endl;
        }); */