#include<iostream>
#include<fstream>
#include<list>
#include"parts.h"
using namespace std;
void readFromFile(string fileToBeRead, parts &tempPart,int &count, int &numProducts);
void writeProductToFile(const parts &tempPart);
void writeVariantToFile(const parts &tempPart);
void entrySlot(string data, int &caseNumber,parts &tempPart,int &added);

int counter=1;
int main(){
    static int productsAdded=0;//Static counter to verify how many products were successfully read from file
    
    map<string,list<parts>> readProducts;//dictionary to hold an initial product, and respective variants to be added using only specific attributes
    parts tempProduct;//temporary product object used to add to map holding all products to be written to a file
    string theFile="limitedCatalog.csv";
    readFromFile(theFile,counter,productsAdded);
    tempProduct.showPart();

   return 0;
}
void readFromFile(string fileToBeRead,int &count,int &numProducts){
    parts tempPart;//temporary product object used to add to map holding all products to be written to a file
    string tempString;//Variable to hold parts of product attributes read from file for processing
    string productData;//Temporary variable to temporarily hold appended attributes of product information to be added to product object
    ifstream myFile;
    myFile.open(fileToBeRead);
    for(int i=0;i<44;i++){
        myFile>>tempString;
        //cout<<tempString<<endl;
    }
    myFile>>tempString;
    while(myFile){
        while (tempString!=","){
            productData.append(" ");
            productData.append(tempString);
            myFile>>tempString;
        }
        entrySlot(productData,count,tempPart,numProducts);

        productData.clear();
        myFile>>tempString;
    }
    myFile.close();
    tempPart.showPart();
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
        //tempPart.showPart();
        break;
    default:
        cout<<"THIS ISN't WORKING OUT!!!"<<endl<<endl<<endl<<endl<<endl;
        //tempPart.showPart();
        break;
    }
}