#pragma once

#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#define VEL_PULO 7
#define VEL_MAX_X_PERS 3
#define VEL_MAX_X_JOG 5
#define VEL_MAX_X_CAV 7

using namespace std;

enum IDS{JOGADOR1, JOGADOR2, MOSQUETEIRO, ESPADACHIM, ESP_CAVALEIRO, CHEFAO_CAP, 
	ESPADA, LANCA, MOSQUETE, ARCO, PROJETIL, PLATAFORMA, CORDA, ARMADILHA, ESPINHO, 
	REDE, CORDA_REDE};

class Entidade
{
protected:
	//	float foi optado na posi��o para ser poss�vel adicionar
	//	fra��es com rela��o a movimenta��o, tanto em X quanto em Y
	//					---------------
	//	A posi��o x e y correspondem a posi��o do canto esquerdo
	//	inferior do objeto. A posi��o x+limX e y+limY correspondem
	//	ao canto direito superior do objeto
	//					---------------
	//	Arrumar as fun��es que n�o s�o realmente pertencentes a classe
	//	entidade, mas sim aos personagens, depois que arrumar a quest�o
	//	da lista e do tipo que ela suporta

	float posX;
	float posY;
	int limX;
	int limY;
	float velX;
	float velY;
	string nome;
	bool fisica;
	bool ativo;
	float velMaxX;
	float velMaxY;
private:
	int ID;
	//sprite
public:
	Entidade();
	virtual ~Entidade();
	void setX(const float px);
	const float getX();
	void setY(const float py);
	const float getY();
	void setLimX(const int aLimX);
	const int getLimX();
	void setLimY(const int aLimY);
	const int getLimY();
	void setAtivo(const bool aAtivo);
	const bool getAtivo();
	void setFisica(const bool aFisica);
	const bool getFisica();
	const float getVelMaxX();
	void setVelMaxX(const float aVelMaxX);
	const float getVelMaxY();
	void setVelMaxY(const float aVelMaxY);

	const int getID();
	virtual void draw() = 0;
	void setVelX(const float aVelX);
	const int getVelX();
	void setVelY(const float aVelY);
	const int getVelY();
	virtual void atualizar() = 0;
};

