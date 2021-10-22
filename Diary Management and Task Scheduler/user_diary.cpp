#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include <bits/stdc++.h>
#include<string.h>
#include <fstream>
#include"user.h"
#include"login.h"
#include"user_diary.h"

using namespace std;

//Diary Entry
struct entry
{
    char date[15];
    char time[10];
    char name[50];
    char place[25];
    char note[500];
};


//write an entry
void add_entry(string username)
{
    int n=username.length();
    FILE *fp;
    struct entry e;
    int x;
    char another='y', time[80];
    char filename[n+1];
    strcpy(filename, username.c_str());
    fp= fopen(filename, "ab+");
    if(fp==NULL)
    {
        fp=fopen(filename, "wb+");
        if(fp==NULL)
        {
            cout<<"\t\tSYSTEM FAIL\n";
            return;
        }
    }
    while(another=='y' ||another=='Y')
    {
        x=0;
        cout<<"\n\t\tEnter time[hh:mm]:   ";
        fflush(stdin);
        gets(time);
        rewind(fp);
        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(strcmp(e.time,time)==0)
            {
                cout<<"\n\t\t------Entry Already Exists------\n";
                x=1;
            }
        }
        if(x==0)
        {
            strcpy(e.time, time);
            cout<<"\t\tName:   ";
            fflush(stdin);
            gets(e.name);
            cout<<"\n\t\tEnter Date of entry:[dd.mm.yyyy]   ";
            fflush(stdin);
            gets(e.date);
            cout<<"\n\t\tEnter place:   ";
            fflush(stdin);
            gets(e.place);
            cout<<"\n\t\tEntry:\n\t\t";
            gets(e.note);
            fwrite(&e, sizeof(e), 1, fp);
            cout<<"\n\t\t--------------Entry Saved!-------------------\n";
        }
        cout<<"\n\t\tDo you want to enter another entry?[y/n]  ";
        fflush(stdin);
        another=getchar();
    }
    fclose(fp);
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;
}

//View Entry
void view_entry(string username)
{
    FILE *fpt;
    struct entry c;
    char date[15],another='y';
    int n=username.length(), ch,x=0;
    char filename[n+1];
    strcpy(filename, username.c_str());
    do
    {
        cout<<"\n\t\tEnter Date of Entry to view:[dd.mm.yyyy]   ";
        fflush(stdin);
        gets(date);
        fpt=fopen(filename, "rb");
        if(fpt==NULL)
        {
            cout<<"\n\t\t-------Sorry!No Entry Exists------\n";
            return ;
        }
        while(fread(&c, sizeof(c), 1, fpt)==1)
        {
            if(strcmp(c.date, date)==0)
            {
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\n\t\tName:  "<<c.name<<endl;
                cout<<"\n\t\tDate:  "<<c.date<<endl;
                cout<<"\n\t\tTime:  "<<c.time<<endl;
                cout<<"\n\t\tPlace  "<<c.place<<endl;
                cout<<"\n\t\tEntry:  "<<c.note<<endl;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                x=1;
            }
        }
        fclose(fpt);
        if(x==0)
        {
            cout<<"\n\t\tOops! No entry for "<<date<<" exits!\n";
        }
        cout<<"\n\t\tWould you like to view another record?[y/n]:  ";
        cin>>another;
    }while(another=='y' || another=='Y');
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;
}

//Delete Entry
void del_entry(string username)
{
    FILE *fp, *fpt;
    struct entry r;
    int n=username.length(), ch;
    char filename[n+1], another='y', date[15];
    strcpy(filename, username.c_str());
    do
    {
        cout<<"\n\t\tWould you like to delete:\n\t\t 1.Whole Record\n\t\t 2.A particular date's entry\n";
        cin>>ch;
        switch(ch)
        {
            case 1: fp= fopen(filename, "ab+");
                    if(fp==NULL)
                    {
                        cout<<"\n\t\tFile does not Exist!\n";
                        return;
                    }
                    fclose(fp);
                    remove(filename);
                    cout<<"\n\t\t--------------Deleted Successfully--------\n";
                    break;
            case 2: fp= fopen(filename, "ab+");
                    if(fp==NULL)
                    {
                        cout<<"\n\t\tFile does not exist!";
                        return ;
                    }
                    fpt = fopen("temp","wb");
                    if(fpt==NULL)
                    {
                        cout<<"\n\t\tError!";
                        return ;
                    }
                    cout<<"\n\t\tEnter Date of entry to be deleted:   ";
                    fflush(stdin);
                    gets(date);
                    while(fread(&r,sizeof(r),1,fp))
                    {
                        if(strcmp(r.date, date)!=0)
                        {
                            fwrite(&r,sizeof(r),1,fpt);
                        }
                    }
                    fclose(fpt);
                    fclose(fp);
                    remove(filename);
                    rename("temp", filename);
                    cout<<"\n\t\tDeleted Successfully";
                    break;
            default: cout<<"\n\t\tError! Wrong Option!\n";
                     break;
        }
        cout<<"\n\t\tWould you like to delete another entry?   ";
        cin>>another;
    }while(another=='y');
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;
}

//edit Entry
void edit_entry(string username)
{
    FILE *fptr;
    struct entry e;
    int n=username.length();
    char date[15], filename[n+1], another='y';
    strcpy(filename, username.c_str());
    fptr=fopen(filename,"rb+");
    if(fptr==NULL)
    {
        cout<<"\n\t\tError! NO such file exists!\n";
        return;
    }
    do
    {
        cout<<"\n\t\tEnter Date of entry to be modified:  ";
        fflush(stdin);
        gets(date);
        while(fread(&e,sizeof(e),1,fptr))
        {
            if(strcmp(e.date,date)==0)
            {
                cout<<"\n\t\tName:   ";
                fflush(stdin);
                gets(e.name);
                cout<<"\n\t\tEnter time[hh:mm]:   ";
                fflush(stdin);
                gets(e.time);
                cout<<"\n\t\tEnter place:   ";
                fflush(stdin);
                gets(e.place);
                cout<<"\n\t\tEntry:\n\t\t";
                gets(e.note);
                fwrite(&e, sizeof(e), 1, fptr);
                fseek(fptr,-sizeof(e),SEEK_CUR);
                fwrite(&e,sizeof(e),1,fptr);
                fseek(fptr,-sizeof(e),SEEK_CUR);
                fread(&e,sizeof(e),1,fptr);
                another=5;
                break;
            }
        }
        if(another==5)
        {
            cout<<"\n\t\tName:  "<<e.name<<endl;
            cout<<"\n\t\tDate:  "<<e.date<<endl;
            cout<<"\n\t\tTime:  "<<e.time<<endl;
            cout<<"\n\t\tPlace  "<<e.place<<endl;
            cout<<"\n\t\tEntry:  "<<e.note<<endl;
            fclose(fptr);
            cout<<"\n\t\tWould you like to enter another entry?[y/n]   ";
            cin>>another;
        }
        else
        {
            cout<<"\n\t\tOops!Record does not exist!\n";
            return;
        }
        fclose(fptr);
    }while(another=='y');
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;
}


//User_diary_page
void user_entry(string username)
{
    system("cls");
    system("color 0");
    int ch;
    cout<<"\n\t\t\t"<<username<<" DIARY Management\n";
    do
    {
         cout<<"\t\t\tMenu\n";
         cout<<"\t\t1.Write an entry\n";
         cout<<"\t\t2.Read a previous entry\n";
         cout<<"\t\t3.Delete an entry \n";
         cout<<"\t\t4.Rewrite an entry\n";
         cout<<"\t\t5.Return to User page\n";
         cout<<"\n\t\tEnter your choice:   ";
         cin>>ch;
         switch(ch)
         {
            case 1: add_entry(username);
                    break;
            case 2: view_entry(username);
                    break;
            case 3: del_entry(username);
                    break;
            case 4: edit_entry(username);
                    break;
            case 5: cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
                    return ;
            default: cout<<"Wrong entry\n";
                     break;
         }
    }while(ch);
}

