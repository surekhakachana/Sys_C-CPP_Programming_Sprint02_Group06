//definition file for validation

#include"Admin.h"
#include"Customer.h"

/*********************************************************
Function Name: product_code_validation
Parameters: code
Description: Validate the product code
*********************************************************/


int Product::product_code_validation(int code)
{
        int count = 0;
        while(code!=0)
        {
            code=code/10;
            count++;
        }
        if(count==4)
             return TRUE;
        else
             return FALSE;

}

/*********************************************************
Function Name: product_price_validation
Parameters: price
Description: Validate the product price
*********************************************************/

int Product::product_price_validation(int price)
{
    if(price!=0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



/*********************************************************
Function Name: product_discounte_validation
Parameters: discount
Description: Validate the product discount
*********************************************************/
int Product::product_discount_validation(int discount)
{
    if(discount!=0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



