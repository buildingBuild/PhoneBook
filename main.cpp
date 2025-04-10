#include <iostream>
#include <fstream>
#include <map>
#include <utility>
using namespace std;

int main()
{

    long double num1;
    long double num2;
    long double result;
    cin >> num1;
    cin >> num2;
    result = num1 - num2;

    cout << result;

    map<string, pair<string, long long> /* */>
        Contact_Info;

    int userChoice;

    cout << "Select a choice\n";
    cout << "1. Add a contact\n";
    cout << "2. Search for a contact\n";
    cout << "3. Delete a contact\n";
    cin >> userChoice;
    cin.ignore();
    // Favorites feature
    // Search by name prefix
    // Sort by recent contact
    // Birthday Reminders
    // Export to file (txt/csv)
    // Call/SMS simulation logs
    // interacting with sql
    // Gui
    // check if number exists
    switch (userChoice)
    {
    case 1:
    {
        char userChoice = 'Y';
        do
        {
            string Name;
            string emailAdd;
            long int Number;
            string countryNumberCode;

            cout << "Enter Contact Name: ";
            getline(cin, Name);

            cout << "Enter Contact Email Address: ";
            getline(cin, emailAdd);

            cout << "Enter Contact Number: ";
            cin >> Number;

            Contact_Info[Name] = make_pair(emailAdd, Number);
            cout << "Do you want to continue adding contacts:(Y/N): ";
            cin >> userChoice;
            cin.ignore();
            userChoice = toupper(userChoice);
        } while (userChoice == 'Y');
        break;
    }

    case 2:
    {
        cout << "Enter Contact Name or Number to search \n";

        break;
    }

    case 3:
    {

        break;
    }
    default:
        break;
    }

    cout << "Hello we are winning you hear me dude can you hear me\n";
    return 0;
}