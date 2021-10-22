#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include <fstream>
#include"user.h"
#include"login.h"
#include"user_task.h"

using namespace std;

//Task entry
struct task
{
    char date[15];
    char time[10];
    char name[50];
    char deadline[30];
    char status[10];
};

//add new task
void add_task(string username)
{
    FILE *fp;
    struct task t;
    int n=username.length(),x=0;
    char filename[n+1], another='y', time[10];
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
    do
    {
        cout<<"\n\t\tEnter time of task[hh:mm]:  ";
        fflush(stdin);
        gets(time);
        rewind(fp);
        while(fread(&t,sizeof(t),1,fp)==1)
        {
            if(strcmp(t.time,time)==0)
            {
                cout<<"\n\t\t------Task Clash------\n";
                x=1;
            }
        }
        if(x==0)
        {
            strcpy(t.time,time);
            cout<<"\n\t\tEnter Date of Task [dd.mm.yyyy]:  ";
            fflush(stdin);
            gets(t.date);
            cout<<"\n\t\tEnter Name of task:  ";
            fflush(stdin);
            gets(t.name);
            cout<<"\n\t\tEnter deadline for task:  ";
            fflush(stdin);
            gets(t.deadline);
            if(strcmp(t.deadline, t.time)<0)
            {
                cout<<"\n\t\tOops! Deadline set wrongly, enter again!  ";
                gets(t.deadline);
            }
            cout<<"\n\t\tEnter Status of task:  ";
            fflush(stdin);
            gets(t.status);
            fwrite(&t, sizeof(t), 1, fp);
            cout<<"\n\t\t-------------Task Saved------------\n";
        }
        fclose(fp);
        cout<<"\n\t\tWould you like to enter another task for today?[y/n]   ";
        cin>>another;
    }while(another=='y'|| another=='Y');
    return;
}

//delete task
void del_task(string username)
{
    FILE *fp, *fpt;
    struct task r;
    int n=username.length(), ch;
    char filename[n+1], another='y', date[15], time[10];
    strcpy(filename, username.c_str());
    do
    {
        cout<<"\n\t\tWould you like to delete:\n\t\t 1.Your entire record\n\t\t 2.A particular date's schedule\n\t\t3.A particular time's task\n";
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
                    cout<<"\n\t\t--------------Deleted Successfully----------\n";
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
                    cout<<"\n\t\tEnter date of entry to be deleted:   ";
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
            case 3: fp= fopen(filename, "ab+");
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
                    cout<<"\n\t\tEnter date of entry to be deleted:   ";
                    fflush(stdin);
                    gets(date);
                    cout<<"\n\t\tEnter time of entry to be deleted:   ";
                    fflush(stdin);
                    gets(time);
                    while(fread(&r,sizeof(r),1,fp))
                    {
                        if(strcmp(r.date, date)!=0 && strcmp(r.time,time)!=0)
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

//delete completed tasks
void del_comp(string username, char time[10], char date[15])
{
    FILE *fp, *fpt;
    struct task r;
    int n=username.length();
    char filename[n+1];
    strcpy(filename, username.c_str());
    fp= fopen(filename, "ab+");
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

    while(fread(&r,sizeof(r),1,fp))
    {
        if(strcmp(r.date, date)!=0 && strcmp(r.time,time)!=0)
        {
            fwrite(&r,sizeof(r),1,fpt);
        }
    }
    fclose(fpt);
    fclose(fp);
    remove(filename);
    rename("temp", filename);
    cout<<"\n\t\tDeleted Successfully";
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;
}
//update status of task
void upd_stat(string username)
{
    FILE *fpe;
    struct task k;
    int n=username.length();
    char date[15], time[10], filename[n+1], another='y', del_ch='y';
    strcpy(filename, username.c_str());
    fpe=fopen(filename,"rb+");
    if(fpe==NULL)
    {
        cout<<"\n\t\tError! NO such file exists!\n";
        return;
    }
    do
    {
        cout<<"\n\t\tEnter Date of task to be modified:  ";
        fflush(stdin);
        gets(date);
        cout<<"\n\t\tEnter time of task:  ";
        fflush(stdin);
        gets(time);
        while(fread(&k,sizeof(k),1,fpe))
        {
            if(strcmp(k.date,date)==0 && strcmp(k.time,time)==0)
            {
                cout<<"\n\t\tEnter Status of task:  ";
                fflush(stdin);
                gets(k.status);
                fwrite(&k, sizeof(k), 1, fpe);
                fseek(fpe,-sizeof(k),SEEK_CUR);
                fwrite(&k, sizeof(k), 1, fpe);
                fseek(fpe,-sizeof(k),SEEK_CUR);
                fwrite(&k, sizeof(k), 1, fpe);
                another=5;
                break;
            }
        }
        if(another==5)
        {
            cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
            cout<<"\n\t\tDate:  "<<k.date<<endl;
            cout<<"\n\t\tTime:  "<<k.time<<endl;
            cout<<"\n\t\tName:  "<<k.name<<endl;
            cout<<"\n\t\tDeadline:  "<<k.deadline<<endl;
            cout<<"\n\t\tstatus:  "<<k.status<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
            if(strcmp(k.status,"100")==0)
            {
                cout<"\n\t\t~~~~~~~~~~~~Task Completed~~~~~~~~~~~~~~~~~~~~~~\n";
                cout<<"\n\t\tWould you like to delete completed task[y/n]?";
                cin>>del_ch;
                if(del_ch=='y')
                    del_comp(username, k.time, k.date);
            }
            fclose(fpe);
            cout<<"\n\t\tWould you like to update status of another task?[y/n]   ";
            cin>>another;
        }
        else
        {
            cout<<"\n\t\tOops!Record does not exist!\n";
            return;
        }
        fclose(fpe);
    }while(another=='y');
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;
}
//modify task
void edit_task(string username)
{
    FILE *fptr;
    struct task e;
    int n=username.length(), ch;
    char date[15], time[10], filename[n+1], another='y';
    strcpy(filename, username.c_str());
    fptr=fopen(filename,"rb+");
    if(fptr==NULL)
    {
        cout<<"\n\t\tError! NO such file exists!\n";
        return;
    }
    do
    {
        cout<<"\n\t\tEnter Date of task to be modified:  ";
        fflush(stdin);
        gets(date);
        cout<<"\n\t\tEnter time of task:  ";
        fflush(stdin);
        gets(time);
        while(fread(&e,sizeof(e),1,fptr))
        {
            if(strcmp(e.date,date)==0 && strcmp(e.time,time)==0)
            {
                cout<<"\n\t\tDo you want to modify 1.Name of Task\n\t\t2. Deadline\n\t\t3.Status of Task\n\t\tEnter your choice:   ";
                cin>>ch;
                switch(ch)
                {
                    case 1: cout<<"\n\t\tEnter Name of task:  ";
                            fflush(stdin);
                            gets(e.name);
                            break;
                    case 2: cout<<"\n\t\tEnter deadline for task:  ";
                            fflush(stdin);
                            gets(e.deadline);
                            if(strcmp(e.deadline, e.time)<0)
                            {
                                cout<<"\n\t\tOops! Deadline set wrongly, enter again  ";
                                gets(e.deadline);
                            }
                            break;
                    case 3: upd_stat(username);
                            break;
                    default: cout<<"\n\t\tWrong option";
                }
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
            cout<<"\n\t\tDate:  "<<e.date<<endl;
            cout<<"\n\t\tTime:  "<<e.time<<endl;
            cout<<"\n\t\tName:  "<<e.name<<endl;
            cout<<"\n\t\tDeadline:  "<<e.deadline<<endl;
            cout<<"\n\t\tstatus:  "<<e.status<<endl;
            fclose(fptr);
            cout<<"\n\t\tWould you like to modify another task?[y/n]   ";
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

//full schedule
void view_sch(string username)
{
    FILE *fpt;
    struct task c;
    char date[15],another='y';
    int n=username.length(), ch,x=0;
    char filename[n+1];
    strcpy(filename, username.c_str());
    do
    {
        cout<<"\n\t\tEnter Date of Task to view[dd.mm.yyyy]:  ";
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
                cout<<"\n\t\tDate:  "<<c.date<<endl;
                cout<<"\n\t\tTime:  "<<c.time<<endl;
                cout<<"\n\t\tName:  "<<c.name<<endl;
                cout<<"\n\t\tDeadline:  "<<c.deadline<<endl;
                cout<<"\n\t\tstatus:  "<<c.status<<endl;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                x=1;
            }
        }
        fclose(fpt);
        if(x==0)
        {
            cout<<"\n\t\tOops! No schedule for "<<date<<" exits!\n";
        }
        cout<<"\n\t\tWould you like to view another record?[y/n]:  ";
        cin>>another;
    }while(another=='y' || another=='Y');
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    return;

}


//Main User task handling page
void user_task(string username)
{
    system("cls");
    system("color A");
    cout<<"\t\t\t "<<username<<" TASK Scheduler\n";
    int ch;
    do
    {
        cout<<"\t\t\tMenu\n";
        cout<<"\t\t1.Add task\n";
        cout<<"\t\t2.Modify task\n";
        cout<<"\t\t3.Delete task\n";
        cout<<"\t\t4.Update Status\n";
        cout<<"\t\t5.View full schedule\n";
        cout<<"\t\t6.Return to User Home page\n";
        cout<<"\n\t\tEnter your choice:   ";
        cin>>ch;
        cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
        switch(ch)
        {
            case 1: add_task(username);
                    break;
            case 2: edit_task(username);
                    break;
            case 3: del_task(username);
                    break;
            case 4: upd_stat(username);
                    break;
            case 5: view_sch(username);
                    break;
            case 6: return;
        }
    }while(ch);
}

