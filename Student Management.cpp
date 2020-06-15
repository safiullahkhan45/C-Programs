#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>

using namespace std;

string userName = "Khan";
string password = "Khan123";

class Student
{
public:
    char name[20];
    int rollNo;
    char section;
    float marks;
    int fee;
public:
    void read();
    void display();
};
void Student::read()
{
    cout << "Enter Name of the student:\n";
    cin.ignore();
    cin.getline(name, 20);
    cout << "Enter Roll No. of the student:\n";
    cin >> rollNo;
    cout << "Enter Section of the student:\n";
    cin >> section;
    cout << "Enter Marks of the student:\n";
    cin >> marks;
    cout << "Enter Fees Given by the Student\n";
    cin >> fee;
}
void Student::display()
{
    cout << name << "\t\t" << rollNo << "\t" << section << "\t" << marks << "\t" << fee << endl;
}
void login()
{
    string user;
    string pass;

    cout << "Login To Continue ...\n\n";
    cout << "User name:\t";
    cin >> user;
    cout << "Password:\t";
    cin >> pass;

    if(userName == user && password == pass)
        {
            cout << "\n\nLogin Successful !!\n\n";
        }
    else
        {
            while(userName != user && password != pass)
            {
                cout << "Incorrect Username or Password.\n";
                cout << "User name:\t";
                cin >> user;
                cout << "Password:\t";
                cin >> pass;
                if(userName == user && password == pass)
                {
                    cout << "\n\nLogin Successful !!\n\n";
                }
            }
        }
}
void addRecord()
{
    Student st;
    ofstream thisFile;
    thisFile.open("UserData.txt", ios::app);
    cout << "Enter Record of the student.\n";
    st.read();
    thisFile.write((char*)&st, sizeof(st));
    thisFile.close();
}
void viewRecord()
{
    Student st;
    ifstream viewFile;
    viewFile.open("UserData.txt");
    while(viewFile.read((char*)&st, sizeof(st)))
    {
        st.display();
    }
    viewFile.close();
}
void modifyRecord(int roll)
{
    Student st;
    fstream fp;
    int found = 0;
    fp.open("UserData.txt",ios::in|ios::out);
    while(fp.read((char*)&st, sizeof(st)) && found == 0)
    {
        if(st.rollNo == roll)
        {
            st.display();
            cout << "\nEnter the new Details of the student.\n";
            st.read();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st, sizeof(st));
            found=1;
        }
    }
    fp.close();
}
void modifyFinance(int roll)
{
    Student st;
    fstream fp;
    int found = 0;
    fp.open("UserData.txt",ios::in|ios::out);
    while(fp.read((char*)&st, sizeof(st)) && found == 0)
    {
        if(st.rollNo == roll)
        {
            st.display();
            int amount;
            cout << "\nEnter amount to add to fees.\n";
            cin >> amount;
            st.fee = st.fee+amount;
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st, sizeof(st));
            found=1;
        }
    }
    fp.close();
}

int main()
{
    string userName;
    string password;
    int choice;
    char cont;
    cout << "\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\tSchool Management System.\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
    cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\tCreated By: Safiullah Khan.\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
    cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\tLogin First.\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
    login();
    cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout << "\t\t1. Add Record.\n";
    cout << "\t\t2. View Record.\n";
    cout << "\t\t3. Modify Record.\n";
    cout << "\t\t4. Modify Financial Record.\n";
    cout << "\t\t5. Exit Program.\n";
    cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";

    cout << "Enter a Choice to continue.\n";
    cin >> choice;
    switch (choice)
    {
    case 1 :
        system("cls");
        addRecord();
        break;
    case 2 :
        system("cls");
        cout << "\n\nDisplaing Record.\n\n";
        cout << "Name\t\t" << "RollNo  " << "Section  " << "Marks " << "Fee \n\n";
        viewRecord();
        break;
    case 3 :
        system("cls");
        int rN;
        cout << "Enter Roll No for record modification.\n";
        cin >> rN;
        modifyRecord(rN);
    case 4 :
        system("cls");
        int rollN;
        cout << "Enter Roll No for record modification.\n";
        cin >> rollN;
        modifyFinance(rollN);
    default :
        return 0;
    }
    cout << "Do you want to continue ??\n";
    cout << "Enter y/Y to Continue or n/N to end the program.\n";
    cin >> cont;
    while(cont == 'Y' || cont == 'y')
    {
        cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
        cout << "\t\t1. Add Record.\n";
        cout << "\t\t2. View Record.\n";
        cout << "\t\t3. Modify Record.\n";
        cout << "\t\t4. Modify Financial Record.\n";
        cout << "\t\t5. Exit Program.\n";
        cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";

        cout << "Enter a Choice to continue.\n";
        cin >> choice;
        switch (choice)
        {
        case 1 :
            system("cls");
            addRecord();
            break;
        case 2 :
            system("cls");
            cout << "\n\nDisplaing Record.\n\n";
            cout << "Name\t\t" << "RollNo  " << "Section  " << "Marks " << "Fee \n\n";
            viewRecord();
            break;
        case 3 :
            system("cls");
            int rN;
            cout << "Enter Roll No for record modification.\n";
            cin >> rN;
            modifyRecord(rN);
            break;
        case 4 :
            system("cls");
            int rollN;
            cout << "Enter Roll No for record modification.\n";
            cin >> rollN;
            modifyFinance(rollN);
            break;
        case 5 :
            cout << "Press any key to Continue. .\n\n";
            return 0;
        }
    }
}
