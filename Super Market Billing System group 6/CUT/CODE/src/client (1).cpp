#include"Admin.h"
#include"Customer.h"
#define ADMIN 1
#define CUSTOMER 2
int main()
{
            int ch;
            Admin adm;
            Customer ctm;
            cout<<"1 for ADMIN\n\n2 for CUSTOMER\n\n0 for EXIT"<<endl;
            cout<<"Enter the choice\n"<<endl;
            cin>>ch;
             switch(ch)
            {
                     case ADMIN:
                             adm.Admin_Login();
                             break;
                      case CUSTOMER:
                             ctm.Customer_Menu();
                             break;
                      case EXIT:
                             exit(0);
                      default:
                             cout<<"Invalid Choice"<<endl;
             }
             return 0;

}