#include "utils.h"
#include <cstdio>


std::vector<std::string> utils::get_files(std::string path)
{
	std::vector < std::string > data;
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		data.push_back((entry.path().filename().string()));
	}
	return data;
}
