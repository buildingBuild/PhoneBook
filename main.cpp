#include <iostream>
#include <fstream> // for file handling
#include <map>     // um for maps obviously lol
#include <utility> // for pairs
#include <sstream>
using namespace std;

int main()
{

    map<string, pair<string, string> /* */> Contact_Info; // some old c++ version support
    map<string, pair<string, string> /* */>::iterator iter;

    ifstream read("storage.txt");
    if (!read)
    {

        cout << "File failed to open for reading\n";
        return 1;
    }
    string Name;
    string Number;
    string email;
    while (read >> Name >> Number >> email)
    {
        Contact_Info[Name] = make_pair(email, Number);
    }

    int userChoice;
    char userWord = 'Y';

    cout << "\n";
    cout << "WELCOME TO CONTACT BOOK!\n";
    cout << "Numbers are formatted in the Land of the Free Format RAHHHH\n";
    do
    {

        cout << "\n";
        cout << "Select an option\n";
        cout << "1. Add a contact\n";
        cout << "2. Search for a contact\n";
        cout << "3. Delete a contact\n";
        cout << "4. Display all contact\n";
        cout << "5. Save contact to database\n";
        cout << "Selecting... ";
        cin >> userChoice;
        cin.ignore();
        // interacting with sql
        // Load for csv file
        switch (userChoice)
        {
        case 1:
        { /// ADDING CONTACT

            char userChoice = 'Y';
            do
            {
                string Name;
                string emailAdd;
                string Number;
                string countryNumberCode;

                //// Start
                bool Name_Key_exist = false; //  preparing to check if name which is key for map exists to prevent overwritting
                do
                {
                    cout << "\n";
                    cout << "Adding Contact\n";
                    cout << "-----------------\n";

                    cout << "Input contact name: ";
                    getline(cin, Name);
                    if (Contact_Info.find(Name) != Contact_Info.end())
                    {
                        Name_Key_exist = true;
                        cout << "Error! Contact Already exist use different Name\n";
                        cout << "\n";
                    }
                    else
                    {
                        Name_Key_exist = false;
                    }
                } while (Name_Key_exist == true);
                bool correctEmailFormat = false; //  preparing to check for right format of email
                do
                {
                    cout << "Provide email address: ";
                    getline(cin, emailAdd); /// add an email check
                    if (emailAdd.find("@gmail.com") == string::npos && emailAdd.find("@yahoo.com") == string::npos && emailAdd.find("@outlook.com") == string::npos)
                    {
                        correctEmailFormat = false;
                        cout << "Wrong email format{ Try emailName@gmail.com or emailName@yahoo.com or @outlook.com\n";
                        cout << "\n";
                        continue;
                    }
                    correctEmailFormat = true;
                } while (correctEmailFormat == false);

                bool correctNumberFormat = true;
                do
                {
                    cout << "Input contact's Number (###-###-####): ";
                    cin >> Number;

                    if (Number[3] != '-' || Number[7] != '-' || Number.size() != 12)
                    {
                        correctNumberFormat = false;
                    }
                    else
                    {
                        for (int i = 0; i < Number.size(); i++)
                        {
                            correctNumberFormat = true;

                            if (i == 3 || i == 7)
                            {
                                continue;
                            }
                            else
                            {
                                if (!isdigit(Number[i]))
                                {
                                    correctNumberFormat = false;
                                    break;
                                }
                            }
                        }
                    }

                    if (correctNumberFormat == false)
                    {
                        cout << "\n";
                        cout << "Invalid input, format should be -- (###-###-###)\n";
                        cout << "\n";
                    }
                } while (correctNumberFormat == false);

                Contact_Info[Name] = make_pair(emailAdd, Number);
                cout << "Contact added successfully!\n";
                cout << "\n";
                cout << "Do you want to continue adding contacts:(Y/N): ";
                cin >> userChoice;
                cin.ignore();
                userChoice = toupper(userChoice);

            } while (userChoice == 'Y');
            break;
        }

        case 2:
        {

            string name_value;
            cout << "\n";
            cout << "Searching for a  Contact\n";
            cout << "-----------------\n";
            cout << "Enter Contact name for searching: ";
            getline(cin, name_value);
            cout << "\n";
            if (Contact_Info.find(name_value) != Contact_Info.end())
            {
                cout << "-----------------\n";
                cout << "Contact Found!\n";
                cout << "-----------------\n";
                cout << "Name: " << name_value << "\n";
                // cout << "Number: " << Contact_Info.at(name_value); // remember its a map with a pair stop making the same mistake lol
                cout << "Number: " << Contact_Info.at(name_value).second << "\n";
                cout << "Email: " << Contact_Info.at(name_value).first << "\n";
                cout << "-----------------\n";
                cout << "\n";
            }
            else
            {
                cout << "-----------------\n";
                cout << "Contact not found!\n";
                cout << "-----------------\n";
            }
            break;
        }

        case 3:
        {
            string name_value;
            cout << "\n";
            cout << "Deleting a Contact\n";
            cout << "-----------------\n";
            cout << "Enter Contact name for deleting: ";
            getline(cin, name_value);
            if (Contact_Info.find(name_value) != Contact_Info.end())
            {
                cout << "-----------------\n";
                cout << "Contact Found!\n";
                cout << "-----------------\n";
                cout << "Name: " << name_value << "\n";
                cout << "Number: " << Contact_Info.at(name_value).second << "\n";
                cout << "Email: " << Contact_Info.at(name_value).first << "\n";
                cout << "-----------------\n";
                Contact_Info.erase(name_value);
                cout << "Contact deleted\n";
                cout << "\n";
            }
            else
            {
                cout << "-----------------\n";
                cout << "Contact not found cannot delete \n";
                cout << "-----------------\n";
            }
            break;
        }

        case 4:
        {
            cout << "\n";
            cout << "Displaying All Contacts" << endl;
            int i = 0;
            // cout to csv file
            for (iter = Contact_Info.begin(); iter != Contact_Info.end(); ++iter)
            {
                cout << "-------------------------------\n";
                cout << "Contact: " << i + 1 << "\n";
                cout << "Name: " << iter->first << "\n";
                cout << "Email Address: " << iter->second.first << "\n";
                cout << "Phone Number: " << iter->second.second << "\n";
                cout << "-------------------------------\n";
                ++i;
            }
            break;
        }

        case 5:
        {
            ofstream write("storage.csv", ios::app); // to append
            if (!write)
            {
                cout << "File failed to open for writing\n";
                break;
            }

            ofstream write2("storage.txt", ios::trunc); // to append
            if (!write)
            {
                cout << "File failed to open for writing\n";
                break;
            }
            cout << "\n";
            // cout to csv file
            for (iter = Contact_Info.begin(); iter != Contact_Info.end(); ++iter)
            {
                write2 << iter->first << " " << iter->second.second << " " << iter->second.first;
                write << iter->first << "," << iter->second.second << "," << iter->second.first;
                if (next(iter) != Contact_Info.end())
                {
                    write2 << "\n"; // line left this way because of spacing bug
                    write << "\n";
                }
            }
            cout << "Contacts saved!\n";
            write.close();
            write2.close();
            break;
        }
        default:
            break;
        }
        cout << "Do you want to continue to Main Menu(Y/N): ";
        cin >> userWord;
        userWord = toupper(userWord);
        cin.ignore();

    } while (userWord == 'Y');
    cout << "Thank you for using the program!!\n";
    return 0;
}