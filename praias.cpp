#include "praias.h"

using namespace std;


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
praiaFluvial::praiaFluvial(string concelho, GPS gps, bool bandeirazul, unsigned int capacidade, vector<servico> servicosdapraia) : concelho(concelho), gps(gps), bandeiraazul(bandeiraazul), capacidade(capacidade), servicosdapraia(servicosdapraia)
{}


/**
 * @brief      Gets the praia's name.
 *
 * @return     The praia's name.
 */
string praiaFluvial::getNome()
{
	return this->nome;
}

/**
 * @brief      Gets the gps.
 *
 * @return     The gps.
 */
GPS praiaFluvial::getGPS()
{
	return this->gps;
}
/**
 * @brief      Gets the praia's concelho.
 *
 * @return     The praia's concelho.
 */
string praiaFluvial::getConcelho()
{
	return this->concelho;
}
/**
 * @brief      Gets the praia's bandeira azul.
 *
 * @return     The praia's bandeira azul.
 */
bool praiaFluvial::getBandeiraAzul()
{
	return bandeiraazul;
}
/**
 * @brief      Gets the praia's capacidade.
 *
 * @return     The praia's capacidade.
 */
unsigned int praiaFluvial::getCapacidade()
{
	return capacidade;
}


/**
 * @brief      { function_description }
 *
 * @param[in]  praia  The praia
 */

GestorPraias::GestorPraias()
{}

string praiaFluvial::getInfo() const
{
	string info;

	info += "Nome da Praia: " + nome + " \n ";
	info += "Concelho onde a praia se situa: " + concelho + " \n ";
	info += "Capacidade da praia: " + to_string(capacidade) + "\n ";
	if (bandeiraazul == true)
	{
		info += "Bandeira azul: A praia possui bandeira azul \n";
	}
	else
	{
		info += "Bandeira azul: A praia nao possui bandeira azul \n";
	}

	return info;
}

string rio::getInfo() const
{
	string info_rio;
	info_rio = praiaFluvial::getInfo();
	info_rio += " A praia � uma praia fluvial de rio \n ";
	info_rio += "Largura M�xima da praia: " + to_string(larguraMax);
	info_rio += "Caudal M�ximo da praia: " + to_string(caudalMax);
    info_rio += "Profundidade M�ximo da praia: " + to_string(profundidadeMax);

	return info_rio;
}

string albufeira::getInfo() const
{
	string info_albufeira;

	info_albufeira = praiaFluvial::getInfo();
	info_albufeira += "A praia � uma praia fluvial de albufeira \n";
	info_albufeira += "�rea da albufeira: " + to_string(area)  + "\n";
	
	return info_albufeira;
}


int GestorPraias::praiaInfo(string praia)
{

	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if (praia == praias[i]->getNome())
		{
			cout << praias[i]->getInfo();
			break;
			return 0;
		}

	}
	
	return 1;


}

/*
int GestorPraias::praiaInfoGPS(GPS(double x, double y) )
{
	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if ( GPS(x,y) == praias[i]->getGPS())
		{

		}


	}



}
*/
