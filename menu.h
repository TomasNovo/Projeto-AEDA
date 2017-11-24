#ifndef MENU_H
#define MENU_H

#include "praias.h"
#include <string>
#include <vector>

class menu {

	GestorPraias gestor;
	unsigned int width = 100;
	unsigned int height = 30;
	std::vector<std::string> banner;

public:
	menu();
	menu(unsigned int widht, unsigned int height);

	void Begin();
	void PreMenu();
	void MainMenu();
	void AddPraia();
	void RemovePraia();
	void ListPraias();
	void SearchPraia();
	void SearchNearestBeach();
	void SearchPraiaByCounty();
	//void DisplayPraiaServices();

	unsigned int getWidth();
	unsigned int getHeight();

	void setWidth(unsigned int width);
	void setHeight(unsigned int height);
	
	bool LoadBanner(std::string filename);
	void PrintBanner();

};


#endif