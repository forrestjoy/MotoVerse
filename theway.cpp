#include<iostream>
#include<fstream>
#include<list>
#include"parts.h"
using namespace std;
void entrySlot(string data, int &caseNumber,parts &tempPart,int &added);

int counter=1;
int main(){
    static int productsAdded=0;
    string tempString;
    string productData;
    parts tempProduct;
    ifstream myFile;

    myFile.open("limitedCatalog.csv");
    for(int i=0;i<44;i++){
        myFile>>tempString;
    }
    myFile>>tempString;
    while(myFile){
        while (tempString!=","){
            productData.append(" ");
            productData.append(tempString);
            myFile>>tempString;
        }
        entrySlot(productData,counter,tempProduct,productsAdded);
        productData.clear();
        myFile>>tempString;
    }
    cout<<"closing";
    myFile.close();
    tempProduct.writePartToFile();
    return 0;
}
void entrySlot(string data, int &caseNumber,parts &tempPart,int &added){
    string placeHolder;
    float floatHolder;
    switch (caseNumber){
    case 1:
        caseNumber++;
        break;
    case 2:
        tempPart.setSku(data);
        caseNumber++;
        break;
    case 3: 
        caseNumber++;
        break;
    case 4:
        tempPart.setHandle(data);
        caseNumber++;
        break;
    case 5:
        caseNumber++;
        break;
    case 6:
        tempPart.setVendor(data);
        caseNumber++;
        break;
    case 7:
        caseNumber++;
        break;
    case 8:
        caseNumber++;
        break;
    case 9:
        caseNumber++;
        break;
    case 10: 
        caseNumber++;
        break;
    case 11:
        tempPart.setPrice(stof(data));
        caseNumber++;
        break;
    case 12:
        floatHolder=stof(data);
        tempPart.setCompareAtPrice(floatHolder);
        caseNumber++;
        break;
    case 13:
        tempPart.setImageSource(data);
        caseNumber++;
        break;
    case 14:
        caseNumber++;
        break;
    case 15:
        tempPart.setHandle(data);
        caseNumber++;
        break;
    case 16:
        caseNumber++;
        break;
    case 17:
        tempPart.setBody(data);
        caseNumber++;
        break;
    case 18:
        tempPart.setBody(data);
        caseNumber++;
        break;
    case 19:
        tempPart.setBody(data);
        caseNumber++;
        break;
    case 20:
        tempPart.setBody(data);
        caseNumber++;
        break;
    case 21:
        tempPart.setBody(data);
        caseNumber++;
        break;
    case 22:
        tempPart.setBody(data);
        caseNumber=1;
        cout<<"Product "<<++added<<": ***********************************"<<endl;
        tempPart.showPart();
        break;
    default:
        cout<<"THIS ISN't WORKING OUT!!!"<<endl<<endl<<endl<<endl<<endl;
        tempPart.showPart();
        break;
    }
}