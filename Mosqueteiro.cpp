#include "Mosqueteiro.h"



Mosqueteiro::Mosqueteiro()
{
}


Mosqueteiro::~Mosqueteiro()
{
}


void Mosqueteiro::builderMosqueteiro(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	arma = pArma;
}


void Mosqueteiro::mover()
{
}


void Mosqueteiro::atacar()
{
}


void Mosqueteiro::atualizar()
{
	posX += velX;
	posY -= velY;
	atualizaArma();
}


void Mosqueteiro::draw()
{
	al_draw_filled_rectangle(posX, posY, posX + limX, posY - limY, al_map_rgb(255, 0, 0));
}



