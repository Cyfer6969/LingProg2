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

#define SPAM_LIMIT				45


using std::vector;
using std::string;

class Files {

	static const vector<string> NAME_VECTOR[];
	public:
		Files(int, int);
		~Files();
		void printTable();
		void printEmail(int, int);
		void printAllEmails(int);
		void classifyEmail(vector<string>);

		int getTotal();
//		string getSpam();
		void setEmail(string, int);
		void setTotal(int);
		void setSpam(string, int);
		int getSpamCount();

	private:
		int total;
		int spamCounter;
		bool FULL;
		vector<vector<string> > email;
		vector<string> emailTopic;
		//estrutura = ID, NOME_ARQUIVO, FROM, SUBJECT, DATE, HOUR, BODY, SPAM
};

#endif
