#include "files.h"
#include "error.h"
#include "filedir.h"

using namespace std;

int main(int argc, char *argv[])
{
	int option = 0;
	int removeID =0;
	int ID = 0;
	vector<string> emailFiles;
	Filedir f("./email");

	int totalEmails = f.searchDir("txt", emailFiles);

	//emailFiles.push_back ("C:/Users/Cyfer/Documents/GitHub/LingProg2/email.txt");
	//emailFiles.push_back ("C:/Users/Cyfer/Documents/GitHub/LingProg2/email1.txt");
	//emailFiles.push_back (strcat ("C:/Users/Cyfer/Documents/GitHub/LingProg2","/email1.txt"));



	Files f(EMAIL_ELEMENTS, totalEmails); // topics, !!!!!!!!TOTAL!!!!!!!
//	std::ifstream file("C:/Users/Cyfer/Documents/GitHub/LingProg2/email.txt");

	cout << "total: " << f.getTotal() << endl;

	cout << "Menu: " << endl;
	cout << "1. Remove Email By ID"		<< endl
		 << "2. Show All Emails"		<< endl
		 << "3. Classify Emails"		<< endl
		 << "4. Count All Emails"		<< endl
		 << "5. Count All Spams"		<< endl
		 << "6. Show Email Info By ID"	<< endl
		 << "7. Exit"					<< endl;

	while (option != 7){
		cout << "Choose a Menu Option: ";
		cin >> option;
		switch(option) {
			case(1):
					cout << "Choose the ID of the email to be removed" << endl;
					cin >> removeID;
					if(remove(f.getPath(removeID)) != 0){
						cout << "Error deleting file" << endl;
					}
					else {cout << "File deleted Succefully" << endl;}
				break;
			case(2):
				f.printTable();
				break;
			case(3):
				f.setEmail (emailFiles);
//				f.setSpam ("Sim", 0);
				break;
			case(4):
				cout << "The total amount of emails in this directory is : "
					 << f.getTotal () << endl;
				break;
			case(5):
				cout << "The total amount of spams in this directory is : "
					 << f.getSpamCount () << endl;
				break;
			case(6):
				cout << "Please Select Your Desired Email: ";
				cin	 >> ID;
				while (ID < 1 || ID > (f.getTotal() - 1)) {
					cout << "Please Enter a Valid ID" << endl;
					cin >> ID;
				}
				f.printEmail (EMAIL_ELEMENTS, ID-1);
				break;
			case(7):
				cout << "Ending Program" << endl;
				return EXIT_FROM_USER;
				break;
			case(8):
				break;

			default:
				cout << "Please Enter a Number from 1 to 7." << endl;
				break;
		}

	}
	f.printTable();

	return 0;
}
