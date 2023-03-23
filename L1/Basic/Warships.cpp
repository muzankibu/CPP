#include<iostream>
using namespace std;
int main(){
    cout<<"Hello";
    cout<<"\nWelcome to Battleship OG";

bool crdnt[4][4]={{ 0, 1, 1, 0 },{ 0, 0, 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 1, 0 }};
  int hit=0;
  int no=0;
  while(hit<4){
    int x,y;
    cout<<"\nenter x and y coordinate:";
    cin>>x>>y;
    if(crdnt[x][y]){
        cout<<"boom!Its a hit!";
        crdnt[x][y]=0;
        hit++;
        cout<<"\n"<<4-hit<<" Ships left!";
    }else{
        cout<<"\nMiss fire!";
        cout<<"\n"<<4-hit<<" Ships left!";
    }
  no++;
  }
  cout<<"\nYou finished in"<<no<<" turns";
}