#pragma once

#include "inimigo.h"
#include <time.h>


//---------------- Inicializando o inimigo -------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::iniciar(int x, int y){
	srand(time(NULL));

	m_sprite.load("inimigo/inimigo.png");
	m_posicao.set(x + (rand() % MAX_AREA) - MAX_AREA / 2.f, y + (rand() % MAX_AREA) - MAX_AREA / 2.f);
	m_spriteTamX = 76;
	m_spriteTamY = 76;
	m_sprite.setAnchorPoint(m_spriteTamX / 2, m_spriteTamY / 2);
	m_frame = 0;
	m_totalFrames = 8;
	m_seguirJogador = false;
	m_vida = 10;

}



//---------------- Movimentacao do inimigo -------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::mover(ofVec2f posJogador, ofVec2f mund, float tam) {
	if (seguir(posJogador, mund)) {

		m_velocidade = (posJogador - mund) - m_posicao;

		float tmp = m_velocidade.length();

		m_velocidade.normalize();

		if (tmp >= (tam + m_spriteTamX) * 0.52f) 
			m_posicao += (VELOCIDADE * ofGetLastFrameTime()) * m_velocidade;
	}
	direcao(posJogador, mund);
}

//---------------- Levar Dano --------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::levardano(){


}


//---------------- Atacar ------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::atacar(){


}


//---------------- Animacao do inimigo------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::animar(float game_time) {
	//Trocando os frames do player para animar
	m_frameTime += game_time; //Fazendo contagem de tempo

	

	//Trocando o indice de posição do frame do player
	if (m_frameTime >= VELOCIDADE_ANIMACAO) {
		m_frame = (m_frame + 1) % m_totalFrames;
		m_frameTime = 0;
	}

}


//---------------- Direcao do inimigo ------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::direcao(ofVec2f player, ofVec2f mund) {

	ofVec2f tpm_prox_posicao;
	tpm_prox_posicao = m_posicao + m_velocidade; //Posicao atual mais a velocidade igual a proxima posicao

	//Encontrando o angulo de direcao do inimigo
	float tmp_dirc = atan2f(m_posicao.y - tpm_prox_posicao.y, m_posicao.x - tpm_prox_posicao.x) * 180 / 3.14;

	//Mudando a direcao de acordo com o agulo de direcao
	m_direcao = ((tmp_dirc > -45) && (tmp_dirc < 45)) ? 0 : m_direcao;
	m_direcao = ((tmp_dirc > 45) && (tmp_dirc < 135)) ? 1 : m_direcao;
	m_direcao = ((tmp_dirc > 135) || (tmp_dirc < -135)) ? 2 : m_direcao;
	m_direcao = ((tmp_dirc > -135) && (tmp_dirc < -45)) ? 3 : m_direcao;
	
}


//---------------- Desenhar o inimigo-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::desenhar(ofVec2f mund) {

	m_sprite.drawSubsection(m_posicao.x + mund.x, m_posicao.y + mund.y, m_spriteTamX, m_spriteTamY, m_spriteTamX * m_frame, m_spriteTamY * m_direcao);

}




bool Inimigo::seguir(ofVec2f player, ofVec2f mund) {
	return m_posicao.distance(player + mund) <= CAMPO_VISAO;
}


void Inimigo::colidiuCom(Inimigo inim[2], ofVec2f mund, int id) {
	for (int i = 0; i < 2; i++) {
		if (i != id) {
			float tmp_dist = inim[i].m_posicao.distance(m_posicao);
			if (tmp_dist <= (inim[i].m_spriteTamX + m_spriteTamX) / 2.f) {
				ofVec2f tmp;
				tmp = (inim[i].m_posicao - m_posicao) / 2.f;
				m_posicao -= (VELOCIDADE * ofGetLastFrameTime()) * tmp.normalized();
			}
		}
	}
}