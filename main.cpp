#include <iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<unistd.h>
void encrpt();
void decrpt();
using namespace std;
int main()
{
 char opt;
 const int MAX = 100;
 char str[MAX];
 ofstream enc("encrpt.txt",ios::app);
   cout << "\nNOTE: If there is No Data to Encrypt Press \"ENTER\" ";
   cout << "\nEnter a string: ";
   cin.getline(str, MAX);
   for(int i=0;str[i]!=NULL;i++)
    {
      str[i]=str[i]+2;
    }
    enc<<str;
    enc.close();
    system("CLS");
    cout<<"-------Menu-------";
    cout<<"\n1.Decrypt the Data";
    cout<<"\n2.Clear the Encrypted Data";
    cout<<"\n3.Exit";
    cout<<"\n------------------";
    cout<<"\nEnter Your Option:";
    cin>>opt;
    if(opt=='1'){
        decrpt();
        main();
    }
    else if(opt=='2'){
         ofstream enc1("encrpt.txt");
         enc1.clear();
            cout<<"Data in File is Deleted Successfully";
            getch();
         main();
    }
    else{
        exit(0);
    }
return 0;
}
void decrpt()
{
    int pwd,count_wpwd=0,len;
    string str="";
retry:
    system("CLS");
    cout<<"\n\t Before Decrypting the Data, Enter the PassWord:";
    cin>>pwd;
    if(pwd==1234)
    {
        system("CLS");
        char ch1;
        ifstream dec("encrpt.txt");
        while(!dec.eof())
        {
            dec.get(ch1);
            ch1 = ch1 - 2;
            str = str + ch1;
        }
        len=str.length();
        if(len>1){
        cout<<"Your Data is:\n";
        cout<<str.substr(0,len-1);
        getch();
        }
        else{
            cout<<"\n\t Sorry...! No Data to Decrypt";
            getch();
        }
        dec.close();
    }
    else
    {
        if(count_wpwd==2){
            main();
        }
        count_wpwd++;
        cout<<"\n\t Sorry....! Wrong PassWord";
        cout<<"\n\t Only "<<3-count_wpwd<<" Chances Left ";
        getch();
        goto retry;
    }
}
