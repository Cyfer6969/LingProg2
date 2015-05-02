#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using std::vector;
using std::string;

class Files {

	public:
		Files(int, int);
		~Files();
		void printTable();

		int getTotal();
		void setEmail(string);
		void setTotal(int);
	private:
		int total;
		vector<vector<string> > email;
};

#endif