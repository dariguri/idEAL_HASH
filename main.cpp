//
//  main.cpp
//  laba1algopart2
//
//  Created by Guryanova Dasha on 25.02.18.
//  Copyright © 2018 Guryanova Dasha. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>
#include <list>
using namespace std;
int hash_function(int a,int b ,int p,int m,int x){//first level
    int hash=((a*x+b) % p) % m;
    return hash;
}
struct perfect_hash_table{
private:
    vector <vector <int >>ideal_table;//create ideal table
    vector<int>prmtr1;//parametr a for the second level fo rthe ideal table
    vector<int>prmtr2;//parametr a for the second level fo rthe ideal table
    int a, b, p = 107, m;
    vector <list <int > >hash_table;
    
    void first_level_hash(vector<int> & value, int cnt){//function that calculate elements hash on the first level
        a=rand() % (p-1) +1;
        b=rand() % p;
        m=cnt;
        for(int i=0;i<m;i++){
            int hash = hash_function(a,b,p,m,value[i]);//find hash of initial values
            hash_table[hash].push_back(value[i]);
            
        }
    }
    void second_level_hash(){//function that calculate elements hash on the second level
        for(int i=0;i<m;i++){
            prmtr1[i]=rand() % (p-1) +1;
            prmtr2[i]=rand() % p;
            int size=(int)hash_table[i].size();
            ideal_table[i].assign(size*size,-1);
        }
        
        for(int i=0;i<m;i++){
            for(auto value: hash_table[i]){
                int second_level_hash=hash_function(prmtr1[i], prmtr2[i], p, ideal_table.size(), value);
                ideal_table[i][second_level_hash]=value;
            }
            hash_table[i].clear();
        }
    }
public:
    perfect_hash_table(vector<int> & value, int m){
        ideal_table.resize(m);
        prmtr1.resize(m);
        prmtr2.resize(m);
        hash_table.resize(m);
        
        first_level_hash(value, m);
        second_level_hash();
    }
    
    bool search(int key){
        int first_level=hash_function(a,b,p,m,key);
        int second_level=hash_function(prmtr1[first_level], prmtr2[first_level], p, ideal_table.size(), key);
        return (ideal_table[first_level].size() && ideal_table[first_level][second_level]==key);
            
    }
    
};


int main(int argc, const char * argv[]) {
    
    int a,b,p=107,m=100;
    srand(time( 0 ));
    
    cin>>m;
    vector <int> value(m);//values that will be hashed
    
    for(int i=0;i<m;i++){
        cin>>value[i];
    }
    
  
    perfect_hash_table table(value, m);
    
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int number;
        cin>>number;
        if(table.search(number)){
            cout<<"yes ,you found";
        }
        else{
            cout<<"no,there is not ";
        }
    }
    
    }

