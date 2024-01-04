#include <iostream>
#include <string>
using namespace std;

int lastIndex = 0;

class Directory
{
public:
    long phoneno;
    string fname, lname;
    Directory(int phoneno = 0, string fname = "", string lname = "")
    {
        this->phoneno = phoneno;
        this->fname = fname;
        this->lname = lname;
    }
};

void addDetail(Directory &d, int flag)
{
    string specific = "";
    if (flag)
        specific = " New";

    cout << "Enter" << specific << " First Name: ";
    cin >> d.fname;
    cout << "\nEnter" << specific << " Last Name: ";
    cin >> d.lname;
    cout << "\nEnter" << specific << " Phone No: ";
    cin >> d.phoneno;
}

void displayDetails(Directory d[])
{
    cout << "\nFirstName\tLastName\tPhoneno\t\n";
    for (int i = 0; i < lastIndex; i++)
    {
        if (d[i].fname != "Deleted")
        {
            cout
                << "\n"
                << d[i].fname << "\t\t" << d[i].lname << "\t\t" << d[i].phoneno << "\t\n";
        }
    }
}

void modifyDetail(Directory d[])
{
    string fname, lname;
    cout << "To Modify Details: \n\n";
    cout << "Enter First Name: ";
    cin >> fname;
    cout << "\nEnter Last Name: ";
    cin >> lname;
    cout << endl;
    int flag = 0;
    for (int i = 0; i < lastIndex; i++)
    {
        if (d[i].fname == fname && d[i].lname == lname)
        {
            flag = 1;
            addDetail(d[i], 1);
        }
    }
    if (flag)
        cout << "\nDetails Modified Successfully..\n\n";
    else
        cout << "\nNo Details Found..\n\n";
}

void deleteDetail(Directory d[])
{
    string fname, lname;
    cout << "To Delete Details: \n\n";
    cout << "Enter First Name: ";
    cin >> fname;
    cout << "\nEnter Last Name: ";
    cin >> lname;
    cout << endl;
    int flag = 0;
    for (int i = 0; i < lastIndex; i++)
    {
        if (d[i].fname == fname && d[i].lname == lname)
        {
            flag = 1;
            d[i].fname = "Deleted";
            d[i].lname = "Deleted";
            d[i].phoneno = 0;
        }
    }
    if (flag)
        cout << "\nDetails Delete Successfully..\n\n";
    else
        cout << "\nNo Details Found..\n\n";
}

int main()
{
    const int count = 100;
    Directory d[count];
    int ch;
    cout << "\nWelcome to Phone Directory Management System\n";
    do
    {
        cout << "\nSelect an Operation: \n\n1.Add New Details\n2.Display All Details\n3.Modify Specific Detail\n4.Delete a Details\n5.Exit\n\nEnter your Choice: ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            addDetail(d[lastIndex], 0);
            lastIndex++;
            cout << "\nDetails Added Successfully..\n\n";
            break;
        case 2:
            displayDetails(d);
            break;
        case 3:
            modifyDetail(d);
            break;
        case 4:
            deleteDetail(d);
            break;
        case 5:
            cout << "Thank You.." << endl
                 << endl;
            return 0;
            break;
        default:
            cout << "\nYou entered an ßInvalid Option...\n";
            break;
        }
    } while (ch != 5 && lastIndex < count - 1);

    cout << endl;
    return 0;
}