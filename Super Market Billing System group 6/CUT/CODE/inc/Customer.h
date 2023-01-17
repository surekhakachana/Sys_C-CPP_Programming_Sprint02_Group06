#include<string.h>
using namespace std;

//define macros
#define YES 1
#define SIZE 50
#define CHECK 1 
#define ORDER 2 
#define EXIT 0 

class Customer
{
    public:
      void Customer_Menu();
      void Customer_Check_Product_Details();
	  void Customer_Place_Order();
    private:
	  string pname;
	  int pcode;
	  float price,dis,quantity;
};