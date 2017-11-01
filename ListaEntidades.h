#pragma once
#include "EntConcreteClasses.h"
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

	// retorna entidade na posi��o i
	Entidade* const entidadeI(const int i);
	// retorna o numero de entidades
	const int numEntidades();
};

