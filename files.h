#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#define EMAIL_ELEMENTS          8

#define RDATE                   0
#define RDATE_HOUR              1
#define SDATE                   2
#define SDATE_HOUR              3
#define FROM                    4
#define SUBJECT                 5
#define BODY                    6

#define SPAM                    7

using std::vector;
using std::string;

class Files {

	public:
		Files(int, int);
		~Files();
		void printTable();
		void printEmail(int topics);

		int getTotal();
		void setEmail(string);
		void setTotal(int);
	private:
		int total;
		bool FULL;
		vector<vector<string> > email;
		//estrutura = ID, NOME_ARQUIVO, FROM, SUBJECT, DATE, HOUR, BODY, SPAM
};

#endif
