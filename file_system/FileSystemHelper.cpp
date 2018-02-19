#define _CRT_SECURE_NO_WARNINGS
#include "FileSystemHelper.h"
#include <iostream>
#include <sys\stat.h>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


namespace fs = std::experimental::filesystem;
using namespace std;


void FileSystemHelper::createFolder(std::string pathName)
{
	fs::path tempPath{ pathName };
	fs::create_directories(tempPath);
}

void FileSystemHelper::removeFolders(std::string pathName)
{
	fs::path tempPath{ pathName };
	fs::remove_all(tempPath);
}

vector<string> FileSystemHelper::getDirectoryFiles(const string & dir, const vector<string> & extensions)
{
	vector<string> files;
	for (auto & p : fs::recursive_directory_iterator(dir))
	{
		if (fs::is_regular_file(p))
		{
			if (extensions.empty() || find(extensions.begin(), extensions.end(), p.path().extension().string()) != extensions.end())
			{
				files.push_back(p.path().string());
			}
		}
	}
	return files;
}

void FileSystemHelper::createFile(std::string path, std::string fileName, std::string extension)
{
	fs::path dir = path;
	fs::path file_name = fileName;
	fs::path fileCreate = dir / file_name / "." / extension;
	std::ofstream(fileCreate) << "";
}

void FileSystemHelper::writeToFileAppend(std::string path, std::string filename, std::string extension, std::string stream, std::string msgType = "")
{
	using namespace std::chrono;

	fs::path dir = path;
	fs::path file_name = filename + "." +  extension;
	fs::path file = dir / file_name;

	cout << file;
	std::ofstream out;
	out.open(file,std::ios::app);
	if (out.is_open()) {
		if (msgType.size() > 1) {
			auto time_point = system_clock::now();
			std::time_t now_c = std::chrono::system_clock::to_time_t(time_point);
			auto time = std::ctime(&now_c);
			auto str_time = std::string(time).substr(0, std::string(time).size() - 2);
			out << "\n[\'" << msgType << "\'][ " << str_time << " ] \"" << stream << "\"" << std::endl;
		}
		else {
			out << "\n" << stream;
		}
	}
	else {
		cout << "[\'ERROR\'] { " << file << " } was not opened or found." << endl;
	}
	out.close();
}
