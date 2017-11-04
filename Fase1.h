#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	Espadachim inimigo1;
	EspadachimCavaleiro cav1;
	Plataforma chao;
	Plataforma plat1;
	Espada armaInimigo;
	Mosqueteiro inimigoMosq1;
	Mosquete armaMosq1;
	Lanca lanc1;

	

public:
	Fase1();
	~Fase1();

	void initFase();
	void execFase();
	void initObjs();
	void initAllegroObjs();
	void initInimigos();
	void initPlataformas();
	void restart();
};

