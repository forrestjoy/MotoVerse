#include<iostream>
#include<fstream>
#include<list>
#include"parts.h"
using namespace std;

void entrySlot(string data, int &caseNumber,parts &tempPart,int &added);
void addToMap(parts &temporaryPart,map<string,list<parts>> &tempMap);
string parseOptionValues(string parseIt);
map<string,list<parts>> readProducts;/*dictionary to hold an initial product,
and respective variants to be added using only specific attributes*/
int counter=1;

int main(){
    static int productsAdded=0;
    string tempString;
    string productData;
    parts tempProduct;
    list<parts> printList;
    ifstream myFile;
//reading from file
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
    myFile.close();

    ofstream write;
    write.open("outputFile.csv");
    write<<"Handle,"<<"Title,"<<"Body,"<<"(HTML),"<<"Vendor,"
    <<"Type,"<<"Tags,"<<"Published,"<<"Option1 Name,"<<"Option1 Value,"
    <<"Option2 Name,"<<"Option2 Value,"<<"Option3 Name,"<<"Option3 Value,"<<"Variant SKU,"<<"Variant Grams,"
    <<"Variant Inventory Tracker,"<<"Variant Inventory Qty,"<<"Variant Inventory Policy,"
    <<"Variant Fulfillment Service,"<<"Variant Price,"<<"Variant Compare At Price,"
    <<"Variant Requires Shipping,"<<"Variant Taxable,"<<"Variant Barcode,"<<"Image Src,"<<"Image Position,"	
    <<"Image Alt Text,"<<"Gift Card,"<<"SEO Title,"<<"SEO Description,"<<"Google Shopping / Google Product Category,"
    <<"Google Shopping / Gender,"<<"Google Shopping / Age Group,"<<"Google Shopping / MPN,"
    <<"Google Shopping / AdWords Grouping,"<<"Google Shopping / AdWords Labels,"<<"Google Shopping / Condition,"
    <<"Google Shopping / Custom Product,"<<"Google Shopping / Custom Label 0,"<<"Google Shopping / Custom Label 1,"
    <<"Google Shopping / Custom Label 2,"<<"Google Shopping / Custom Label 3,"<<"Google Shopping / Custom Label 4,"
    <<"Variant Image,"<<"Variant Weight Unit,"<<"Variant Tax Code,"<<"Cost per item,";
    write.close();




    map<string,list<parts>>::iterator it=readProducts.begin();
    while (it!=readProducts.end()){
        
        list<parts>::iterator lit;
        for(lit=it->second.begin();lit!=it->second.end();lit++){
            cout<<"Product: "<<lit->getHandle()<<endl;
            cout<<"\tOption: "<<lit->getOptionName()<<endl;
            cout<<"\tOption Value: "<<lit->getOptionValues()<<endl<<endl;
            //lit->showPart();
            //cout<<lit->writePartToFile();
        }
//        cout<<it->first<<"  "<<"size: ";
//        cout<<it->second.size()<<endl;
        //printList=it->second;
        
        it++;
    }
    

    myFile.close();
    tempProduct.writePartToFile();
    return 0;
}

/*********************************************************************************************/
void entrySlot(string data, int &caseNumber,parts &tempPart,int &added){
    string placeHolder;
    float floatHolder;
    list<parts> listPartTemp;
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
        tempPart.setTempTitle(data);
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
        tempPart.setCostPerItem(stof(data));
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
        tempPart.setTitle(data);
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
        addToMap(tempPart,readProducts);
        break;
    default:
        cout<<"THIS ISN't WORKING OUT!!!"<<endl<<endl<<endl<<endl<<endl;
        tempPart.showPart();
        break;
    }
}
//addToMap function//
/*
This function serves the purpose of adding parts to a map containing a string, and a list of parts.
The Key for this map 
*/
void addToMap(parts &temporaryPart, map<string,list<parts>> &tempMap){
    list<parts> partsList;
    string optionTemp;
    partsList.push_back(temporaryPart);
    
    if(tempMap.find(temporaryPart.getHandle())!=tempMap.end()){
        /*
            The 4 lines within the if condition:
                1. set the option name of the temporary part which is already inserted in the map.
                2. get the string in the tempPart object which contains the size information.
                3. parse said string for the size information which is contained at the end of the string
                4. set that option value within the part which is the first element in the list of parts 
                containing the same handle which is how the parts will be identified within the file they're
                being written to.
        */
        if(tempMap[temporaryPart.getHandle()].begin()->getOptionName()!="size"){
            tempMap[temporaryPart.getHandle()].begin()->setOptionName("size");
            optionTemp=tempMap[temporaryPart.getHandle()].begin()->getTempTitle();
            optionTemp=parseOptionValues(optionTemp);
            tempMap[temporaryPart.getHandle()].begin()->setOptionValues(optionTemp);
        }
////
        cout<<"editing: "<<temporaryPart.getHandle()<<endl;
        temporaryPart.setOptionName("size");
        optionTemp=temporaryPart.getTempTitle();
        optionTemp=parseOptionValues(optionTemp);
        temporaryPart.setOptionValues(optionTemp);
        tempMap[temporaryPart.getHandle()].push_back(temporaryPart);
    }
    else{
        //cout<<"Inserting product: "<<temporaryPart.getHandle()<<endl;
        tempMap.insert(pair<string,list<parts>>(temporaryPart.getHandle(),partsList));
    }
}

string parseOptionValues(string parseIt){
    int iter;
    string extracted;
    string space="a";
    iter=parseIt.size();
        int i=iter;
        while (i>0&&space!=" "){
            space=parseIt[i];
            extracted.insert(0,space);
            i--;
        }
    return extracted;
}