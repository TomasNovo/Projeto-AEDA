#ifndef SERVICOS_H
#define SERVICOS_H

#include <string>
#include "GPS.h"

/**
 * @brief      Class for servico.
 */
class servico
{	
	std::string nome;
	GPS gps;
	std::string tipo;
public:
	servico();
	servico(std::string nome, GPS gps);
	~servico();
	GPS getGPS() const;
	std::string getTipo() const;
	std::string getNome() const;
	void setTipo(std::string tipo);
};


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
public:
	servicoForaDaPraia();
	servicoForaDaPraia(std::string nome, GPS gps);
	~servicoForaDaPraia();
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



#endif