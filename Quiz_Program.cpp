#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
using namespace std;
void starline();
int main()
{
    int no=0;
    bool har=0;
    int b=0;
    int ans[10];
    float score=0;
    int anshard[10]={1,1,1,4,3,2,2,3,2,2};//answers to the questions
    int ansmed[10]={3,3,1,4,3,3,2,4,3,2};//answers to the questions
    int anseasy[10]={4,1,2,1,4,1,3,1,3,1};//answers to the questions
    int ansin=0;
    int k=0;
    int h=0,i=0,j=0,l=0,ea=0,q=0;
    float correct =0;
    char ch;
    string x[10];
    string y[10];
    string z[10];
    char s[100];
    ifstream medium;
    ifstream hard;
    ifstream easy;
    int e=0,m=0,n=0,main=0;
    starline();
    starline();
    cout<<"Welcome to the Quiz"<<endl;
    starline();
    starline();
    cout<<"The rules:"<<endl;
    cout<<"Press 1 to continue: "<<endl;
    cin>>ch;
    while(main<=9)
    {
        medium.open("Medium.txt");
        for(int i=0;i<=9;i++)
        {
            getline(medium,x[i],'\n');
            if(i==main)
            {
                no++;// displaying the question number
                system("cls");
                cout<<"("<<no<<"): "<<x[i]<<endl;
                cout<<"Please select the option 1(a)/2(b)/3(c)/4(d): "<<endl;
                cout<<"Enter your answer: ";
                cin>>ansin;
            }
        }
        if(ansin==ansmed[main])// check if the answer is right
        {
           correct++;
           score=score+4;
           q=main-ea;//Decreasing the value of main as our requirement
           h++;
           hard.open("Hard.txt");
           for(int j=0;j<=9;j++)
           {
               getline(hard,y[j],'\n');
               if(j==q)
               {
                no++;// displaying the question number
                system("cls");
                cout<<"Q= ";
                cout<<"("<<no<<")"<<x[i]<<endl;
                cout<<"Please select the option 1(a)/2(b)/3(c)/4(d): "<<endl;
                cin>>ansin;
                if(ansin==ansmed[j])
                {
                    correct++;
                    score=score+5;
                }
               }
           }
        }
        
        else//if the answer form the Medium/Hard question is wrong then jump to Easy Questions
        {
            ea++;
            l=main-h;
            easy.open("Easy.txt");
            for(int k=0;k<=9;k++)
            {
                getline(easy,z[k],'\n');// reading the whole file
                if(k==l)// Displaying the questions which we want
                {
                no++;// displaying the question number
                system("cls");
                cout<<"Q= ";
                cout<<"("<<no<<")"<<x[i]<<endl;
                cout<<"Please select the option 1(a)/2(b)/3(c)/4(d): "<<endl;
                cin>>ansin;
                if(ansin==anseasy[k])
                {
                    correct++;
                    score=score+3;
                }
                }
            } 
        }
       main++;
       if(main==10)//Displaying the question of easy and hard which are left after completion of medium questions
       {
           if(ea<=9||h<=9)
           {
               while(ea<=9)
               {
                   easy.open("Easy.txt");
                   for(int t=0;t<=10;t++)
                   {
                       getline(easy,z[t],'\n');
                       if(t==ea)//Displaying the reamining questions
                       {
                           no++;// displaying the question number
                           system("cls");
                           cout<<"Q= ";
                           cout<<"("<<no<<")"<<x[i]<<endl;
                           cout<<"Please select the option 1(a)/2(b)/3(c)/4(d): "<<endl;
                           cin>>ansin;
                           if(ansin==anseasy[t])
                           {
                               correct++;
                               score=score+3;
                           }
                       }
                   }
                   ea++;
               }
                if(ea==10)
                   {
                       while(h<=10)//Displaying the remainig values of hard files
                       {
                           hard.open("Hard.txt");
                           for(int w=0;w<=10;w++)
                           {
                               getline(hard,y[w],'\n');
                               if(h==w)
                               {
                                     no++;// displaying the question number
                                     system("cls");
                                     cout<<"Q= ";
                                     cout<<"("<<no<<")"<<x[i]<<endl;
                                     cout<<"Please select the option 1(a)/2(b)/3(c)/4(d): "<<endl;
                                     cin>>ansin;
                                     if(ansin==anseasy[w])
                                    {
                                      correct++;
                                      score=score+5;
                                    } 
                               }
                           }
                           h++;
                           if(h==10)
                           break;
                       }
                   }
           }
       }
    }
    system("cls");
    cout<<"Your Score is: "<<score<<" Outof 120"<<endl;
    cout<<"You Answered: "<<correct<<endl;
    cout<<" You answered "<<(30-correct)<<" Wrong Questions "<<endl;
    return 0;
}
void starline()
{
    for(int i=0;i<120;i++)
    {
        cout<<"*";
    }
    cout<<endl;
}