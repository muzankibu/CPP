#include<iostream>
using namespace std;
int main(){
    struct{
        int carnum;
        string name;
        double price;
    }mycar1, mycar2;

     mycar1.carnum=2022;
     mycar1.name="Toyota";
     mycar1.price=2001256.2;
     mycar2.carnum=2222;
     mycar2.name="Skoda";
     mycar2.price=20010006.2;
cout<<mycar1.carnum<<" "<<mycar1.name<<" "<<mycar1.price<<"\n";
cout<<mycar2.carnum<<" "<<mycar2.name<<" "<<mycar2.price<<"\n";
}