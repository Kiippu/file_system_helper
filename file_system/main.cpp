#define _CRT_SECURE_NO_WARNINGS



#include "FileSystemHelper.h"
#include <iostream>
#include <fstream>
#include <algorithm>    // std::find
#include <vector>


namespace fs = std::experimental::filesystem;
using namespace std;


int main() {

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

	FileSystemHelper::getInstance().writeToFileAppend("./sandbox","kory","json","apples are amazing","");
	FileSystemHelper::getInstance().writeToFileAppend("./sandbox", "kory", "json", "apples are amazing", "");
	FileSystemHelper::getInstance().writeToFileAppend("./sandbox", "kory", "json", "apples are amazing", "ERROR");

	

	return 0;
}