#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <iostream>

using namespace std ;

class patient
{
    char name[40];
    int age;
    char gender;
    char disease[20];
    char dateofadm[15];
    int wardno;
    char dateofdis[15];
    int days;

public:
    void getdata(void);
    void display(void);
};

void patient::getdata(void)
{
    
    char ch;
    cin.get(ch);
    cout << "Enter Name :";
    cin.getline(name, 40);
    cout << "Enter Age:";
    cin >> age;
    cout << "Enter gender:";
    cin >> gender;
    cout << "Enter Disease:";
    gets(disease);
    cout << "Enter date of admission:";
    cin.getline(dateofadm, 15);
    cout << "Enter ward number:";
    cin >> wardno;
    cout << "Enter date of discharge:";
    cin.getline(dateofdis, 15);
    cout << "Total number of days patient stayed in hospital:";
    cin >> days;
    cout << endl;
}
void patient::display(void)
{
    long int total;
    cout << " Name :";
    cout << name;
    cout << endl
         << "Age:";
    cout << age;
    cout << endl
         << "Gender:";
    cout << gender;
    cout << endl
         << "Disease:";
    puts(disease);
    cout << "Date of Admission:";
    puts(dateofadm);
    cout << endl
         << "Ward number:";
    cout << wardno;
    cout << endl
         << "Date of discharge:";
    puts(dateofdis);
    cout << endl
         << "Days patient stayed:";
    cout << days;
    cout << endl
         << "Total payment for the patient is:";
    total = days * 2000;
    cout << total;
    cout << endl;
}
int main()
{
    
    patient p[3];
    fstream fino;
    fino.open("Patient.dat", ios::in | ios::out);
    if (!fino)
    {
        cout << "Cannot open file!!\n";
        exit(0);
    }
    cout << "Enter details for 3 Patient\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details for Patient" << i + 1 << endl;
        p[i].getdata();
        fino.write((char *)&p[i], sizeof(p[i]));
    }
    fino.seekg(0);
    cout << "The information of PATIENT are\n";
    for (int i = 0; i < 3; i++)
    {
        fino.read((char *)&p[i], sizeof(p[i]));
        p[i].display();
    }
    fino.close();
    getch();
}