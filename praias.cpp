#include "praias.h"
#include "algoritmos.h"
#include "utilities.h"
#include <sstream>
#include <fstream>

using namespace std;

//------------------------------PRAIAFLUVIAL------------------------------

/**
 * @brief      Constructs the object.
 */
praiaFluvial::praiaFluvial()
{}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  concelho         The concelho
 * @param[in]  gps              The gps
 * @param[in]  bandeirazul      The bandeirazul
 * @param[in]  capacidade       The capacidade
 * @param[in]  servicosdapraia  The servicosdapraia
 */
praiaFluvial::praiaFluvial(string nome, string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, vector<servico> servicosdapraia) : nome(nome), concelho(concelho), gps(gps), bandeiraazul(bandeiraazul), capacidade(capacidade), servicosdapraia(servicosdapraia)
{}

praiaFluvial::~praiaFluvial()
{}

/**
 * @brief      Gets the praia's name.
 *
 * @return     The praia's name.
 */
string praiaFluvial::getNome() const {
	return this->nome;
}

/**
 * @brief      Gets the gps.
 *
 * @return     The gps.
 */
GPS praiaFluvial::getGPS() const {
	return this->gps;
}
/**
 * @brief      Gets the praia's concelho.
 *
 * @return     The praia's concelho.
 */
string praiaFluvial::getConcelho() const {
	return this->concelho;
}
/**
 * @brief      Gets the praia's bandeira azul.
 *
 * @return     The praia's bandeira azul.
 */
bool praiaFluvial::getBandeiraAzul() const {
	return bandeiraazul;
}

/**
 * @brief      Gets the praia's capacidade.
 *
 * @return     The praia's capacidade.
 */
unsigned int praiaFluvial::getCapacidade() const {
	return capacidade;
}

vector<servico> praiaFluvial::getServicos() const {
	return servicosdapraia;
}


string praiaFluvial::getTipo() const {
	return tipo;
}
/**
 * @brief      Gets the information from a praiaFluvial.
 *
 * @return     The information.
 */
string praiaFluvial::getInfo() const
{
	string info;

	info += "Tipo da praia: " + tipo + ", ";
	info += "Nome da praia: " + nome + ", ";
	info += "Concelho onde a praia se situa: " + concelho + ", ";
	info += "Capacidade da praia: " + to_string(capacidade) + ", ";
	if (bandeiraazul == true)
	{
		info += "A praia possui bandeira azul, ";
	}
	else
	{
		info += "A praia nao possui bandeira azul, ";
	}

	return info;
}


void praiaFluvial::setGPS(GPS gps) {
	this->gps = gps;
}

void praiaFluvial::setNome(string nome) {
	this->nome = nome;
}

void praiaFluvial::setTipo(string tipo) {
	this->tipo = tipo;
}

bool praiaFluvial::operator<(const praiaFluvial& praia1) const {
	if (this->concelho != praia1.getConcelho())
		return (this->concelho < praia1.getConcelho());

	else
		return (this->bandeiraazul < praia1.getBandeiraAzul());
}

bool praiaFluvial::operator==(const praiaFluvial& praia1) const {
	return (this->nome == praia1.getNome());
}

unsigned int praiaFluvial::getLargura() const {
	return 0;
}

unsigned int praiaFluvial::getCaudal() const {
	return 0;
}

unsigned int praiaFluvial::getProfundidade() const {
	return 0;
}

unsigned int praiaFluvial::getArea() const {
	return 0;
}

//------------------------------RIO------------------------------

rio::rio()
{
	setTipo("rio");
}

rio::rio(string nome, string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, vector<servico> servicosdapraia, unsigned int larguraMax, unsigned int caudalMax, unsigned int profundidadeMax): praiaFluvial(nome,concelho,gps,bandeiraazul,capacidade, servicosdapraia), larguraMax(larguraMax), caudalMax(caudalMax), profundidadeMax(profundidadeMax)
{
	setTipo("rio");
}

rio::~rio()
{}


unsigned int rio::getLargura() const {
	return larguraMax; 
}

unsigned int rio::getCaudal() const { 
	return caudalMax;
}

unsigned int rio::getProfundidade() const {
	return profundidadeMax;
}

string rio::getInfo() const
{
	string info_rio = praiaFluvial::getInfo();

	info_rio += "A praia trata-se de uma praia fluvial de rio, ";
	info_rio += "Largura Minima da praia: " + to_string(larguraMax) + ", ";
	info_rio += "Caudal Maximo da praia: " + to_string(caudalMax) + ", ";
    info_rio += "Profundidade Maximo da praia: " + to_string(profundidadeMax);

	return info_rio;
}

//------------------------------ALBUFEIRA------------------------------

albufeira::albufeira()
{
	setTipo("albufeira");
}

albufeira::albufeira(string nome, string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, vector<servico> servicosdapraia, unsigned int area) : praiaFluvial(nome, concelho, gps, bandeiraazul, capacidade, servicosdapraia), area(area)
{
	setTipo("albufeira");
}

albufeira::~albufeira()
{}


unsigned int albufeira::getArea() const {
	return area;
}

string albufeira::getInfo() const
{
	string info_albufeira = praiaFluvial::getInfo();

	info_albufeira += "A praia trata-se de uma praia fluvial de albufeira, ";
	info_albufeira += "Area da albufeira: " + to_string(area);
	
	return info_albufeira;
}


//------------------------------GESTORPRAIAS------------------------------

/**
 * @brief      Constructs the Gestor .
 */
GestorPraias::GestorPraias()
{}

GestorPraias::GestorPraias(set<praiaFluvial*, classcomp> praias, vector<servicoForaDaPraia*> servicosdefora) : praias(praias), servicosdefora(servicosdefora)
{}

GestorPraias::~GestorPraias()
{}


int GestorPraias::praiaInfo(string praia) {

	set<praiaFluvial*, classcomp>::iterator it = this->findPraia(praia);

	if (it != praias.end())
	{
		cout << (*it)->getInfo();
		return 0;
	}

	return 1;
}

int GestorPraias::praiaInfoGPS(GPS gps) {

	set<praiaFluvial*, classcomp>::iterator it = this->findPraia(gps);

	if (it != praias.end())
	{
		cout << (*it)->getInfo();
		return 0;
	}

	return 1;
}

void GestorPraias::addPraia(praiaFluvial *praia) {
	praias.insert(praia);
}

void GestorPraias::removePraia(set<praiaFluvial*, classcomp>::iterator it) {
	praias.erase(it);
}


/**
 * @brief      Gets the closest praia.
 *
 * @param[in]  gps   The GPS coordinates
 *
 * @return     The closest praia to gps.
 */

void GestorPraias::setPraias(set<praiaFluvial*, classcomp> input) {
	praias = input;
}


set<praiaFluvial*, classcomp> GestorPraias::getPraias() {
	return praias;
}

vector<servicoForaDaPraia*> GestorPraias::getServicos() {
	return servicosdefora;
}

praiaFluvial GestorPraias::getPraia(set<praiaFluvial*, classcomp>::iterator it) {

	return (**it);
}

set<praiaFluvial*, classcomp>::iterator GestorPraias::getClosestPraia(GPS gps) {

	if (praias.size() == 0)
		return praias.end();

	set<praiaFluvial*, classcomp>::iterator it;

	set<praiaFluvial*, classcomp>::iterator min = praias.begin();

	for (it = praias.begin(); it != praias.end(); ++it)
	{
		if ((*it)->getGPS().distance(gps) < (*min)->getGPS().distance(gps))
			min = it;
	}

	return min;
}


set<praiaFluvial*, classcomp>::iterator GestorPraias::findPraia(string nome) {

	set<praiaFluvial*, classcomp>::iterator it = praias.begin();

	for (it = praias.begin(); it != praias.end(); it++)
	{
		if ((*it)->getNome() == nome)
			return it;
	}

	return praias.end();
}

set<praiaFluvial*, classcomp>::iterator GestorPraias::findPraia(GPS gps) {

	set<praiaFluvial*, classcomp>::iterator it = praias.begin();

	for (it = praias.begin(); it != praias.end(); it++)
	{
		if ((*it)->getGPS() == gps)
			return it;
	}

	return praias.end();
}

bool GestorPraias::isEnd(set<praiaFluvial*, classcomp>::iterator &it) {
	return (it == praias.end());
}


bool lesserConcelho(praiaFluvial praia1, praiaFluvial praia2) {
	return (praia1.getConcelho() < praia2.getConcelho());
}


/*void GestorPraias::servicosInfo(praiaFluvial praia)
{
	string nome;
	GPS gps;
	string cafes, restaurantes, nadador, campos;
	int c = 0, r = 0, ns = 0, cd = 0;

	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if (praia.getNome() == praias[i]->getNome() )
		{
			for (unsigned int u = 0; u < praias[i]->getServicos().size(); u++)
			{
				gps = praias[i]->getServicos().at(u).getGPS();

				if (praias[i]->getServicos().at(u).getTipo() == "restaurante")
				{
					r++;
				}
				else if (praias[i]->getServicos().at(u).getTipo() == "cafe")
				{
					c++;
				}
				else if (praias[i]->getServicos().at(u).getTipo() == "campoDesportivo")
				{
					cd++;
				}
				else if (praias[i]->getServicos().at(u).getTipo() == "nadador")
				{
					ns++;
				}
			}
		}
	}
	
	cout << "A praia possui " << c << " cafes, " << r << "restaurantes, " << cd << " campos desportivos e " << ns << " nadadores salvadores\n" ;

}*/




bool GestorPraias::LoadPraias(string filename) 
{
	ifstream file(filename);

	if (!file.is_open())
		return false;

	string tempPraia;

	vector<string> parser(14,"");

	vector<servico> tempServicos;

	while (getline(file, tempPraia, '\n'))
	{
		stringstream ss(tempPraia);

		getline(ss, parser[0], ',');
		utilities::trimString(parser[0]);

		if (parser[0] == "rio") //"rio",nome,concelho,latitude,longitude,bandeiraazul,capacidade,largura,caudal,profundidade,tipo1,nome1,latitude1,longitude1,...
		{
			getline(ss, parser[1], ',');
			getline(ss, parser[2], ',');
			getline(ss, parser[3], ',');
			getline(ss, parser[4], ',');
			getline(ss, parser[5], ',');
			getline(ss, parser[6], ',');
			getline(ss, parser[7], ',');
			getline(ss, parser[8], ',');
			getline(ss, parser[9], ',');

			for(int i = 1; i <= 9; i++)
				utilities::trimString(parser[i]);

			tempServicos.resize(0);
			while (getline(ss, parser[10], ',') && getline(ss, parser[11], ',') && getline(ss, parser[12], ',') && getline(ss, parser[13], ',')) //tipo1,nome1,latitude1,longitude1,tipo2,nome2,latitude2,longitude2,...
			{
				for(int i = 10; i <= 13; i++)
					utilities::trimString(parser[i]);

				if (parser[10] == "nadadorSalvador")
					tempServicos.push_back(nadadorSalvador(parser[11]));

				else if (parser[10] == "cafe")
					tempServicos.push_back(cafe(parser[11], GPS(stod(parser[12]), stod(parser[13]))));

				else if (parser[10] == "restaurante")
					tempServicos.push_back(restaurante(parser[11], GPS(stod(parser[12]), stod(parser[13]))));

				else if (parser[10] == "campoDesportivo")
					tempServicos.push_back(campoDesportivo(parser[11], GPS(stod(parser[12]), stod(parser[13]))));

				else
					throw BadFileInput(filename);
			}

			try
			{
				praias.insert(new rio(parser[1], parser[2], GPS(stod(parser[3]), stod(parser[4])), (bool)stoi(parser[5]), stoi(parser[6]),  tempServicos, stoi(parser[7]), stoi(parser[8]), stoi(parser[9])));
			}
			catch (exception& e)
			{
				throw BadFileInput(filename);
			}


		}

		else if (parser[0] == "albufeira") //"albufeira",nome,concelho,latitude,longitude,bandeiraazul,capacidade,area
		{
			getline(ss, parser[1], ',');
			getline(ss, parser[2], ',');
			getline(ss, parser[3], ',');
			getline(ss, parser[4], ',');
			getline(ss, parser[5], ',');
			getline(ss, parser[6], ',');
			getline(ss, parser[7], ',');

			for(int i = 1; i <= 7; i++)
				utilities::trimString(parser[i]);

			tempServicos.resize(0);
			while (getline(ss, parser[10], ',') && getline(ss, parser[11], ',') && getline(ss, parser[12], ',') && getline(ss, parser[13], ',')) //tipo1,nome1,latitude1,longitude1,tipo2,nome2,latitude2,longitude2,...
			{
				for(int i = 10; i <= 13; i++)
					utilities::trimString(parser[i]);

				if (parser[10] == "nadadorSalvador")
					tempServicos.push_back(nadadorSalvador(parser[11]));

				else if (parser[10] == "cafe")
					tempServicos.push_back(cafe(parser[11], GPS(stod(parser[12]), stod(parser[13]))));

				else if (parser[10] == "restaurante")
					tempServicos.push_back(restaurante(parser[11], GPS(stod(parser[12]), stod(parser[13]))));

				else if (parser[10] == "campoDesportivo")
					tempServicos.push_back(campoDesportivo(parser[11], GPS(stod(parser[12]), stod(parser[13]))));

				else
					throw BadFileInput(filename);
			}

			try
			{
				praias.insert(new albufeira(parser[1], parser[2], GPS(stod(parser[3]), stod(parser[4])), (bool)stoi(parser[5]), stoi(parser[6]),  tempServicos, stoi(parser[7])));
			}
			catch (exception& e)
			{
				throw BadFileInput(filename);
			}
		}

		else if (parser[0] == "servicosdefora") //"servicosdefora",tipo1,nome1,latitude1,longitude1,tipo2,nome2,latitude2,longitude2,...
		{
			while(getline(ss, parser[1], ',') && getline(ss, parser[2], ',') && getline(ss, parser[3], ',') && getline(ss, parser[4], ','))
			{
				for(int i = 1; i <= 4; i++)
					utilities::trimString(parser[i]);

				if (parser[1] == "pontoTuristico")
				{
					try
					{
						servicosdefora.push_back(new pontoTuristico(parser[2], GPS(stod(parser[3]),stod(parser[4]))));
					}
					catch (exception& e)
					{
						throw BadFileInput(filename);
					}
				}

				else if (parser[1] == "alojamento")
				{
					try
					{
						servicosdefora.push_back(new alojamento(parser[2], GPS(stod(parser[3]),stod(parser[4]))));
					}
					catch (exception& e)
					{
						throw BadFileInput(filename);
					}
				}

				else
					throw BadFileInput(filename);
			}
		}
		else
			throw BadFileInput(filename);

	}

	file.close();

	return true;
}


bool GestorPraias::SavePraias(string filename) {

	ofstream file(filename);

	if (!file.is_open())
		return false;

	for (set<praiaFluvial*, classcomp>::iterator it = praias.begin(); it != praias.end(); it++)
	{
		if (it != praias.begin())
			file << '\n';

		if ((*it)->getTipo() == "rio")
			file << (*it)->getTipo() << ',' << (*it)->getNome() << ',' << (*it)->getConcelho() << ',' << (*it)->getGPS().getLatitude() << ',' << (*it)->getGPS().getLongitude() << ',' << (*it)->getBandeiraAzul() << ',' << (*it)->getCapacidade() << ',' << (*it)->getLargura() << ',' << (*it)->getCaudal() << ',' << (*it)->getProfundidade();
		else
			file << (*it)->getTipo() << ',' << (*it)->getNome() << ',' << (*it)->getConcelho() << ',' << (*it)->getGPS().getLatitude() << ',' << (*it)->getGPS().getLongitude() << ',' << (*it)->getBandeiraAzul() << ',' << (*it)->getCapacidade() << ',' << (*it)->getArea();

		for (int j = 0; j < (*it)->getServicos().size(); ++j)
		{
			file << ',' << (*it)->getServicos()[j].getTipo() << ',' << (*it)->getServicos()[j].getNome() << ',' << (*it)->getServicos()[j].getGPS().getLatitude() << ',' << (*it)->getServicos()[j].getGPS().getLongitude();
		}
	}

	for (int i = 0; i < servicosdefora.size(); ++i)
	{
		if (i == 0)
			file << '\n' << "servicosdefora";

		file << ',' << servicosdefora[i]->getTipo() << ',' << servicosdefora[i]->getNome() << ',' << servicosdefora[i]->getGPS().getLatitude() << ',' << servicosdefora[i]->getGPS().getLongitude();
	}

	file.close();

	return true;
}


//2
tabHS GestorPraias::getServicosNaoAtivos() const
{
	return servicosNaoAtivos;
}
