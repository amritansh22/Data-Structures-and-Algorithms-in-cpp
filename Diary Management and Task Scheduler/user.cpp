#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include <fstream>
#include"user.h"
#include"login.h"
#include"user_diary.h"
#include"user_task.h"

using namespace std;

void edit_pass(string username)
{
    int i=0;
    char pass[32]={0};
    ifstream myfile;
    myfile.open("users.txt");
    ofstream temp;
    temp.open("temp.txt");
    string user;
    while (myfile>>user>>pass)
    {
        if (user==username)
        {
            cout<<"\t\t\tEnter New Password "<<username<<"\n";
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

void del_account(string del_user)
{
    string user,pass;
    ifstream myfile;
    ofstream temp;
    myfile.open("users.txt");
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
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;
}

//USER HOME PAGE
void User_display()
{
    system("cls");
    system("color D");
        int c,ch;
        string username;
        cout<<"\t\t\t\t\t1.Login or 2.Create Account\n\n";
        cin>>c;
        cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
        if(c==1)
        {
            username=user_login();
            if(username=="Nil")
            {
                cout<<"\n\t\tOops! Try Again Later!\n";
                return;
            }
            else
            {
                system("cls");
                do
                {
                    cout<<"\t\t\tMenu\n";
                    cout<<"\t\t1.Diary Manager\n";
                    cout<<"\t\t2.task Scheduler\n";
                    cout<<"\t\t3.Edit password\n";
                    cout<<"\t\t4.Delete account\n";
                    cout<<"\t\t5.Exit\n";
                    cout<<"\n\t\tEnter your choice:   ";
                    cin>>ch;
                    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
                    switch(ch)
                    {
                        case 1: user_entry(username);
                                break;
                        case 2: user_task(username);
                                break;
                        case 3: edit_pass(username);
                                break;
                        case 4: del_account(username);
                                break;
                        case 5: cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
                                return ;
                        default: cout<<"Wrong entry\n";
                                    break;
                    }
                }while(ch);
            }
        }
        else
            Register();
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;

}
