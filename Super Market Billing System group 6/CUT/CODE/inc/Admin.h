//header file 

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
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
class Admin
{
          public:
                 void Add_A_Product();
                 void Delete_A_Product();
                 void Search_A_Product();
                 void Modify_A_Product();
                 void Display_A_Products();
                 void Admin_Menu();
                 void Admin_Login();
          private:
                 int code,price;
                 char name[MAX];
                 float discount;
                 string Username,Password;
};
