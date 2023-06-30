#include "utils.h"
#include "Tamagotchi.h"

std::vector<std::string> utils::get_files(std::string path)
{
	std::vector < std::string > data;
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		auto d = entry.path().filename().generic_string().length();
		data.push_back((entry.path().filename().generic_string().substr(0, d-4)));
	}
	return data;
}

void heartbeat()
{
	do
	{
		
	} while (atoi(tama.getAllData().at(2).c_str()) == 0);
}