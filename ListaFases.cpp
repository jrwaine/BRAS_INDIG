#include "ListaFases.h"



ListaFases::ListaFases()
{
}


ListaFases::~ListaFases()
{
}


void ListaFases::carregaFaseN(const int aN)
{
	//	carrega a fase predeterminada
	switch (aN)
	{
	case 1:
		fase1.setCampanha(false);
		fase1.initFase();
		break;
	case 2:
		fase2.setCampanha(false);
		fase2.initFase();
		break;
	case 3:
		faseFinal.setCampanha(false);
		faseFinal.initFase();
		break;
	default:
		break;
	}
}


bool ListaFases::defineNumJogadores(const int aNumJogs)
{
	if (aNumJogs == 2 || aNumJogs == 1)
	{
		fase1.setNumJogs(aNumJogs);
		return true;
	}
	else
		return false;
}

void ListaFases::campanha()
{
	fase1.setCampanha(true);
	// cutscene e tals

	fase1.initFase();
	//	condi��o para ter passado de fase...
	//	se passou, mostra pontos, cutscene ou coisa assim e ent�o inicia outra fase
	
	fase2.initFase();
	//	condi��o para ter passado de fase...
	//	se passou, mostra pontos, cutscene ou coisa assim e ent�o inicia outra fase

	faseFinal.initFase();
	//	condi��o para ter passado de fase...
	//	se passou, mostra pontos, cutscene ou coisa assim e ent�o inicia outra fase


	// cr�ditos
}

//	MUDAR O STRING PARA ALGUM ID OU COISA ASSIM
void ListaFases::defineJog(string const aNome, const int aNum)
{
	if (fase1.getNumJogs() == 1)
	{
		if (aNum == 1)
		{
			if (aNome == "TECA")
			{
				//	DEFINE O JOGADOR 1 UM COMO SENDO A TE�A
			}
			else if (aNome == "RAONI")
			{
				//	DEFINE O JOGADOR 1 UM COMO SENDO O RAONI
			}
		}
	}
	else if (fase1.getNumJogs() == 2)
	{
		if (aNum == 1)
		{
			if (aNome == "TECA")
			{
				//	DEFINE O JOGADOR 1 UM COMO SENDO A TE�A
			}
			else if (aNome == "RAONI")
			{
				//	DEFINE O JOGADOR 1 UM COMO SENDO O RAONI
			}
		}
		else if (aNum == 2)
		{
			if (aNome == "TECA")
			{
				//	DEFINE O JOGADOR 2 UM COMO SENDO A TE�A
			}
			else if (aNome == "RAONI")
			{
				//	DEFINE O JOGADOR 2 UM COMO SENDO O RAONI
			}
		}
	}
}
