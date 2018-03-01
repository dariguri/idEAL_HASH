//
//  main.cpp
//  laba4algopart2
//
//  Created by Guryanova Dasha on 01.03.18.
//  Copyright © 2018 Guryanova Dasha. All rights reserved.
//

#include <iostream>
#include<vector>

using namespace std;
double max=1e9;

double optimal_binary_tree(vector <double > p,vector <double> q,int n){  //p-probbility of real keys ,q-probability of dummy keys
    double e[n+1][n];//array for calculating mathematical expectation
    int root[n][n] ;
    double w[n+1][n];//aray for calculating
    
    for (int i=0;i<n+1;i++){
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
        
    }
    for(int l=1;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            e[i][j]=1e9;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int r=i;r<j;r++){
                int k=e[i][r-1]+e[r+1][j]+w[i][j];//formula which help us calculating math expactation
                if(k<e[i][j]){
                    e[i][j]=k;
                    root[i][j]=r;
                }
            }
        }
       
    }
    //after thi cycle we have optimal math expectation ,so we can build optimal binary tree by information that we get before(root array)
    
}
    
int main(int argc, const char * argv[]) {
    return 0;
}
