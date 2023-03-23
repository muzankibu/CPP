#include<iostream>
using namespace std;
int main()
{
    float num;
    cout<<"Enter your number:";
    cin>>num;
    String result=(num==0)?"The number is nuetral":(num>0)?"Greater than 0":"Less than 0";
    cout<<result;
}