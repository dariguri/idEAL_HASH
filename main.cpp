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
using namespace std;
int hash_function(int a,int b ,int p,int m,int x){//first level
    int hash=((a*x+b) % p) % m;
    return hash;
}

int main(int argc, const char * argv[]) {
    
    int a,b,p=107,m=100;
    srand(time( 0 ));
    a=rand() % (p-1) +1;
    b=rand() % p;
    cin>>m;
    vector <int> value(m);//values that will be hashed
    vector <vector <int >>hash_table(m) ;//create hash table
    for(int i=0;i<m;i++){
        cin>>value[i];
    }
    for(int i=0;i<m;i++){
        
        int hash = hash_function(a,b,p,m,value[i]);//find hash of initial values
        hash_table[hash].push_back(value[i]);
        
    }
    vector <vector <int >>ideal_table(m);//create ideal table
    vector<int>prmtr1(m);//parametr a for the second level fo rthe ideal table
    vector<int>prmtr2(m);//parametr a for the second level fo rthe ideal table
 
    for(int i=0;i<m;i++){
        prmtr1[i]=rand() % (p-1) +1;
        prmtr2[i]=rand() % p;
        int size=(int)hash_table[i].size();
        ideal_table[i].assign(size*size,-1);
    }
  
    for(int i=0;i<m;i++){
        int first_level_hash=hash_function(a,b,p,m,value[i]);
        int second_level_hash=hash_function(prmtr1[first_level_hash], prmtr2[first_level_hash], p, ideal_table.size(), value[i]);
        ideal_table[first_level_hash][second_level_hash]=value[i];
    }
    
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int number;
        cin>>number;
        int first_level_hash=hash_function(a,b,p,m,number);
        int second_level_hash=hash_function(prmtr1[first_level_hash], prmtr2[first_level_hash], p, ideal_table.size(), number);
        if(ideal_table[first_level_hash].size() && ideal_table[first_level_hash][second_level_hash]==number){
            cout<<"yes ,you found";
        }
        else{
            cout<<"no,there is not ";
        }
    }
    
    }

