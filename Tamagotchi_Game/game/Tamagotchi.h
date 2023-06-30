#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <sstream>
#include "utils.h"

class Tamagotchi
{
	std::string name;
	int age;
	int health;
	int hunger;
	int mood;
	int money;
	int sleep;
	int clean;
	int energy;
	int weight;
	int height;
	int level;
	int exp;
	int expNext;

		// Методы для получения значений переменных
public:
		std::vector<std::string> getAllData() const {
			std::vector<std::string> data;
			data.push_back(this->name);
			data.push_back(std::to_string(age));
			data.push_back(std::to_string(health));
			data.push_back(std::to_string(hunger));
			data.push_back(std::to_string(mood));
			data.push_back(std::to_string(sleep));
			data.push_back(std::to_string(clean));
			data.push_back(std::to_string(energy));
			data.push_back(std::to_string(weight));
			data.push_back(std::to_string(height));
			data.push_back(std::to_string(level));
			data.push_back(std::to_string(exp) + " // " + std::to_string(expNext));
			return data;
		}
		void setName(const std::string& n) {
			name = n;
		}

		void setAge(int a) {
			age = a;
		}

		void setHealth(int h) {
			health = h;
		}

		void setHunger(int hu) {
			hunger = hu;
		}

		void setMood(int m) {
			mood = m;
		}

		void setMoney(int mo) {
			money = mo;
		}

		void setSleep(int sl) {
			sleep = sl;
		}

		void setClean(int c) {
			clean = c;
		}

		void setEnergy(int e) {
			energy = e;
		}

		void setWeight(int w) {
			weight = w;
		}

		void setHeight(int he) {
			height = he;
		}

		void setLevel(int l) {
			level = l;
		}

		void setExp(int ex) {
			exp = ex;
		}

		void setExpNext(int en) {
			expNext = en;
		}

		void set_default()
		{
			this->setAge(0);
			this->setLevel(1);
			this->setExp(0);
			this->setHealth(100);
			this->setHunger(100);
			this->setMood(100);
			this->setSleep(100);
			this->setClean(100);
			this->setEnergy(100);
			this->setWeight(10);
			this->setHeight(10);
			this->setMoney(100);
			this->setExpNext(0);
		}
		
        bool save_game()
        {
			std::string homedrive = getenv("HOMEDRIVE");
			std::string homepath = getenv("HOMEPATH");
			std::string folder_path = homedrive + homepath + "\\Documents\\vos.team\\Tamagotchi\\";			std::string Tamagotchi_path = homedrive + homepath + "\\Documents\\vos.team\\";
			if (!std::filesystem::exists(folder_path)) {
				std::filesystem::create_directories(Tamagotchi_path + "Tamagotchi");

			}
				std::ofstream file(folder_path + name + ".txt");
				file << name << std::endl;
				file << age << std::endl;
				file << health << std::endl;
				file << hunger << std::endl;
				file << mood << std::endl;
				file << money << std::endl;
				file << sleep << std::endl;
				file << clean << std::endl;
				file << energy << std::endl;
				file << weight << std::endl;
				file << height << std::endl;
				file << level << std::endl;
				file << exp << std::endl;
				file << expNext << std::endl;
				file.close();
				return true;

        }
        bool load_game(std::string n)
        {
			std::string homedrive = getenv("HOMEDRIVE");
			std::string homepath = getenv("HOMEPATH");
			std::string folder_path = homedrive + homepath + "\\Documents\\vos.team\\Tamagotchi\\";
			std::ifstream file(folder_path + n + ".txt");
			if (file.is_open()) {
				std::vector<std::string> vec;
				std::string line;
				while (getline(file, line)) {
					vec.push_back(line);
				}
				this->setName(vec[0]);
				this->setAge(atoi(vec[1].c_str()));
				this->setHealth(atoi(vec[2].c_str()));
				this->setHunger(atoi(vec[3].c_str()));
				this->setMood(atoi(vec[4].c_str()));
				this->setMoney(atoi(vec[5].c_str()));
				this->setSleep(atoi(vec[6].c_str()));
				this->setClean(atoi(vec[7].c_str()));
				this->setEnergy(atoi(vec[8].c_str()));
				this->setWeight(atoi(vec[9].c_str()));
				this->setHeight(atoi(vec[10].c_str()));
				this->setLevel(atoi(vec[11].c_str()));
				this->setExp(atoi(vec[12].c_str()));
				this->setExpNext(atoi(vec[13].c_str()));
				file.close();
				return true;
			}
			else
				return false;
        }
};

inline Tamagotchi tama;