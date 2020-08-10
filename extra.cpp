#include<iostream>
#include<fstream>
#include<map>
#include<list>
#include<string>
//#include"parts.h"
using namespace std;

int main(){
string tempString;
string tempName;
//parts tempProduct;
//map<string,list<parts>>  readProducts;

fstream myFile;
myFile.open("myStuff.csv");
int x=3;
int y=0;
    while(y<=x){
        cout<<"Enter your first input:   ";
        cin>>tempString;
        tempString.push_back(',');
        myFile<<tempString;
        y++;
    }
    tempString="Now reading from file: ";
    cout<<tempString<<endl<<"*****"<<endl;
    myFile.close();

    ifstream readFile("myStuff.csv");
    while(getline(readFile,tempString))
    {
        cout<<tempString<<endl;
    }
    readFile.close();
}