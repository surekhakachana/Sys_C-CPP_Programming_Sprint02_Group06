//header file
#include<iostream>
#include<fstream>
//#include<stdlib.h>
//#include<string.h>
#include<vector>

using std::cout;using std::cerr;
using std::endl;using std::string;
using std::ifstream;using std::vector;
using namespace std;

//define macros
#define ADD 1
#define DELETE 2
#define SEARCH 3
#define MODIFY 4
#define DISPLAY 5
#define EXIT 0
#define MAX 30
#define TRUE 1
#define FALSE 0
class Product
{
          public:
                 void Add_A_Product();
                 void Delete_A_Product();
                 int Search_A_Product();
                 void Modify_A_Product();
                 int Display_A_Products();
                 void Admin_Menu();
                 void Admin_Login();
                 int product_code_validation(int);
                 int product_price_validation(int);
                 int product_discount_validation(int);
                
          private:
                 int code,price;
                 char name[MAX];
                 float discount;
                 string Username,Password;
};