#include "parts.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
parts:: parts()
{
    optionNames="Title";
    optionValues="default Title";
    handle="";
    title="";
    body="";
    vendor="";
    type="";
    publish=true;
    variantSkuNum="";
    variantGrams=0;
    variantInvQty=0;
    variantInvPolicy="";
    variantFulfillService="";
    variantPrice=0.00;
    varCompareAtPrice=0.00;
    varRequiresShipping=true;
    imageSrc="";
    imagePosition=1;
    imageAltText="";
    seoTitle="";
    seoDescription="";
    variantImage="";
    variantWeightUnits="";
    costPerItem=0.00;
}

parts:: ~parts(){

}

void parts::setHandle(string newhandle)
    {handle=newhandle;}

void parts::setTitle(string newTitle)
    {title=newTitle;}

void parts::setBody(string newBody){
    body.append(". ");
    body.append(newBody);
    }

void parts::setVendor(string newVendor)
    {vendor=newVendor;}

void parts::setType(string productType)
    {type=productType;}

void parts::setTags(const vector<string> &productTags)
    {tags=productTags;}

void parts::setPublish(bool published)
    {publish=published;}

void parts::setOptionName(string optionName)
    {optionNames=optionName;}

void parts::setOptionValues(string optionVal)
    {optionValues=optionVal;}

void parts::setSku(string newSKU)
    {variantSkuNum=newSKU;}

void parts::setWeightInGrams(int weight)
    {variantGrams=weight;}

void parts::setInventoryQuantity(int quantity)
    {variantInvQty=quantity;}

void parts::setInventoryPolicy(string policy)
    {variantInvPolicy=policy;}

void parts::setFulfillService(string service)
    {variantFulfillService=service;}

void parts::setPrice(float price)
    {variantPrice=price;}

void parts::setCompareAtPrice(float comparePrice)
    {varCompareAtPrice=comparePrice;}

void parts::setShippingStatus(bool shippingRequired)
    {varRequiresShipping=shippingRequired;}

void parts::setImageSource(string imageSource)
    {imageSrc=imageSource;}

void parts::setImagePosition(int newimagePosition)
    {imagePosition=newimagePosition;}

void parts::setAltText(string newaltText)
    {imageAltText=newaltText;}

void parts::setSEOTitle(string newseoTitle)
    {seoTitle=newseoTitle;}

void parts::setSEODescription(string newseoDescription)
    {seoDescription=newseoDescription;}

void parts::setVarImage(string newvarImage)
    {variantImage=newvarImage;}

void parts::setWeightUnits(string weightUnits)
    {variantWeightUnits=weightUnits;}

void parts::setCostPerItem(float newcostPerItem)
    {costPerItem=newcostPerItem;}

void parts::setTempTitle(string holder){
    parseThis=holder;
}

string parts::getHandle()
    {return handle;}

string parts::getTitle()
    {return title;}

string parts::getBody()
    {return body;}

string parts::getVendor()
    {return vendor;}

string parts::getType()
    {return type;}

void parts::getTags(vector<string> &productTags){
    for(int i=0;i<maxAmountOfTags;i++){
        productTags.push_back(tags[i]);
    }
}

string parts::getPublish(){
    if(publish==true) 
        return "true";
    else 
        return "false";
}

string parts::getOptionName(){
    return optionNames;
}

string parts::getOptionValues(){
    return optionValues;
}

string parts::getSku()
    {return variantSkuNum;}

int parts::getWeightInGrams()
    {return variantGrams;}

int parts::getInventoryQuantity()
    {return variantInvQty;}

string parts::getInventoryPolicy()
    {return variantInvPolicy;}

string parts::getFulfillService()
    {return variantFulfillService;}

float parts::getPrice()
    {return variantPrice;}

float parts::getCompareAtPrice()
    {return varCompareAtPrice;}

string parts::getShippingStatus(){
    if(varRequiresShipping==true)
        return "true";
    else
        return "false";
}

string parts::getTaxStatus(){
    if(varIsTaxable==true)
        return "true";
    else
        return "false";
}

string parts::getImageSource()
    {return imageSrc;}

int parts::getImagePosition()
    {return imagePosition;}

string parts::getAltText()
    {return imageAltText;}

string parts::getGiftCardStatus(){
    if(giftCard==true)
        return "true";
    else
        return "false";
}

string parts::getSEOTitle()
    {return seoTitle;}

string parts::getSEODescription()
    {return seoDescription;}

string parts::getVarImage()
    {return variantImage;}

string parts::getWeightUnits()
    {return variantWeightUnits;}

float parts::getCostPerItem()
    {return costPerItem;}

string parts::getVariantTaxCode(){
    if(variantTaxCode==true)
        return "true";
    else
        return "false";
}

void parts::showPart(){
    cout<<"Handle: "<<handle<<endl
    <<"Title: "<<title<<endl
    <<"body: "<<body<<endl<<endl
    <<"vendor: "<<vendor<<endl
    <<"type: "<<type<<endl;

    for(int i=0;i<tags.size();i++){
        cout<<tags[i]<<" ";
    }
    cout<<endl<<"Publish: "<<publish<<endl;
    cout<<"Options: "<<optionNames<<endl;
    cout<<"Option Value: "<<optionValues<<endl;
    cout<<endl<<"variantSkuNum: "<<variantSkuNum<<endl
    <<"variantGrams: "<<variantGrams<<endl
    <<"variantInventoryTracker: "<<variantInventoryTracker<<endl
    <<"variantInvQty: "<<variantInvQty<<endl
    <<"variantInvPolicy: "<<variantInvPolicy<<endl
    <<"variantFulfillService: "<<variantFulfillService<<endl
    <<"variantPrice: "<<variantPrice<<endl
    <<"varCompareAtPrice: "<<varCompareAtPrice<<endl
    <<"varRequiresShipping: "<<getShippingStatus()<<endl
    <<"varIsTaxabletrue: "<<getTaxStatus()<<endl
    <<"imageSrc: "<<imageSrc<<endl
    <<"imagePosition: "<<imagePosition<<endl
    <<"imageAltText: "<<imageAltText<<endl
    <<"giftCard: "<<getGiftCardStatus()<<endl
    <<"seoTitle: "<<seoTitle<<endl
    <<"seoDescription: "<<seoDescription<<endl
    <<"variantImage: "<<variantImage<<endl
    <<"variantWeightUnits: "<<variantWeightUnits<<endl
    <<"variantTaxCode: "<<getVariantTaxCode()<<endl
    <<"costPerItem: "<<costPerItem<<endl
    <<"Size: "<<parseThis<<endl;
}

string parts::writePartToFile(){
    string partData;
    partData=getHandle()+",";
    partData.append(",");
    partData.append(getTitle()+",");
    return partData;
}

string parts::getTempTitle(){
    return parseThis;
}