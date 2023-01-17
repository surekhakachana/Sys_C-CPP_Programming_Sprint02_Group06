//definition for admin
#include"Admin.h"

/***************************************************************
Function Name: Admin_Login()
Parameters: No Parameters
Description: Admin can login into the system
****************************************************************/

void Admin::Admin_Login()
{
    cout<<"Enter the username and password for admin login\n";
    string  username, password;
    ifstream file;
    file.open("Admin.txt");
    if(!file)
    {
       cout<<"Error creating file!";
    }
    else
    {
       cout<<"Enter Username: ";
       cin>>Username;
       cout<<"Enter Password: ";
       cin>>Password;

    }
    file >> username;
    file >> password;
    if(username==Username && password==Password)
    {
        cout<<"Logged in Successfully!!"<<endl;
        Admin_Menu();
    }
    else
    {
       cout<<"Login Failed!"<<endl;
       Admin_Login();
    }
   file.close();
}


/***************************************************************
Function Name: Admin_Menu()
Parameters: No Parameters
Description: display the admin menu
****************************************************************/

void Admin::Admin_Menu()
{
    int ch;
    while(1)
    { 
        cout<<"------------------ADMIN MENU------------------------------";
        cout<<" \n\n1 for Add A Product\n\n2for Delete  A Product\n\n3 for Search A Product \n\n4 for Modify A Product\n\n5 for Display A Product\n\n0 for Exit"<<endl;
        cout<<"Enter the choice\n"<<endl;
        cin>>ch;
        switch(ch)
        {
            case ADD:
                      cout<<"Add the product details to the supermarket\n";
                      Add_A_Product();
                      break;
            case DELETE:
                      cout<<"Delete the product details to the supermarket\n";
                      Delete_A_Product();
                      break;
            case SEARCH:
                      cout<<"Search the product details to the supermarket\n";
                      Search_A_Product();
                      break;
            case MODIFY:
                      cout<<"Modify the product details to the supermarket\n";
                      Modify_A_Product();
                      break;
            case DISPLAY:
                      cout<<"Display the product details in the supermarket\n";
                      Display_A_Products();
                      break;
            case EXIT:
                      exit(0);
            default:
                      cout<<"Invalid Choice"<<endl;
        }
    }
}


/***************************************************************
Function Name: Add_A_Product()
Parameters: No Parameters
Description: Admin Can add the product details
****************************************************************/

void Admin::Add_A_Product()
{
        system("clear");
        fstream file;
        cout<<"----------------------Add Product Details----------------------"<<endl;
        cout<<"\nEnter Product Name: ";
        cin>>name;
        cout<<"\nEnter Product Code: ";
        cin>>code;
        cout<<"\nEnter product price: ";
        cin>>price;
        cout<<"\nEnter product discount: ";
        cin>>discount;
        cout<<"\n-----------------------------------------------------------"<<endl;
        file.open("product.txt",ios::app | ios::out);
        file<< " " <<name<< " " << " " <<code<< " " <<price<< " " <<discount<<" "<<"\n";
        file.close();
        cout<<endl;
}


/***************************************************************
Function Name: Display_A_Product()
Parameters: No Parameters
Description: Admin Can display the product details
****************************************************************/

void Admin::Display_A_Products()
{
        fstream file;
        int total = 1;
        cout<<"------------------Display Product details------------------------"<<endl;
        file.open("product.txt",ios::in);
        if(!file)
        {
                cout<<"File cannot be open"<<endl;
                file.close();
        }
        else
        {
                file>> name >> code >> price >> discount;
                while(!file.eof())
                {
                        cout<<"\n\n\t\tProduct No: "<<total++<<endl;
                        cout<<"\t\t\tProduct Name: "<<name<<endl;
                        cout<<"\t\t\tProduct code: "<<code<<endl;
                        cout<<"\t\t\tProduct Price: "<<price<<endl;
                        cout<<"\t\t\tProduct Discount: "<<discount<<endl;
                        file>> name >> code >> price >> discount;
                }
		if(total == 0)
                {
                        cout<<"No Data is found"<<endl;
                }
        }
        cout<<"\n------------------------------------------------------------------"<<endl;
        file.close();
}


/***************************************************************
Function Name: Search_A_Product()
Parameters: No Parameters
Description: Admin Can search the product details
****************************************************************/

void Admin::Search_A_Product()
{
        system("clear");
        fstream file;
        int found = 0;
        int pcode;
        file.open("product.txt",ios::in);
        if(!file)
        {
                cout<<"Data is not present"<<endl;
        }
        else
        {
                cout<<"-------------------Search Product Details----------------------------"<<endl;
                cout<<"\nEnter the code of project to be searched: "<<endl;
                cin>>pcode;
                file >> name >> code >> price >> discount;
                while(!file.eof())
                {
                        if(pcode == code)
                        {
				                cout<<"\nProduct Name: "<<name<<endl;
                                cout<<"\nProduct Code: "<<code<<endl;
                                cout<<"\nProduct Price: "<<price<<endl;
                                cout<<"\nProduct Discount: "<<discount<<endl;
                                found++;
                        }
                        file >> name >> code >> price >> discount;
                        if (found == 0)
                        {
                                cout<<"Product Code not found"<<endl;
                        }
                }
                file.close();
        }
}
		

/***************************************************************
Function Name: Modify_A_Product()
Parameters: No Parameters
Description: Admin Can modify the product details
****************************************************************/

void Admin::Modify_A_Product()
{
        system("clear");
        fstream file,file1;
        int pcode;
        int found = 0;
        cout << "--------------- Product Modify Details -------------" << endl;
        file.open("product.txt", ios::in);
        if (!file)
        {
            cout << "\n\t\t\tNo Data is Present.."<<endl;
            file.close();
        }
        else
        {
            cout << "\nEnter Code of Product which you want to Modify: ";
            cin >> pcode;
            file1.open("precord.txt", ios::app | ios::out);
            file >> name >> code >> price >> discount;
            while (!file.eof())
            {
                if (pcode != code)
                {
                      file1 << " " << name << " " << code << " " << price << " " << discount << "\n" ;
                }
                else
                {
		            	cout << "\n\t\tEnter Product Name: ";
                    	cin >> name;
                    	cout << "\t\t\tEnter Product Code: ";
                    	cin >> code;
                    	cout << "\t\t\tEnter Product Price: ";
                    	cin >> price;
                    	cout << "\t\t\tEnter Product Discount: ";
                    	cin >> discount;
			            file1 << " " << name << " " << code << " " << price << " " << discount << "\n" ;
                  	    found++;
                }
                file >> name >> code >> price >> discount;
                cout<<endl;
            }
            if (found == 0)
            {
                cout << "\n\n Product Not Found...."<<endl;
            }
            file1.close();
            file.close();
            remove("product.txt");
            rename("precord.txt", "product.txt");
        }
}


/***************************************************************
Function Name: Delete_A_Product()
Parameters: No Parameters
Description: Admin Can delete the product details
****************************************************************/

void Admin::Delete_A_Product()
{
        system("clear");
        cout<<"----------------------------Delete Product Details------------------------------"<<endl;
        fstream file,file1;
        int found = 0;
        int pcode;
        file.open("product.txt",ios::in);
        if(!file)
        {
                cout<<"No data is present"<<endl;
                file.close();
        }
        else
        {
                cout<<"\nEnter the code of the product to be deleted: "<<endl;
                cin>>pcode;
                file1.open("precord.txt",ios::app|ios::out);
                file>> name >> code >> price >> discount;
                while(!file.eof())
                {
                        if(pcode!=code)
                        {
                                file1<< " " <<name<< " " << " " <<code<< " " << " " <<price<< " " <<discount<<" "<<"\n";
                        }
                        else
                        {
                                found++;
                                cout<<"Successfully deleted"<<endl;
                        }
                        file>> name >> code >> price >> discount;
                        cout<<endl;
                }
		if(found == 0)
                {
                        cout<<"Product  no not found"<<endl;
                }
                file1.close();
                file.close();
                remove("product.txt");
                rename("precord.txt", "product.txt");
        }
}
