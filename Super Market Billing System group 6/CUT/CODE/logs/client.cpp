#include<iostream>
using namespace std;
#include "product.h"
#include "Logger.h"
int main()
{
        cout<<"Super Market Billing System";
        LOG_INFO("Product id is %d\n",product(234));
        LOG_INFO("Product id is %d\n",product(456));
        return 0;
}