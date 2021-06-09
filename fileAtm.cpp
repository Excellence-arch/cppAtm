// #include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<fstream>
using namespace std;

class Atm {
	public:
		int p;
		int user;
		string customers[100][4];
		int custmerBal[100];
		string fName;
		string lName;
		string address;
		string password;
		Atm() {
			readFile();
			readBal();
			init();
		}

		void init() {
			cout<< "\nWelcome to c++ bank\nPress\n1. Register\n2.Login\n3. Quit\n";
			cin>> user;
			switch(user) {
				case 1:
					reg();
					break;
				case 2:
					login();
					break;
				case 3:
					break;
				default:
					cout<< "Try again later";
					init();
			}
		}

		void menu(int m) {
			cout<< "\nPress\n1. Deposit\n2. Transfer\n3. Withdraw\n4. Check Balance\n5. Logout\n";
			cin>> user;
			switch(user) {
				case 1:
					deposit(m);
					break;
				case 2:
					transfer(m);
					break;
				case 3:
					withdraw(m);
					break;
				case 4:
					bal(m);
					break;
				case 5:
					init();
					break;
				default:
					cout<< "Invalid input\n";
					menu(m);
			}
		}

		void login() {
			cout<< "Enter your first Name\n";
			cin>> fName;
			cout<< "Enter your password\n";
			cin>> password;
			bool found = false;

			for(int i=0; i<80; i++) {
				if(fName == customers[i][0] and password == customers[i][3]) {
					found = true;
					menu(i);
				}
			}

			if(!found) {
				cout<< "Invalid first name or password\n";
				login();
			}
			found = false;

		}
		void reg() {
			cout<< "Enter your first name ";
			cin>> fName;
			cout<< "Enter your last name ";
			cin>> lName;
			cout<< "Enter your email address ";
			cin>> address;
			cout<< "Enter your password ";
			cin>> password;

			customers[p][0] = fName;
			customers[p][1] = lName;
			customers[p][2] = address;
			customers[p][3] = password;
			custmerBal[p] = 0;
			p++;

			cout<< "Your account has been activated\n";
			writeFile();
			bal();
			menu(p);
		}

		void bal(int m) {
			cout<< "Your account balance is "<<custmerBal[m];
		}

		void transfer(int m) {
			string fName;
			string lName;
			bool found = false;
			cout<< "First name of the recipient\n";
			cin>> fName;
			cout<< "Last name of the recipient\n";
			cin>> lName;
			for (int q = 0; q < p; q++)
			{
				// found = true;
				if(fName == customers[q][0] and lName == customers[q][1]) {
					// if (lName == customers[q][1]) {
						found = true;
						cout<< "How much do you want to transfer\n";
						cin>> user;
						custmerBal[q] += user;
						custmerBal[m] -= user;
						cout<< "Transaction successful, Your new account balance is "<<custmerBal[m];
					// }
				}
			}
			if (!found) {
				cout<< "Account not found, please try again\n";
				transfer(m);
			}
			// found = false;
			bal();
			menu(m);
			// cout<< "Transfer";
		}

		void withdraw(int m) {
			cout<< "How much do you want to withdraw\n1. 1000\n2. 2000\n3. 5000\n4. 10000\n5. 20000\n6. Cancel";
			cin>> user;
			switch(user) {
				case 1:
					custmerBal[m] -= 1000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 2:
					custmerBal[m] -= 2000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 3:
					custmerBal[m] -= 5000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 4:
					custmerBal[m] -= 10000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 5:
					custmerBal[m] -= 20000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 6:
					menu(m);
					break;
				default:
					cout<< "Invalid input\nPlease try again\n";
					deposit(m);
			}
		}

		void deposit(int m) {
			cout<< "How much do you want to deposit\n1. 1000\n2. 2000\n3. 5000\n4. 10000\n5. 20000\n6. Cancel";
			cin>> user;
			switch(user) {
				case 1:
					custmerBal[m] += 1000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 2:
					custmerBal[m] += 2000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 3:
					custmerBal[m] += 5000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 4:
					custmerBal[m] += 10000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 5:
					custmerBal[m] += 20000;
					cout<< "Your new account balance is "<< custmerBal[m];
					bal();
					menu(m);
					break;
				case 6:
					menu(m);
					break;
				default:
					cout<< "Invalid input\nPlease try again\n";
					deposit(m);
			}
		}

		void writeFile() {
			fstream myWrite;
			myWrite.open("Bank.txt", ios::out);
			if (myWrite) {
				for (int i = 0; i < p; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						myWrite<<customers[i][j] << " ";
					}
					myWrite<< "\n";
				}
				myWrite.close();
			}
		}

		void bal() {
			fstream myBal;
			myBal.open("Balances.txt", ios::out);
			if (myBal) {
				for (int i = 0; i < p; i++)
				{
					myBal<< custmerBal[i] << "\n";
				}
			}
		}

		void readBal() {
			string files;
			fstream bals;
			bals.open("Balances.txt", ios::in);
			if (bals) {
				int i = 0;
				while(getline(bals, files)) {
					custmerBal[i] = stoi(files);
					i++;
				}
			}
		}

		void readFile() {
			string fileContent;
			fstream myRead;
			myRead.open("Bank.txt", ios::in);
			int i = 0;
			while(getline(myRead, fileContent)) {
				int j = 0;
				stringstream ss(fileContent);
				string word;
				while(ss >> word) {
					customers[i][j] = word;
					j++;
				}
				i++;
			}
			p = i;
		}
};

int main() {
	Atm me;
	return 0;
}