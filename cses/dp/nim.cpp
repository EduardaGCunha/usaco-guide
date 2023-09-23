#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char nimGame(vector<int> piles, char player1,char player2){
    int xorSum=0;
    
    for(int i=0;i<piles.size();i++){
        xorSum^=piles[i];
    }
    if(xorSum!=0){
        return player1;
    }
    else return player2;
}

int main()
{
    vector<int> piles={3,4,5};
    char player1='A';
    char player2='B';
    char winner=nimGame(piles,player1,player2);
    cout<<"Winner is Player "<<winner<<endl;
}