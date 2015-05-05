#include "files.h"


Files::Files(int topics, int total_){

	FULL = false;
	Files::setTotal(total_);

	email.resize(total);
	for (int i = 0; i < total; ++i)
		email[i].resize(topics);

	for(int i = 0; i < total; i++){
		for(int j = 0; j < topics; j++)
			email[i][j] = "0";
	}


	emailTopic.resize (EMAIL_ELEMENTS);
	emailTopic[0] = "RDATE";
	emailTopic[1] = "RDATE_HOUR";
	emailTopic[2] = "SDATE";
	emailTopic[3] = "SDATE_HOUR";
	emailTopic[4] = "FROM";
	emailTopic[5] = "SUBJECT";
	emailTopic[6] = "BODY";
	emailTopic[7] = "SPAM";


}

Files::~Files(){
}

void Files::printTable(){
	if(!FULL){
		std::cout << "Id \t From \t Subject \t "
					 "R.Date \t R.Hour \t Spam"
				  << std::endl;
		for (int i = 1; i <= total; i++) {

			std::cout << i << "\t"
					  << email[i-1][FROM] << "\t"
					  << email[i-1][SUBJECT] << "\t\t"
					  << email[i-1][RDATE] << "\t\t"
					  << email[i-1][RDATE_HOUR] << "\t\t"
					  << email[i-1][SPAM] << "\t"
					  << std::endl << std::endl;
		}

	}
}

int Files::getTotal(){
	return total;
}

// string** Files::getEmail(){
// 	return email;
// }

void Files::setEmail(string filename, int ID){

	string line;
	int counter = 0;

	std::ifstream file(filename);

	if ( file.is_open() ) {
		while( getline(file,line) ) {
	//		std::cout << line << std::endl;
			if (counter < 4){
				if (line.find("Date:") != -1 && counter == 0){
					email[ID][RDATE] = line.erase (0, 4+2+3);
					counter = 1;
				}else if(line.find("Date:") != -1 && counter == 1){
					email[ID][SDATE] = line.erase (0, 4+2);
					counter = 2;
				}else if(line.find("From:") != -1 && counter == 2){
					email[ID][FROM] = line.erase (0, 4+2);
					counter = 3;
				}else if(line.find("Subject:") != -1 && counter == 3){
					email[ID][SUBJECT] = line.erase (0, 7+2);
					counter = 4;
				}
			}else
			email[ID][BODY] += line;
		}
	} else {
		std::cout << "Problem opening file" << std::endl;
	}

	email[ID][SPAM] = "Not Classified Yet";

	file.close ();
}

void Files::setTotal(int T){
	total = T;
}

void Files::printEmail(int topics, int ID){

	for(int j=0; j < topics; j++){
		std::cout << emailTopic[j] << ": " << email[ID][j] << " ";
		std::cout << std::endl;
	}

}

void Files::printAllEmails(int topics){

	for (int i=0; i < total; i++){
		for(int j=0; j < topics; j++){
			std::cout << email[i][j] << std::endl;
		}
		std::cout << std::endl;
	}

}

int Files::getSpamCount(){

	spamCounter = 0;
	string aux;
	for(int i = 0; i < total; i++){
		aux = email[i][SPAM];
		if(aux.find("S") != -1){
			spamCounter++;
		}
	}
	return spamCounter;
}

void Files::setSpam (string spam, int ID){
	email[ID][SPAM] = spam;
}

void Files::classifyEmail(vector<string> email){

//	total = email.size();
	for (int i = 0; i < email.size(); i++){

	int result = 0; //resultado do API em Perl
	//result = chamadaDoPerl(email[i]) -> email[i] [e o endereco do email.txt para cada email existente

	if (result >= SPAM_LIMIT)
		this->setSpam("Yes", i);
	else
		this->setSpam("No", i);
	}
}

