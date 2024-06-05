/*
Group 1
Faris Abdulrahman AlZayed - 2210001983
Abdulaziz Hussain Alqahtani - 2210002322
Saud Mohammed Alghamdi - 2210002353
Abdullah Muneer Al Ibrahim - 2210001893
Mohammad Abduljalil Altalalwah - 2210002079
Safwan Islam Nabeel - 2210009095
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct transaction
{
	string type;
	int amount;
};


struct account
{
	string name;
	int balance;
	int tnum;
	transaction t[10];	
};
int balance;
int accNum = 0;
account AllAcc[30];

void Menu();

void AddAccount()
{
	if(accNum>=30)
	{
		cout << "Max account limit reached! cannot add account\n";
		return;
	}
	string n;
	int bal;
	cout << "Enter account name: ";
	cin >> n;
	cout << "Enter account balance: ";
	cin >> bal;
	AllAcc[accNum].name = n;
	AllAcc[accNum].balance = bal;
	accNum++;
}

void Deposit()
{
	string n;
	int bal;
	cout << "Enter account name: ";
	cin >> n;
	int i;
	for(i=0 ; i<accNum ; i++)
	{
		if(AllAcc[i].name==n)
		{
			break;
		}
	}
	if(i==accNum)
	{
		cout << "No account found with name!";
		return;
	}
	cout << "Current Balance is: "<<AllAcc[i].balance << endl;
	cout << "Enter amount to deposit: ";
	cin >> bal;
	AllAcc[i].balance+=bal;
	cout << "Amount deposited\n";
}
void Withdrawl()
{
	string n;
	int bal;
	cout << "Enter account name: ";
	cin >> n;
	int i;
	for(i=0 ; i<accNum ; i++)
	{
		if(AllAcc[i].name==n)
		{
			break;
		}
	}
	if(i==accNum)
	{
		cout << "No account found with name!";
		return;
	}
	cout << "Current Balance is: "<<AllAcc[i].balance << endl;
	cout << "Enter amount to withdrawl: ";
	cin >> bal;
	if(bal>AllAcc[i].balance)
	{
		cout << "Insufficient balance. ";
		return;
	}
	AllAcc[i].balance-=bal;
	cout << "Amount withdrawl successfull\n";
}
void Delete()
{
	string n;
	int bal;
	cout << "Enter account name: ";
	cin >> n;
	int i;
	for(i=0 ; i<accNum ; i++)
	{
		if(AllAcc[i].name==n)
		{
			AllAcc[i].name="-";
			break;
		}
	}
	if(i==accNum)
	{
		cout << "No account found with name!";
		return;
	}
}

void DisplayAccount(int &numAccounts)
{
	cout << "Account Name\t\tAccount Balance\n";
	for(int i=0 ; i<numAccounts ; i++)
	{
		cout << AllAcc[i].name <<"\t\t\t" << AllAcc[i].balance << endl;
	}
}

void searchAcc()
{
	string n;
	int bal;
	cout << "Enter account name: ";
	cin >> n;
	int i;
	for(i=0 ; i<accNum ; i++)
	{
		if(AllAcc[i].name==n)
		{
			cout << "Account Name\t\tAccount Balance\n";
			cout << AllAcc[i].name <<"\t\t\t" << AllAcc[i].balance << endl;
			break;
		}
	}
	if(i==accNum)
	{
		cout << "No account found with name!";
		return;
	}
}
int Report()
{
	ofstream file;
	file.open("report.txt");
	int count = 0;
	for(int i=0 ; i<accNum ; i++)
	{
    count++;
	}
  	file << "The number of accounts active: " << count << "\n";
	file.close();
	cout << "Report generated in a seperate file\n";
  return 1;
}


void saveData()
{
	ofstream file;
	file.open("Accounts.txt");
	for(int i=0 ; i<accNum ; i++)
	{
    int len = AllAcc[i].name.length();
    if(AllAcc[i].name[len-1] == '-')
    {
      continue;
    }
		file << AllAcc[i].name <<" " << AllAcc[i].balance << endl;
	}
	file.close();
	cout << "Report generated\n";

}

void readAcc()
{
	ifstream file;
	file.open("Accounts.txt");
	while(!file.eof())
	{
		file >> AllAcc[accNum].name;
		file >> AllAcc[accNum].balance;
		accNum++;
	}
	accNum-=1;
	file.close();
	cout << "All accounts read from report!\n";
}

int main() {
	readAcc();
	while(true)
		Menu();
	
	
}

void Menu() {
	
	int opt;
	
		cout << "              Menu             \n";
		cout << "            ******";
		cout << "\n\n1.Add Account\n";
		cout << "2.Search for Account\n";
		cout << "3.Deposit\n";
		cout << "4.Withdrawl\n";
		cout << "5.Delete Account\n";
		cout << "6.Display all accounts\n";
		cout << "7.Accounts Report\n";
		cout << "8.Exit Program\n\n";
		
		cin>>opt;
	
	switch(opt) {
		case 1:

			AddAccount();
			break;
		case 2:
			
			searchAcc();
			break;
		case 3:
			
			Deposit();
			break;
		case 4:
			
			Withdrawl();
			break;
		case 5:
			
			Delete();
		case 6:
			DisplayAccount(accNum);
			break;
		case 7:
			Report();
			break;
		case 8:
			Report();
    		saveData();
			cout << "Exiting program!";
			exit(0);
		default:
			cout << "Please enter the correct option." << endl;
			Menu();
	}
}


