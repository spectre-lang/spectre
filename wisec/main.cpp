#include <iostream>
#include "codegarmmar.tab.h"
#include "compiler.h"
#include <string>
//#include "consolecolor.h"
using namespace std;
using namespace wisec;

int main() {
	FILE* file;
	fopen_s(&file, "DemoClass.wise", "r");
	if (!file) {
		cout << "can not open the file!" << endl;
	}
	else {
		Compiler compiler;
		compiler.append_file(file);
		compiler.compile_class_files();
		
		for (ClassFile& class_file : compiler.get_class_files()) {
			auto information = class_file.get_information();
			cout << endl;
			if (information.empty()) {
				//cout << green << "0 error, 0 warning!" << white << endl;
				cout << "0 error, 0 warning!" << endl;
			}
			else {
				//cout << yellow << information.size() << " result string(s)" << endl;
				cout << information.size() << " result string(s)" << endl;
				for (int i = 0; i < information.size(); i++) {
					//cout << white << i << "\t";
					//wcout << red << information[i].get_name() << "\t";
					cout << i << "\t";
					cout << information[i].get_name() << "\t";
					if (!information[i].get_message().empty()) {
						//wcout << white << information[i].get_message();
						cout << information[i].get_message();
					}
					cout << endl;
				}
			}
		}

		fclose(file);
	}
}