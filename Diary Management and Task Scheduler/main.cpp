#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include <fstream>
#include <fstream>
#include "admin.h"
#include"user.h"
#include "login.h"
using namespace std;

//HOME PAGE
int main()
{
    system("cls");
    system("color A");
    int ch;
    do
    {
        cout<<"\n\t\t\t\t\tPERSONAL DIARY & TASK MANAGEMENT\n\n";
        cout<<"\t\t\t\t\t\tWELCOME!\n\n";
        cout<<"\t\t\tModes of Acces:\n";
        cout<<"\t\t\t1.Admin\n";
        cout<<"\t\t\t2.User\n";
        cout<<"\t\t\t3.Exit\n";
        cout<<"\t\t\tSelect an option: ";
        cin>>ch;
        cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
        switch(ch)
        {
            case 1: Ad_display();
                break;
            case 2: User_display();
                break;
            default: cout<<"\t\t\t\t\tThank You!\n";
                     cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
            return 0;
        }
    }while(ch);
}
