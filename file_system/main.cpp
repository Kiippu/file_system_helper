#define _CRT_SECURE_NO_WARNINGS



#include "FileSystemHelper.h"
#include <iostream>
#include <fstream>
#include <algorithm>    // std::find
#include <vector>


namespace fs = std::experimental::filesystem;
using namespace std;


int main() {

	// TEST DATA: START

	std::string pathName("test/a/b");

	FileSystemHelper::getInstance().createFolder(pathName);
	

	fs::create_directories("sandbox/a/b");
	vector<string> e_files = {
		"./sandbox/a/b/file1.rst",
		"./sandbox/a/b/file1.txt",
		"./sandbox/a/file2.RST",
		"./sandbox/file3.md",
		"./sandbox/will_be.ignored"
	};

	FileSystemHelper::getInstance().writeToFileAppend("./logging", "kory", "json", "apples1 are amazing with false");
	FileSystemHelper::getInstance().writeToFileAppend("./sandbox", "kory", "json", "apples2 are amazing with true", true);
	FileSystemHelper::getInstance().writeToFileAppend("./sandbox", "kory", "json", "apples3 are amazing with false",false, "ERROR");
	FileSystemHelper::getInstance().writeToFileAppend("./sandbox", "kory", "json", "apples4 are not amazing with true",true, "SYSTEM_ERROR");

	std::cout << std::string("").size();

	std::vector<std::string> list;
	std::vector<std::string> ext;
	ext.push_back(".json");
	ext.push_back(".txt");
	list = FileSystemHelper::getInstance().getDirectoryFiles("././sandbox",ext);

	for (auto obj : list) {
		std::cout << obj << endl;

	}
	
	// TEST DATA: END


	return 0;
}