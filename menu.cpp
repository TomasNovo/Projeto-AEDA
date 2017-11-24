#include "menu.h"
#include "ui_utilities.h"
#include "utilities.h"
#include <fstream>

using namespace std;

menu::menu()
{}

menu::menu(unsigned int width, unsigned int height) : width(width), height(height)
{}

void menu::Begin()
{
	PreMenu();
}

void menu::PreMenu()
{

	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	string tempstr;

	while(1)
	{
		cout <<"\n Insert input filename (leave empty for default: \"inputfile\"): ";

		getline(cin, tempstr);
		utilities::trimString(tempstr);
		if (tempstr == "")
			tempstr = "inputfile";

		if (gestor.LoadPraias(tempstr))
			break;
		else
			cout << "File doesn't exist!";

	}
	cout << "\n";

	while (1)
	{
		cout <<"\n Insert banner filename (leave empty for default: \"bannerfile\"): ";

		getline(cin, tempstr);
		utilities::trimString(tempstr);
		if (tempstr == "")
			tempstr = "bannerfile";

		if (LoadBanner(tempstr))
			break;
		else
			cout << "File doesn't exist!";
	}

	cout << "\n\n   All files have been loaded with success. Press enter to continue...";
	getline(cin, tempstr);

	MainMenu();
}


void menu::MainMenu()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

	cout << "Enter a number to choose the sub-menu that you want to go !\n\n";
	cout << "1- See a river beach by inserting name \n";
	cout << "2- See a river beach by inserting GPS \n";
	cout << "3- Discover the nearest beach around your GPS coordenates	\n";
	cout << "4- See the beaches of a county \n";
	cout << "5- See the services of a beach \n";
	cout << "0- Quit \n\n";


	string input;

	while (true)
	{
		cout << "Select an option: ";

		getline(cin, input);
		utilities::trimString(input);
		cout << "\n";

		if (input == "1")
		{
			AddPraia();
			break;
		}

		else if (input == "2")
		{
			RemovePraia();
			break;
		}

		else if (input == "3")
		{
			ListPraias();
			break;
		}

		else if (input == "4")
		{
			SearchPraiaByName();
			break;
		}

		else if (input == "5")
		{
			SearchPraiaByGPS();
			break;
		}

		else if (input == "6")
		{
			SearchNearestBeach();
			break;
		}

		else if (input == "7")
		{
			SearchPraiaByCounty();
			break;
		}

		else if (input == "0")
			return;

		else
			cout << "Invalid input\n";

	}
}

void menu::AddPraia()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

	string tempstr, tipo, nome, concelho;
	GPS gps;
	bool bandeiraazul;
	int capacidade, larguraMax, caudalMax, profundidadeMax, area;
	vector<servico> tempServicos;

	cout << "\n\nEnter the information of the river beach that you want to add! (write \".\" at any time to go back)\n";

	while(1)
	{
		cout << "Please enter the type of the beach (\"rio\" or \"albufeira\")\n";

		getline(cin, tipo);
		utilities::trimString(tipo);

		if (name == ".")
			return;

		if (tipo == "rio" || tipo == "albufeira")
			break;

		cout << "Wrong type! Must be either \"rio\" or \"albufeira\"\n\n";
	}

	while(1)
	{
		cout << "Please enter the name of the beach\n";

		getline(cin, nome);
		utilities::trimString(nome);

		if (name == ".")
			return;

		if (name != "")
			break;

		cout << "You need to write something!\n\n";
	}

	while(1)
	{
		cout << "Please enter the county of the beach\n";

		getline(cin, concelho);
		utilities::trimString(concelho);

		if (concelho == ".")
			return;

		if (concelho != "")
			break;

		cout << "You need to write something!\n\n";
	}

	while(1)
	{
		cout << "Please enter the latitude coordinate of the beach\n";

		getline(cin, tempstr);
		utilities::trimString(tempstr);

		if (tempstr == ".")
			return;

		string tempstr2;

		cout << "Please enter the longitude coordinate of the beach\n";

		getline(cin, tempstr2);
		utilities::trimString(tempstr2);

		if (tempstr2 == ".")
			return;

		try
		{
			gps = GPS(stod(tempstr), stod(tempstr2));
		}
		catch (exception &e)
		{
			cout << "Wrong Coordinates!\n";
			continue;
		}
		break;
	}

	while(1)
	{
		cout << "Does the beach have blue flag? (Y/N)\n";

		getline(cin, tempstr);
		utilities::trimString(tempstr);

		if (tempstr == ".")
			return;

		if (tempstr == "Y" || tempstr == "y")
			bandeiraazul = true;
		else
			bandeiraazul = false;

		break;
	}

	while(1)
	{
		cout << "Please enter the capacity of the beach\n";

		getline(cin, tempstr);
		utilities::trimString(tempstr);

		if (tempstr == ".")
			return;

		try
		{
			capacidade = stoi(tempstr);

			if (capacidade < 0)
			{
				cout << "Capacity must be an unsigned integer!\n";
				continue;
			}

			break;
		}
		catch (exception &e)
		{
			cout << "Capacity must be an unsigned integer!\n";
		}

	}

	if (tipo == "rio")
	{

		while(1)
		{
			cout << "Please enter the maximum width of the beach\n";

			getline(cin, tempstr);
			utilities::trimString(tempstr);

			if (tempstr == ".")
				return;

			try
			{
				larguraMax = stoi(tempstr);

				if (larguraMax < 0)
				{
					cout << "The maximum width must be an unsigned integer!\n";
					continue;
				}

				break;
			}
			catch (exception &e)
			{
				cout << "The maximum width must be an unsigned integer!\n";
			}

		}

		while(1)
		{
			cout << "Please enter the maximum volume of water of the beach\n";

			getline(cin, tempstr);
			utilities::trimString(tempstr);

			if (tempstr == ".")
				return;

			try
			{
				caudalMax = stoi(tempstr);

				if (caudalMax < 0)
				{
					cout << "The maximum volume must be an unsigned integer!\n";
					continue;
				}

				break;
			}
			catch (exception &e)
			{
				cout << "The maximum volume must be an unsigned integer!\n";
			}

		}

		while(1)
		{
			cout << "Please enter the maximum depth of the beach\n";

			getline(cin, tempstr);
			utilities::trimString(tempstr);

			if (tempstr == ".")
				return;

			try
			{
				profundidadeMax = stoi(tempstr);

				if (profundidadeMax < 0)
				{
					cout << "The maximum depth must be an unsigned integer!\n";
					continue;
				}

				break;
			}
			catch (exception &e)
			{
				cout << "The maximum depth must be an unsigned integer!\n";
			}

		}

	}
	else
	{
		while(1)
		{
			cout << "Please enter the area of the beach\n";

			getline(cin, tempstr);
			utilities::trimString(tempstr);

			if (tempstr == ".")
				return;

			try
			{
				area = stoi(tempstr);

				if (area < 0)
				{
					cout << "The area must be an unsigned integer!\n";
					continue;
				}

				break;
			}
			catch (exception &e)
			{
				cout << "The area must be an unsigned integer!\n";
			}

		}

	}

	while(1)
	{
		cout << "Enter a service of the beach (write \"..\" to end input of services)";
		string tipo, nome;
		GPS gps2;

		while(1)
		{
			cout << "Please enter the type of the service\n";

			getline(cin, tipo);
			utilities::trimString(tipo);

			if (tipo == ".")
				goto endinput;

			if (tipo == "nadadorSalvador" || tipo == "cafe" || tipo == "restaurante" || tipo == "campoDesportivo")
				break;

			cout << "Wrong type\n";
		}

		while(1)
		{
			cout << "Please enter the name of the service\n";

			getline(cin, nome);
			utilities::trimString(nome);

			if (nome == ".")
				goto endinput;

			if (nome == "")
			{
				cout << "You need to enter something\n";
				continue;
			}

			break;
		}

		while(1)
		{
			cout << "Please enter the latitude coordinate of the beach\n";

			getline(cin, tempstr2);
			utilities::trimString(tempstr2);

			if (tempstr2 == ".")
				return;

			string tempstr3;

			cout << "Please enter the longitude coordinate of the beach\n";

			getline(cin, tempstr3);
			utilities::trimString(tempstr3);

			if (tempstr2 == ".")
				return;

			try
			{
				gps2 = GPS(stod(tempstr2), stod(tempstr3));
			}
			catch (exception &e)
			{
				cout << "Wrong Coordinates!\n";
				continue;
			}
			break;
		}


	}

	endinput: 

}


void menu::RemovePraia()
{



}

void menu::ListPraias()
{




}

void menu::SearchPraiaByName()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

	string tempstr;

	cout << "Enter the name of the river beach that you want to get info !\n";

	cout << "Please enter the name of the beach\n";
	getline(cin, tempstr);
	utilities::trimString(tempstr);

	praiaFluvial * temp = gestor.findPraia(tempstr);

	if (temp == nullptr)
	{
		cout << "Beach not found!\n";
		cout << "Would you like to try again ? (Y/N) \n";
		getline(cin, tempstr);

		if (tempstr == "Y" || tempstr == "y")
			SearchPraiaByName();
	}
	else
	{
		cout << '\n' << *temp;
		getline(cin, tempstr);
	}


}

void menu::SearchPraiaByGPS()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

	string tempstr;
	double latitude, longitude;

	cout << "Enter the GPS coordinates of the river beach that you want to get info !\n";

	try
	{
		cout << "Please enter the latitude of the beach\n";
		getline(cin, tempstr);
		utilities::trimString(tempstr);
		latitude = stod(tempstr);

		cout << "Please enter the longitude of the beach\n";
		getline(cin, tempstr);
		utilities::trimString(tempstr);
		longitude = stod(tempstr);

		praiaFluvial * temp = gestor.findPraia(GPS(latitude, longitude));

		if (temp == nullptr)
		{
			cout << "Beach not found!\n";
			cout << "Would you like to try again ? (Y/N) \n";
			getline(cin, tempstr);

			if (tempstr == "Y" || tempstr == "y")
				SearchPraiaByGPS();
		}
		else
		{
			cout << '\n' << *temp;
			getline(cin, tempstr);
		}
	}
	catch (exception& e)
	{
			cout << "Invalid coordinates!\n";
			cout << "Would you like to try again ? (Y/N) \n";
			getline(cin, tempstr);

			if (tempstr == "Y" || tempstr == "y")
				SearchPraiaByGPS();
	}
}

void menu::SearchNearestBeach()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

	double latitude, longitude;

	cout << "Please enter the latitude of the position you want to calculate the nearest beach ! \n";
	cout << "Latitude: ";
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please write a valid number ! \n";
		cin >> latitude;
	}

	cout << "Now please enter the longitude ! \n";
	cout << "Longitude: ";
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please write a valid number ! \n";
		cin >> longitude;
	}

	GPS gps(latitude, longitude);

	praiaFluvial *pf;
	pf = gestor.getClosestPraia(gps);

	cout << "The nearest beach is " << pf->getNome();
}

void menu::SearchPraiaByCounty()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

	string county;

	cout << "Please input the county ! \n";
	cout << "County: ";
	getline(cin, county);


}

/*void menu::DisplayPraiaServices()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();
	
	string praia;
	cout << "Enter the name of the river beach that you want to get info !\n";
	cout << "Name of the beach: ";
	getline(cin, praia);

	praiaFluvial * temp = gestor.findPraia(praia);

}*/

unsigned int menu::getWidth()
{
	return width;
}

unsigned int menu::getHeight()
{
	return height;
}


void menu::setWidth(unsigned int width)
{
	this->width = width;
}

void menu::setHeight(unsigned int height)
{
	this->height = height;
}

bool menu::LoadBanner(string filename) {

	ifstream file(filename);

	if (!file.is_open())
		return false;

	string tempstr;

	while(getline(file, tempstr, '\n'))
	{
		banner.push_back(tempstr);
	}

	return true;
}

void menu::PrintBanner() {

	for (int i = 0; i < banner.size(); ++i)
	{
		cout << string((width - banner[i].size())/2, ' ') << banner[i] << '\n';
	}

	cout << '\n';
}