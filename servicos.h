#ifndef SERVICOS_H
#define SERVICOS_H

#include <string>
#include "GPS.h"
#include "data.h"
#include <iostream>

/**
 * @brief      Class for servico.
 */
class servico
{	
	std::string nome;
	GPS gps;
	std::string tipo;
	bool aberto = true;
	data dt = data(0,0,0);
public:
	servico();
	servico(std::string nome, GPS gps);
	~servico();

	GPS getGPS() const;
	std::string getTipo() const;
	std::string getNome() const;
	bool getAberto() const;
	data getData() const;
	std::string getInfo() const;
	
	void setTipo(std::string tipo);
	void setAberto(bool aberto);
	void setData(data dt);

	void makeInspection(data dt);

};

bool operator<(const servico& srvc1, const servico& srvc2);
std::ostream& operator<<(std::ostream& os, const servico& srvc);

/**
 * @brief      Class for nadador salvador. Derivates from servico.
 */
class nadadorSalvador : public servico
{
public:
	nadadorSalvador();
	nadadorSalvador(std::string nome);
	~nadadorSalvador();

};

/**
 * @brief      Class for cafe. Derivates from servico.
 */
class cafe : public servico
{
public:
	cafe();
	cafe(std::string nome, GPS gps);
	~cafe();
	
};

/**
 * @brief      Class for restaurante. Derivates from servico.
 */
class restaurante : public servico
{
public:
	restaurante();
	restaurante(std::string nome, GPS gps);
	~restaurante();
	
};

/**
 * @brief      Class for campo. Derivates from servico.
 */
class campoDesportivo : public servico
{
public:
	campoDesportivo();
	campoDesportivo(std::string nome, GPS gps);
	~campoDesportivo();

};



class servicoForaDaPraia : public servico
{
	bool permanente;
public:
	servicoForaDaPraia();
	servicoForaDaPraia(std::string nome, GPS gps);
	~servicoForaDaPraia();

	void close(bool permanente, data dt);
	void open(data dt);
};


class pontoTuristico: public servicoForaDaPraia
{
public:
	pontoTuristico();
	pontoTuristico(std::string nome, GPS gps);
	~pontoTuristico();
};

class alojamento : public servicoForaDaPraia
{
public:
	alojamento();
	alojamento(std::string nome, GPS gps);
	~alojamento();
};


// 2

class ServicoPtr {
	servico* servicoPtr;
public:
	ServicoPtr(servico* s) { servicoPtr = s; }
	std::string getName() const { return servicoPtr->getNome(); } // gps tipo aberto
	GPS getGPS() const { return servicoPtr->getGPS(); }
	std::string getType() const { return servicoPtr->getTipo(); }
	bool getAberto() const { return servicoPtr->getAberto(); }
	//void setName(string n) { servicoPtr->nome = n; }
	// falta funcao que altera a data
};



#endif