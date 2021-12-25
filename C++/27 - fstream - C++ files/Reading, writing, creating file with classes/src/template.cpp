#include <iostream>
using namespace std;
#include <fstream>
#include <template.h>

fstream fileop::myfile;
string fileop::content;

void fileop::makefile() {

    myfile.open("text.txt", ios::out);
    myfile.close();
    myfile.open("text.txt", ios::in | ios::out);
}


void fileop::writeonfile() {
    if (myfile.is_open()){
         myfile << "writing text";
    }
    myfile.close();
}

void fileop::readfile() {

    myfile.open("text.txt", ios::in | ios::out);
         cout << "File content: " << endl;
         
        while (getline(myfile, content)){
            cout << " " << content << endl;
        }
        myfile.close();
}

void fileop::checkfile() {

    myfile.open("text.txt");

    if (myfile.fail()){
        cout << "File not found, making file" << endl;
        makefile();
        writeonfile();
        readfile();
    } else{
        readfile();
    }
}
