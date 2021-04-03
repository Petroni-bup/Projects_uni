#include <iostream>
#include <cstring>

class BankAccount {
	
private:
	char memberName[20];
	char bankNum[10] = "BG";
	char subArray[8];
	size_t balance = 0;

	size_t  arrLength(char* arr) {
		
		return strlen(arr);
	}

public:
	char getMemberName() {
		return *memberName;
	}

	void setMemberName(char data , size_t location) {
		memberName[location] = data;
	}

	char getBankNum() {
		return *bankNum;
	}

	void setBankNum(char data, size_t location) {
		bankNum[location] = data;
	}

	char getSubArray() {
		return *subArray;
	}

	void setSubArray(char data, size_t location) {
		subArray[location] = data;
	}

	size_t getBalance() {
		return balance;
	}

	void setBalance(size_t balance) {
		this->balance = balance;
	}



	BankAccount* makeAccount() {

		
		std::cout << "Fill member name." << std::endl;
		std::cin.getline(memberName, 20);
		

		std::cout << "Fill bank num." << std::endl;
		std::cin.getline(subArray, 10);
		for (int i = 2;i < arrLength(subArray) + 2;++i) {
			bankNum[i] = subArray[i - 2];
		}

			do {
				std::cout << "Deposit minimum 500 for account copleation! " << std::endl;
				std::cin >> balance; 
			}
		    while (balance < 500);
		
			

		return this;
	}

	void printData() {
		std::cout << std::endl;

		std::cout << "Member name: ";
		for (int a = 0; a < arrLength(memberName); ++a) {
			std::cout<< memberName[a];
		}
		std::cout << std::endl;

		std::cout << "Bank number: ";
		for (int i = 0; i < arrLength(bankNum); ++i) {
			std::cout<< bankNum[i];
		}
		std::cout << std::endl;

		std::cout << "Balance: " << balance << std::endl;


	}

	
	BankAccount* pushOrPull() {
		char desition = ' ';
		size_t moneyCount;
		while (desition != 'n') {

			std::cout << "Now you can depozit(enter d) money from the account " << std::endl;
			std::cout << "or pull(enter p) money form the account                          curent balance: " <<balance << std::endl;

			std::cout << "or do nothing(n)" << std::endl;

			do {
				std::cin >> desition;
			} while (desition != 'd' && desition != 'p' && desition != 'n');

			switch (desition) {
			case 'd':
				std::cout << "So you want to depozit, ok then pick a number!" << std::endl;
				std::cin >> moneyCount;
				this->balance += moneyCount;
				break;
			case 'p':
				do {
					std::cout << "So you want to pull money, ok then pick a number, but no bigger than the balance! " << "Yout balance: " << balance << std::endl;
					std::cin >> moneyCount;
				} while (moneyCount > balance);

				this->balance -= moneyCount;
				break;
			case 'n':
				std::cout << "You changed your mind? Ok." << std::endl;
				break;
			}
		}
			return this;
		
	}

	
};


int main() {

	BankAccount member1;
	
	member1.makeAccount()->pushOrPull()->printData();
	
	
	
	return 0;
}
