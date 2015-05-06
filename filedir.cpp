#include "filedir.h"

using namespace std;

FileDir::FileDir (string n) {
	setNameDir (n);
	openDir ();
}
FileDir::~FileDir () {
	if (dp != NULL) closedir (dp);

}

void FileDir::openDir () {
	if((dp = opendir(nameDir.c_str())) == NULL) {
		cout << "Error opening " << nameDir << endl;
		exit (1);
	}

}

int FileDir::readDir () {
	dir.clear ();

	while ((dirp = readdir(dp)) != NULL) {
		dir.push_back(string(dirp->d_name));
	}

	rewinddir (dp);
	return dir.size ();
}

void FileDir::listDir () {
	for (unsigned i = 0; i < dir.size (); i++) {
		cout << dir.at (i) << endl;
	}

}
void FileDir::setNameDir (string n) { nameDir = n;}

int FileDir::searchDir (string extension, vector<string> files){
	int emailCounter = 0;
	dir.clear ();

	while ((dirp = readdir(dp)) != NULL) {

		if(string(dirp->d_type) == DT_REG){

			string filename = dirp->d_name;

			if(filename.find(extension, (filename.lenght() - extension.lenght()) ) != string::npos ){

				string directory = nameDir;
				directory.append (string(dirp->d_name));
				files.push_back(directory);
				emailCounter++;
			}

		}

	}
	return emailCounter;

}
