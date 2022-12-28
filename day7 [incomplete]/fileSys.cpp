#include "fileSys.hpp"

fileSys::fileSys(){
    root.parent = nullptr;
    root.nameDir = '/';
    cur = &root;
};
//-------------------------------------------------------------------------------------
//uses BFS and a QUEUE to traverse the FS
void fileSys::printAll(){
    queue<dir> que;
    dir *tmp = cur;
    cur = &root;
    
    string spaces = " ";
    cout << "printing WHOLE fs: \n";
    
    if(!cur->children.empty()){
        que.push(*cur);
        while(!que.empty()){
            int dSize = 0;
            cout << "--/" << cur->nameDir << endl;
            
            for(int i=0; i<cur->children.size();++i){
                cout << "dir "<< cur->children[i].nameDir << endl;

                que.push(cur->children[i]);
            }

            if(!cur->contents.empty()){
                for(int i=0; i<cur->contents.size();++i){
                    cout << cur->contents[i].name << endl;
                    dSize += cur->contents[i].size;
                }
                cur->dSize = dSize;

                if(dSize <= 100000){
                    fsSize += dSize;
                    if(cur->parent != nullptr && cur->parent->dSize <= 100000)
                        fsSize += dSize;
                    cout << "ADDING_" << cur->nameDir << ": " << dSize << endl;
                }
            }

            que.pop();
            cur = &que.front();
        }

    }else{
        cout << "only root directory exists\n";
        printContents();
    }
    cout << "----------------------------------------------------\n";
    cout << "directories w/size<=100000: " << fsSize << '\n';
    cur = tmp;

    

}

//-------------------------------------------------------------------------------------
void fileSys::printContents(){
    cout << "----------------------------\n";
    cout <<  "contents in: " << cur->nameDir << endl;
    cout << "----------------------------\n";
    for(int  i=0; i < cur->children.size();++i){
        cout << cur->children[i].nameDir << endl;
    }
    for(int i=0; i<cur->contents.size();++i){
        cout << cur->contents[i].name << endl;
    }
}
//-------------------------------------------------------------------------------------
void fileSys::chDir(string chDir){

    cout <<  "changing from: " << cur->nameDir << endl;

    if(chDir == ".."){
        cur = cur->parent;
    }else if(chDir == "/"){
        cur = &root;
    }else{
        for(int i=0; i<cur->children.size();i++){
            if(cur->children[i].nameDir == chDir){
                cur = &cur->children[i];
            }
        }
    }

    cout << "to: " << cur->nameDir << endl;
};

void fileSys::addDir(string inDir){
    dir insert;
    insert.nameDir = inDir;
    insert.parent = cur;
    cur->children.push_back(insert);
};
//-------------------------------------------------------------------------------------
void fileSys::addFile(string nameF, int sizeF){
    file insert;
    insert.name = nameF;
    insert.size = sizeF;
    cur->contents.push_back(insert);
};