#include "Jogador.h"

int Jogador::num_jogs = 0;

Jogador::Jogador()
{
	//MUDAR PARA SINGLETON O ESQUEMA DE CONSTRUTOR
	posX = 0;
	posY = 0;
	limX = LIM_X_JOG;
	limY = LIM_Y_JOG;
	velX = 0;
	velY = 0;
	fisica = true;
	ativo = false;
	velMaxX = VEL_MAX_X_JOG;
	velMaxY = VEL_PULO;
	ID = -1;

	vida = VIDA_MAX_JOG;
	arma = NULL;
	dir = true;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
	timer_ataque = NULL;
	timer_atacando = NULL;
	timer_invuneravel = NULL;
	
	num_jogs++;
	chances = 3; //	3 chances � o padr�o inicial
	subindo = false;
	subiu = false;
	imovel = false;
	timer_imovel = NULL;
}


Jogador::~Jogador()
{
	delete (arma);
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);
	
	al_destroy_timer(timer_imovel);
	num_jogs--;
}


void Jogador::builderJogador(const int ax, const int ay, const bool aAtivo, const int aID, const int aChances)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;
	if(aID != -1)
		ID = aID;

	vida = VIDA_MAX_JOG;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
	if (arma == NULL)
	{
		Arma* pArma = constroiArma();
		if (pArma != NULL)
			arma = pArma;
	}

	if(aChances != -1)
		chances = aChances;
	subindo = false;
	subiu = false;
	imovel = false;
}


void Jogador::atacar()
{
	if (arma->getID() == ESPADA)
	{
		atacando = true;
		al_resume_timer(timer_atacando);
		al_resume_timer(timer_ataque);
		al_set_timer_count(timer_atacando, 0);
		al_set_timer_count(timer_ataque, 0);
	}
}


void Jogador::moverDir()
{
	if (!imovel) 
	{
		if (velX < velMaxX)
			velX += (float)ACEL_X_PERS;
		if (velX > velMaxX)
			velX = velMaxX;
		if(!atacando)
			dir = true;
	}
}


void Jogador::moverEsq()
{
	if (!imovel) 
	{
		if (velX > -velMaxX)
			velX -= (float)ACEL_X_PERS;
		if (velX < -velMaxX)
			velX = -velMaxX;
		if(!atacando)
			dir = false;
	}
}


void Jogador::pular()
{
	if(!imovel)
		velY = VEL_PULO;
}


// para cordas
void Jogador::subir()
{
	if (!imovel)
	{
		velY = VEL_SUBIDA;
		subiu = true;
	}
}


void Jogador::atualizar()
{
	posY -= velY;
	posX += velX;
	
	if (subiu)
		subindo = true;
	else
		subindo = false;
	subiu = false;
	atualizaAtaque();
	atualizaInvuneravel();
	atualizaAtacando();
	atualizaParado();	
	atualizaArma();
}


void Jogador::draw(const int aPosFaseX, const int aPosFaseY)
{
	if(!invuneravel)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 255,0));
	else
		al_draw_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 255, 0), 2);
	if (atacando)
		al_draw_filled_rectangle(arma->getX() - aPosFaseX, arma->getY() - aPosFaseY, arma->getX() + arma->getLimX() 
			- aPosFaseX, arma->getY() - arma->getLimY() - aPosFaseY, al_map_rgb(255, 150, 0));
}


const int Jogador::getChances()
{
	return chances;
}


void Jogador::setChances(const int aChances)
{
	chances = aChances;
}


void Jogador::createTimers()
{
	timer_ataque = al_create_timer(PER_ATAQ_JOG);
	timer_invuneravel = al_create_timer(TEMP_INVUN_JOG);
	timer_atacando = al_create_timer(TEMP_ATAQ_JOG);
	timer_imovel = al_create_timer(TEMP_IMOVEL);
}


const bool Jogador::getSubindo()
{
	return subindo;
}


void Jogador::setSubindo(const bool aSubindo)
{
	subindo = aSubindo;
}


void Jogador::descer()
{
	if (!imovel)
	{  
		velY = -VEL_SUBIDA;
	}
}


//	para KB = 1, o jogador recebe um knock back para direita
//	para KB = -1, o jogador recebe um knock back para esquerda
//	para KB = 0, o jogador n�o recebe knock back
//	para KB = 2, o jogador fica parado por um tempo
//	para KB = 3, o jogador toma o efeito de quando � capturado por uma rede
void Jogador::tomaDano(const int aDano, const int KB)
{
	if (!invuneravel && aDano > 0)
	{
		vida -= aDano;
		if (vida >= 0)
		{
			invuneravel = true;
			if (KB == 1)
			{
				velX = VEL_X_KB;
				velY = VEL_Y_KB;
			}
			else if (KB == -1)
			{
				velX = -VEL_X_KB;
				velY = VEL_Y_KB;
			}
			else if (KB == 2)
			{
				if (velY > 0)
					velY = 0;
				velX = 0;
				imovel = true;
				al_set_timer_count(timer_imovel, 0);
				al_resume_timer(timer_imovel);
			}
			else if (KB == 3)
			{
				if (velY > 0)
					velY = 0;
				velX = 0;
				imovel = true;
				al_set_timer_count(timer_imovel, -2);
				al_resume_timer(timer_imovel);
			}

			//reseta o contador do timer
			al_set_timer_count(timer_invuneravel, 0);
			al_resume_timer(timer_invuneravel);
		}
	}
}


const bool Jogador::persPodeAtacar()
{
	if (arma->getID() == ESPADA)
	{
		if (al_get_timer_count(timer_ataque) >= 1 && !atacando && !imovel)
			return true;
	}
	else if (arma->getID() == ARCO)
	{
		if (al_get_timer_count(timer_ataque) >= 1 && !atacando && !imovel)
			return true;
	}
	return false;
}


void Jogador::atualizaParado()
{
	if (imovel)
	{
		if (al_get_timer_count(timer_imovel) >= 1)
		{
			al_stop_timer(timer_imovel);
			imovel = false;
		}
	}
}


void Jogador::destruirTimer()
{
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);
	al_destroy_timer(timer_imovel);
}


void Jogador::initTimer()
{
	al_start_timer(timer_ataque);
	
	al_start_timer(timer_imovel);
	al_stop_timer(timer_imovel);
	//	o timer s� ser� resumido quando a fun��o "atacar" for acionada 
	//	e tem valor inicial 1 para permitir o primeiro ataque

	al_start_timer(timer_atacando);
	al_stop_timer(timer_atacando);
	//	o timer s� ser� resumido quando a fun��o "atacar" for acionada

	al_start_timer(timer_invuneravel);
	al_stop_timer(timer_invuneravel);
	al_set_timer_count(timer_invuneravel, 0);
	//	o timer s� ser� resumido quando a fun��o "tomaDano" for acionada
}


Projetil* const Jogador::atirar()
{
	if (arma->getID() == ARCO)
	{
		Projetil* pProj = new Projetil();
		pProj->setID(PROJETIL_JOG);
		if(dir)
			pProj->builderProjetil(arma->getX(), arma->getY(), VEL_MAX_PROJ, true, PROJETIL_JOG, arma);
		else	
			pProj->builderProjetil(arma->getX(), arma->getY(), -VEL_MAX_PROJ, true, PROJETIL_JOG, arma);

		pProj->setArmaProj(arma);
		atacando = true;
		al_resume_timer(timer_atacando);
		al_resume_timer(timer_ataque);
		al_set_timer_count(timer_atacando, 0);
		al_set_timer_count(timer_ataque, -1);	//jogador demora o dobro de tempo para atacar com o arco
		return pProj;
	}
	return NULL;
}


void Jogador::reset(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_JOG;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;

	subindo = false;
	subiu = false;
	imovel = false;
}


void Jogador::resetChances()
{
	chances = 3;
}
