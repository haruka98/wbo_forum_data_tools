#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <filesystem>
#include <fstream>
#include <iomanip>

bool sorter(std::pair<std::vector<std::string>, long long> i, std::pair<std::vector<std::string>, long long> j) {
	return (i.second > j.second);
}

int main(int argc, char* argv[]) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <path to input folder>" << std::endl;
		return 1;
	}
	std::vector<std::pair<std::vector<std::string>, long long>> name_list = {
		{{ "Ifraid", "Ifrit" }, 0 },
		{{ "Saramanda", "Salamander" }, 0 },
		{{ "Orojya", "Orochi" }, 0 },
		{{ "Phoenic", "Phoenix" }, 0 },
		{{ "Revizer", "Leviathan" }, 0 },
		{{ "Gryph", "Griffin" }, 0 },
		{{ "Killerken", "Kraken" }, 0 },
		{{ "Dragooon", "Dragoon" }, 0 },
		{{ "Gargole", "Gargoyle" }, 0 },
		{{ "Goreim", "Golem" }, 0 },
		{{ "Begirados", "Behemoth" }, 0 },
		{{ "Genbu" }, 0 },	// includes Genbull
		{{ "Balro" }, 0 },
		{{ "Girago", "Zirago" }, 0 },
		{{ "Wyvang" }, 0 },
		{{ "Pegasis", "Pegasus" }, 0 },
		{{ "Bahamdia", "Bahamoote" }, 0 }
	};
	for(std::filesystem::directory_iterator next(argv[1]), end; next != end; next++) {
		if(next->path().extension() == ".html") {
			std::ifstream file(next->path().string());
			std::string line = "";
			while(std::getline(file, line)) {
				for(int i = 0; i < name_list.size(); i++) {
					for(int j = 0; j < name_list[i].first.size(); j++) {
						std::size_t found = std::string::npos;
						do {
							found = line.find(name_list[i].first[j], found + 1);
							if(found != std::string::npos) {
								name_list[i].second++;
							}
						} while(found != std::string::npos);
					}
				}
			}
			file.close();
		}
	}
	std::sort(name_list.begin(), name_list.end(), sorter);
	long long total_counter = 0;
	for(int i = 0; i < name_list.size(); i++) {
		total_counter += name_list[i].second;
	}
	for(int i = 0; i < name_list.size(); i++) {
		double percent = (double)100 * ((double)name_list[i].second / (double)total_counter);
		std::cout << name_list[i].first[0] << ": " << name_list[i].second << " ~" << std::fixed << std::setprecision(2) << percent << "%" << std::endl;
	}
	return 0;
}
