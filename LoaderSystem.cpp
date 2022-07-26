#include "include/LoaderSystem.h"
#include <fstream>
#include <iostream>
#define string std::string
#define list std::list

LoaderSystem::LoaderSystem() {

}

LoaderSystem::~LoaderSystem() {

}

LoaderSystem& LoaderSystem::getInstance() {
	static LoaderSystem instance;
	return  instance;
}

void LoaderSystem::tick(ECS::World* world, float deltatime) {

}

list<sf::RectangleShape>* LoaderSystem::load_level(CString path) {
	std::ifstream file("./levels/" + path);
	string str;
	list<string> lines;
	list<sf::RectangleShape>* level = new list<sf::RectangleShape>();

	while (std::getline(file, str)) lines.push_back(str);

	string de = "]"; //delimiter
	list<string> elements;
	size_t p = 0;
	for (string s : lines) {
		while ((p = s.find(de)) != string::npos) {
			elements.push_back(s.substr(0, p));
			s.erase(0, p + de.length());
		}
	}

	//lines.clear();	// clear list so we can reuse it and not make a new list
	int rect_points[4];
	int index = 0;
	for (string s : elements) {
		s.erase(std::remove(s.begin(), s.end(), '['));
		s.erase(std::remove(s.begin(), s.end(), ' '));

		de = ",";
		p = 0;
		while ((p = s.find(de)) != string::npos) {
			//lines.push_back(s.substr(0, p));
			rect_points[index++] = std::stoi(s.substr(0, p));
			s.erase(0, p + de.length());
		}
		sf::RectangleShape r;
		r.setSize(sf::Vector2f(rect_points[2], rect_points[3]));
		r.setPosition(rect_points[0], rect_points[1]);
		level->push_back(r);
		index = 0;
		//lines.clear();
	}

	return level;
}
