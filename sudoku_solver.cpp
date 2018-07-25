#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sudoku[9][9];
int grids[9];
int rows[9];
int cols[9];
bool done=false;
int MAX=(1<<11)-1;

void print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<sudoku[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void solve(int i,int j){
    if(i==8&&j==9){
        print();
        done=true;
        return;
    }
    if(j==9){
        solve(i+1,0);
        return;
    }
    if(sudoku[i][j]!=0){
        solve(i,j+1);
        return;
    }
    
    int g=((i/3)*3)+(j/3);
    int pos = (~grids[g])&(~cols[j])&(~rows[i]);
    
    
    for(int p=1;p<=9&&!done;p++){
        if(pos&(1<<p)){
            //cout<<i<<" "<<j<<" "<<p<<endl;
            sudoku[i][j]=p;
            grids[g]|=(1<<p);
            rows[i]|=(1<<p);
            cols[j]|=(1<<p);
            //print();
            solve(i,j+1);
            sudoku[i][j]=0;
            //cout<<(MAX-(1<<p))<<endl;
            grids[g]&=(MAX-(1<<p));
            rows[i]&=(MAX-(1<<p));
            cols[j]&=(MAX-(1<<p));
        }
    }
}

int main() {
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
            int g=((i/3)*3)+(j/3);
            grids[g]|=(1<<sudoku[i][j]);
            rows[i]|=(1<<sudoku[i][j]);
            cols[j]|=(1<<sudoku[i][j]);
        }
    solve(0,0);
    return 0;
}
