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

void Files::setEmail(string){

	string line;
	std::ifstream FILE;
	FILE.open(line);

	if ( FILE.is_open() ) {
		while( getline(FILE,line) ) {
			std::cout << line << std::endl;
		}
	}

}

void Files::setTotal(int T){
	total = T;
}

void Files::printEmail(int topics){

	for (int i=0; i < total; i++){
		for(int j=0; j < topics; j++){
			std::cout << email[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

