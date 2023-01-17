//definition file for customer module
#include"Customer.h"
#define TRUE 1



/***************************************************************
Function Name: Customer_Menu()
Parameters: No Parameters
Description: display the customer menu
****************************************************************/

void Customer::Customer_Menu()
{
	int ch;
	while(1)
	{
	cout<<"\n1.Customer check product details\
	       \n2.Customer place order\
	       \n0.Exit"<<endl;
	cout<<"Enter the choice\n";
	cin>>ch;
	switch(ch)
	{
	    case CHECK:
		   cout<<"Check for the  product details"<<endl;
		   Customer_Check_Product_Details();
		   break;
	    case ORDER:
		   cout<<" customer place an order"<<endl;
		   Customer_Place_Order();
		   break;
		case EXIT:
		     exit(0);
		default:
		      cout<<"Invalid Choice"<<endl;
	}
	}
}

/***************************************************************
Function Name: Customer_Check_Product_Details()
Parameters: No Parameters
Description: Customer Can Check the product details
****************************************************************/

void Customer::Customer_Check_Product_Details()//customer see the details of the product
{
    fstream data;
    data.open("product.txt",ios::in);
    cout<<"\n\n--------------Display details of the Product----------------\n";
    cout<<"PName\t\tPro code\t\tPrice\t\t quantity\n";
    if(data.is_open())
    {
        string pname;
        while(getline(data,pname))
        {
            cout<<pname;
        }
        data.close();
        
    }

}






/***************************************************************
 Function Name: Customer_Place_Order()
Parameters: No Parameters
Description: customer place the order as per Customer needs
****************************************************************/

void Customer::Customer_Place_Order() 
{
    fstream data;
    int pcode;
    float quantity;
    int c=0;
    float price;
    float amount=0;
    float dis;
    float total;
    int choice;
    cout<<"\n---------------------------------------";
    data.open("product.txt",ios::in); 
    if(!data)
    {
        cout<<"\n\n Record is empty";
    }
    
    else
    {
        //data.close();
        Customer_Check_Product_Details();
        cout << "\n ---------PLEASE PLACE YOUR ORDER------------------";
        cout << "\n-------------------------------------\n";
        do
        {
            cout<<"\nEnter product name:";
            cin>>pname;
            cout<<"\nEnter product code:";
            cin>>pcode;
            cout<<"\nEnter the product price:";
            cin>>price;
            cout<<"\n\nEnter the product quantity:";
            cin>>quantity;
            cout<<"\nEnter discount on the product:";
            cin>>dis;
            
            for(int i=0;i<c;i++)
            {
                if(!data)
                {
                    cout<<"\n\nDuplicate product code.please try again ";
                    
                }
                
            }
            c++;
            cout<<"\n\n Do you want to buy another product? yes then press 1 else 0";
            cin>>choice;
            
        }while(choice!=0);
        cout<<"product is placed successfully";
        cout<<"\n\n--------------------RECEIPT------------------\n";
        cout<<"\nProductName\t ProductNo\t productprice\tproductquantity\t discount\n";
        
        for(int i=0;i<c;i++)
        {
            data.open("product.txt",ios::in);
            cout<<"\n"<<pname<<"\t\t"<<pcode<<"\t\t"<<price<<"\t\t"<<quantity<<"\t\t"<<dis;
            data>>pname>>pcode>>price>>quantity>>dis;
            //while(!data.eof()==0)
            
            if(!data.eof())
            {
                    amount=(price * quantity);
                    dis=((amount*dis)/100);
                    //total=toatl+dis;
                    total=amount-dis;
            }
        }data.close();
        
    }
    cout<<"\n\n--------------------------------------";
    cout<<"\namount:"<<amount;
    cout<<"\nDiscount:"<<dis;
    cout<<"\nTotal Amount :"<<total;
}
