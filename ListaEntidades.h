#pragma once
#include "Jogador.h"
#include "Mosqueteiro.h"
#include "Espada.h"
#include "Corda.h"
#include <vector>
using namespace std;

/*	mudar implementa��o para um template mais espec�fico	*/
class ListaEntidades
{
private:
	vector<Entidade*> entidades;
public:
	ListaEntidades();
	~ListaEntidades();
	void addEntidade(Entidade* pEntidade);
	void desenhaAtivos();
};

