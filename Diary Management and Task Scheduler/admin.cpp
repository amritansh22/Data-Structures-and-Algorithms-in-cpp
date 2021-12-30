#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include <fstream>
#include"admin.h"
#include"login.h"
using namespace std;

//ADMIN
void view_acc()
{
    int l=0;
    l=ad_login();
    if(l==0)
        return;
    else
    {
        cout<<"\t\t\t\t\tADMIN\n\n";
        cout<<"\t\tAccounts:\n";
        ifstream file ("users.txt");
        cout<<"\t\tUsername   Password\n";
        string user, pass;
        while(file>>user >> pass)
        {
            cout<<"\t\t"<<user<<"    "<<pass<<"\n";
        }
        file.close();
    }
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
}

int del_acc()
{
    int l=0;
    char v;
    l=ad_login();
    if(l==0)
        return 1;
    else
    {
        string del_user, user,pass;
        cout<<"\t\t\t\t\tADMIN\n\n";
        cout<<"\t\tDeletion\n";
        cout<<"\t\tEnter the username to be deleted: ";
        cin>>del_user;
        ifstream myfile;
        myfile.open("users.txt");
        ofstream temp;
        temp.open("temp.txt");
        while (myfile>>user>>pass)
        {
          if (user!=del_user)
            temp << user <<" "<<pass << endl;
        }
        myfile.close();
        temp.close();
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
    cout<<"\t\tDo you want to see all the accounts in the system?[y/n]\n";
    cin>>v;
    if(v=='y')
    {
        cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
        return 0;
    }
    else
    {
        cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
        return 1;
    }

}

void change_ad_pass()
{
    int i=0,j;
    char pass[32]={0};
    ifstream myfile;
    myfile.open("users.txt");
    ofstream temp;
    temp.open("temp.txt");
    string user;
    while (myfile>>user>>pass)
    {
        if (user=="admin")
        {
            cout<<"\t\t\tEnter New Password Admin\n";
            i=0;
            pass[0]=getch();
            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    pass[i]=getch();
                }
                else
                {
                    cout<<"*";
                    i++;
                    pass[i]=getch();
                }
            }
            pass[i]='\0';
            temp<<user<<" "<<pass<<endl;
        }
    }
    myfile.close();
    temp.close();
    remove("users.txt");
    rename("temp.txt", "users.txt");
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return ;
}

//ADMIN PAGE
void Ad_display()
{
    system("cls");
    system("color 0");
    int ch , c,l=0;
    cout<<"\t\t\t\t\tADMIN\n\n";
    cout<<"\t\t\t\t\tWelcome Admin!\n\n";
    cout<<"\t\t\t\t1.Login or 2.Set Admin Password\n";
    cin>>c;
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    if(c==1)
    {
        l=ad_login();
        if(l==1)
        {
            do
            {
                cout<<"\n\n\t\t-----Menu-----\n";
                cout<<"\t\t1.Change Admin Password\n";
                cout<<"\t\t2.View accounts\n";
                cout<<"\t\t3.Delete accounts\n";
                cout<<"\t\t4.Back to Home page!\n";
                cout<<"\t\t  Enter your choice of action: ";
                cin>>ch;
                cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
                switch(ch)
                {
                    case 1: change_ad_pass();
                        break;
                    case 2: view_acc();
                        break;
                    case 3: {int d= del_acc();
                                if(d==0)
                                    view_acc;}
                        break;
                    case 4: return;
                        break;
                   }
            }while(ch);
        }
    }
    else
    {

        Register();

    }

    return;
}

