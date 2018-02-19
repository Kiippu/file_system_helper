#pragma once


#include <string>
#include <vector>
#include <filesystem>



class FileSystemHelper
{
public:
	static FileSystemHelper & getInstance() {
		static FileSystemHelper instance;
		return instance;
	}

private:
	FileSystemHelper() {};

public:
	FileSystemHelper(const FileSystemHelper&)	= delete;
	void operator=(FileSystemHelper const&)		= delete;

	void createFolder(std::string path);
	void removeFolders(std::string pathName);

	std::vector<std::string> getDirectoryFiles(const std::string & dir, const std::vector<std::string>& extensions);

	void createFile(std::string path ,std::string fileName, std::string extension);

	void writeToFileAppend(std::string path, std::string filename, std::string extension, std::string stream, std::string msgType);

	//void getFile(std::string fileName, std::string extension);

	//vector<string> getDirectoryFiles(const string & dir, const vector<string> & extensions);





};

