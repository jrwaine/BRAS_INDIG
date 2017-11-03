#pragma once
#include "Entidade.h"
class ArmaDeAlcance;

class Projetil :
	public Entidade
{
private:
	ArmaDeAlcance* armaProjetil;
public:
	Projetil();
	~Projetil();
	void builderProjetil(const int ax, const int ay, const int aLimX, const int aLimY, const int aVelx, const int aVelY, const bool aAtivo);
	void atualizar();
	void setArmaProj(ArmaDeAlcance* const pArma);
	ArmaDeAlcance* const getArmaProj();
	void draw();
};

