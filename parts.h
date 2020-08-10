#include<string>
#include<vector>
#include<map>
using namespace std;
const int maxAmountOfTags=10;
const int maxOptionNames=3;
const int maxOptions=12;

class  parts
{
 private: // data members hidden from the client
    
    string handle;
    string title;
    string body;
    string vendor;
    string type;
    vector<string> tags;
    bool publish;
    string optionNames;
    string optionValues;
    string variantSkuNum;
    int variantGrams;
    const string variantInventoryTracker="";
    int variantInvQty;
    string variantInvPolicy;
    string variantFulfillService;
    float variantPrice;
    float varCompareAtPrice;
    bool varRequiresShipping;
    const bool varIsTaxable=true;
    string imageSrc;
    int imagePosition;
    string imageAltText;
    const bool giftCard=false;
    string seoTitle;
    string seoDescription;
    string variantImage;
    string variantWeightUnits;
    const bool variantTaxCode=false;
    float costPerItem;
    string parseThis;

 public: // available to the client
   parts();
   ~parts();
   void setHandle(string handle);
   void setTitle(string newTitle);
   void setBody(string newBody);
   void setVendor(string newVendor);
   void setType(string productType);
   void setTags(const vector<string> &productTags);
   void setPublish(bool published);
   void setOptionName(string optionName);
   void setOptionValues(string optionVal);
   void setSku(string newSKU);
   void setWeightInGrams(int weight);
   void setInventoryQuantity(int quantity);
   void setInventoryPolicy(string policy);
   void setFulfillService(string service);
   void setPrice(float price);
   void setCompareAtPrice(float comparePrice);
   void setShippingStatus(bool shippingRequired);
   void setImageSource(string imageSource);
   void setImagePosition(int newimagePosition);
   void setAltText(string newaltText);
   void setSEOTitle(string newseoTitle);
   void setSEODescription(string newseoDescription);
   void setVarImage(string newvarImage);
   void setWeightUnits(string weightUnits);
   void setCostPerItem(float newcostPerItem);
   void setTempTitle(string holder);

   string getHandle();
   string getTitle();
   string getBody();
   string getVendor();
   string getType();
   void getTags(vector<string> &productTags);
   string getPublish();
   string getOptionName();
   string getOptionValues();
   string getSku();
   int getWeightInGrams();
   int getInventoryQuantity();
   string getInventoryPolicy();
   string getFulfillService();
   float getPrice();
   float getCompareAtPrice();
   string getShippingStatus();
   string getTaxStatus();
   string getImageSource();
   int getImagePosition();
   string getAltText();
   string getGiftCardStatus();
   string getSEOTitle();
   string getSEODescription();
   string getVarImage();
   string getWeightUnits();
   string getVariantTaxCode();
   float getCostPerItem();
   string getTempTitle();

   void showPart();
   string writePartToFile();

};   
// don't forget the semicolon at the end.