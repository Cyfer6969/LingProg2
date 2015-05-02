#include "files.h"


Files::Files(int topics, int total_){

	total = total_;
	email.resize(total);

	for (int i = 0; i < total; ++i)
    	email[i].resize(topics);
	
	for(i = 0; i < total; i++){
		for(j = 0; j < topics; j++)
			email[i][j] = " ";
	}
}

Files::~Files(){
}

void Files::printTable(){

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
	FILE.open(string, ios::in);

	if ( FILE.is.open() ) {
		while( getline(FILE,line) ) {
			cout << line << "/n"
		}	
	}

}

void setTotal(int T){
	total = T;
}