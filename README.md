

My terminal Based Contact/PhoneBook that reads in various contact information. It lets users store and easily access contacts information 
using a combination of maps and pairs(data structures)It then saves the information into various file formats such as csv and sql documents for accessing

Key Functions -:
 . Add new contacts and prevents duplicate Name
 . Validates email and number formats to ensure they are correct
 . Searching and deletion of contacts 
 . saves data to storage.txt(backup), storage.csv(excel use), phonebook.sql(DataBase use)

Files
Main.cpp -- main program
storage.txt -- memory for programs next iteration
storage.csv -- for excel file
phonebook.sql -- databse creation

How to Run [IDE of choice or straight from the terminal]
g++ main.cpp -o Phonebook
./PhoneBook
mysql -u root -p < phoneBook.sql

![image alt](https://github.com/buildingBuild/PhoneBook/blob/c99b423a8af8f366ea75d0bb9843b3caf9e1f0e9/img.png)
