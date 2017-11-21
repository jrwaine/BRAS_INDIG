#pragma once
#include "Plataforma.h"
class Corda :
	public Plataforma
{
private:
	bool escalavel;
public:
	Corda();
	~Corda();
	void setEscalavel(const bool aEscalav);
	const bool getEscalavel();
	void draw(const int aPosFaseX, const int aPosFaseY);
	void builderCorda(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aEscalavel);
	void atualizar();
};

