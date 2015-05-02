#include "files.h"
#include "error.h"

using namespace std;

int main(int argc, char *argv[])
{
	int option = 0;

	Files f(EMAIL_ELEMENTS, 5);

	cout << "total: " << f.getTotal() << endl;


	cout << "Choose one of the following options: " << endl;
	cout << "1. Remove Email By ID"		<< endl
		 << "2. Show All Emails"		<< endl
		 << "3. Classify Emails"		<< endl
		 << "4. Count All Emails"		<< endl
		 << "5. Count All Spams"		<< endl
		 << "6. Show Email Info By ID"	<< endl
		 << "7. Exit"					<< endl;

	while (option != 7){
		cin >> option;
		switch(option) {
			case(1):
				break;
			case(2):
				f.printTable();
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				break;
			case(7):
				cout << "Ending Program" << endl;
				return EXIT_FROM_USER;
				break;

			default:
				cout << "Please Enter a Number from 1 to 7." << endl;
				break;
		}

	}
	f.printTable();

	return 0;
}
