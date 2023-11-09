#include <iostream>
#include <fstream>
#include<string>
#include<stdlib.h>
#include<windows.h>
using namespace std;
bool flag=false;
struct email
{
    string from;
    string to;
    string date;
    string subject;
    string salutation;
    string body;
    string signature;
    email *link;
};
email *Front=NULL;
email *Rear=NULL;

void enQ(string name1,string name2,string date1,string sub,string sal,string E_body,string sig)
{
    email *temp= new email;
    temp->from=name1;
    temp->to=name2;
    temp->date=date1;
    temp->subject=sub;
    temp->salutation=sal;
    temp->body=E_body;
    temp->signature=sig;
    temp->link=NULL;

    if(Front==NULL&&Rear==NULL)
    {
        Front=Rear=temp;
    }
    else
    {
        Rear->link=temp;
        Rear=temp;
    }
}
void deQ()
{
    email *temp=Front;

    if(Front==NULL)
    {
        cout<<"Your Mail box is Empty"<<endl;
        return;
    }

    else if(Front==Rear)
    {
        flag=true;
    string name1=temp->from;
    string name2=temp->to;
    string date=temp->date;
    string subj=temp->subject;
    string salu=temp->salutation;
    string body=temp->body;
    string sig=temp->signature;
    ofstream filewrite;
    filewrite.open("Stored_mails.txt",ios::out|ios::app);
    filewrite<<"From: "<<name1<<endl<<"To: "<<name2<<endl<<"Date: "<<date<<endl<<"Subject: "<<subj<<endl<<salu<<endl<<body<<endl<<sig<<endl;
    filewrite.close();
        Front=NULL;
        Rear=NULL;
    }
    else
    {
        flag=true;
    string name1=temp->from;
    string name2=temp->to;
    string date=temp->date;
    string subj=temp->subject;
    string salu=temp->salutation;
    string body=temp->body;
    string sig=temp->signature;
    ofstream filewrite;
    filewrite.open("Stored_mails.txt",ios::out|ios::app);
    filewrite<<"From: "<<name1<<endl<<"To: "<<name2<<endl<<"Date: "<<date<<endl<<"Subject: "<<subj<<endl<<salu<<endl<<body<<endl<<sig<<endl;
    filewrite.close();
        Front=Front->link;
    }

    free(temp);
}
string sickleave()
{
    string myText;

    ifstream MyReadFile("sickLeave_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string holidayleave()
{
    string myText;

    ifstream MyReadFile("holidayLeave_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string absenceleave()
{
    string myText;

    ifstream MyReadFile("absenceLeave_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string achgreet()
{
    string myText;

    ifstream MyReadFile("achGreet_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string bdaygreet()
{
    string myText;

    ifstream MyReadFile("bdayGreet_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string clubwelcome()
{
    string myText;

    ifstream MyReadFile("clubWelcome_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string sitewelcome()
{
    string myText;

    ifstream MyReadFile("siteWelcome_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string joboffer()
{
    string myText;

    ifstream MyReadFile("jobOffer_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
string scholarshipoffer()
{
    string myText;

    ifstream MyReadFile("schlrOffer_mail.txt");

    while (getline (MyReadFile, myText))
    {
        return myText;
    }
    MyReadFile.close();
}
void print ()
{
    email *ptr = Front;

    cout << endl << "Your requested E-mail:" << endl;
    cout << "\n------------------------"<<endl;
    while (ptr != NULL)
    {
        cout<<" "<<"From: "<<ptr->from<<endl;
        cout<<" "<<"To: "<<ptr->to<<endl;
        cout<<" "<<"Date: "<<ptr->date<<endl;
        cout<<" "<<"Subject: "<<ptr->subject<<endl;
        cout<<" "<<ptr->salutation<<","<<endl;
        cout<<endl;
        cout<<ptr->body<<endl;
        cout<<endl;
        cout<<" "<<"Signature: "<<ptr->signature<<endl;
        ptr = ptr->link;
        cout << endl;
    }

}
int main()
{
    int option;
    string name_1,name_2,date,sub,sal,sig,E_body;
    while(1)
    {
       system("cls");
       cout << "\n\n\n\n\t\t\t\t\tEMAIL GENERATOR"<<endl;
        cout << "\n\t\t\t\t\t------------------------";
        cout << "\n\n\t\t\t\t\tAvailable operations: "
                "\n\n\t\t\t\t\t1. Leave Email "
                "\n\t\t\t\t\t2. Greetings Email"
                "\n\t\t\t\t\t3. Welcome Email"
                "\n\t\t\t\t\t4. Offer Email"
                "\n\t\t\t\t\t5. store your previous mail"
             << "\n\t\t\t\t\t6. Exit\n\n\t\t\t\t\tEnter option: ";
             cout<<"choose your option from above:"<<endl;
             cin>>option;
             cout<<endl;
        if(option==1)
        {

            system("cls");
            int opt;
            cout<<"you have chosen leave mail"<<endl;

            cout << "\n------------------------"<<endl;
            cout << "Press 1 for generating a Leave mail for sick leave" << endl;
            cout << "Press 2 for generating a Leave mail for holiday leave" << endl;
            cout << "Press 3 for generating a Leave mail for leave of absence" << endl;
            cin>>opt;
            if(opt==1)
            {
                E_body=sickleave();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }

            if(opt==2)
            {
                E_body=holidayleave();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }
            if(opt==3)
            {
                E_body=absenceleave();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }
        }
        else if(option==2)
        {
            system("cls");
            int opt2;
            cout<<"you have chosen Greet mail"<<endl;
            cout << "\n------------------------"<<endl;

            cout << "Press 1 for generating a Greet mail for achievement" << endl;
            cout << "Press 2 for generating a Greet mail for birthday" << endl;
            cin>>opt2;
            if(opt2==1)
            {

                E_body=achgreet();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }
            if(opt2==2)
            {

                E_body=bdaygreet();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }
        }
        else if(option==3)
        {
            system("cls");
            int opt3;

            cout<<"you have chosen Welcome mail"<<endl;
            cout << "\n------------------------"<<endl;
            cout << "Press 1 for generating a welcome mail for joining a club" << endl;
            cout << "Press 2 for generating a welcome mail for logging in a website" << endl;
            cin>>opt3;
            if(opt3==1)
            {
                E_body=clubwelcome();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }
            if(opt3==2)
            {
                E_body=sitewelcome();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }

        }
        else if(option==4)
        {
            system("cls");
            int opt4;
            cout<<"you have chosen Offer mail"<<endl;
            cout << "\n------------------------"<<endl;

            cout << "Press 1 for generating a offer mail for job" << endl;
            cout << "Press 2 for generating a offer mail for scholarship" << endl;
            cin>>opt4;
            if(opt4==1)
            {
                E_body=joboffer();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }
            if(opt4==2)
            {
                E_body=scholarshipoffer();

                getline(cin,name_1);
                cout<<"Sender's name:"<<endl;
                getline(cin,name_1);
                cout<<"Receiver's name:"<<endl;
                getline(cin,name_2);
                cout<<"Date:"<<endl;
                getline(cin,date);
                cout<<"Subject:"<<endl;
                getline(cin,sub);
                cout<<"Salutation:"<<endl;
                getline(cin,sal);
                cout<<"Signature:"<<endl;
                getline(cin,sig);
                enQ(name_1,name_2,date,sub,sal,E_body,sig);
                print();
                system("PAUSE");
            }


        }
        else if(option==5)
        {

            system("cls");
            deQ();
            if(flag){
               cout<<"Your previous mail has been stored"<<endl;
               flag=false;
               system("PAUSE");
            }
        }
        else if(option==6)
        {

            system("cls");
            break;
            system("PAUSE");
        }
        else
        {
            system("cls");
            cout<<"Press Options between 1-6"<<endl;
            system("cls");
        }

    }
}
