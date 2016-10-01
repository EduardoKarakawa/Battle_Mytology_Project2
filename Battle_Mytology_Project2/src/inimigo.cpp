#pragma once

#include "inimigo.h"
#include <time.h>

void Inimigo::iniciar(int x, int y){
	srand(time(NULL));

	m_sprite.load("inimigo/inimigo.png");
	m_posicao.set(x + (rand() % MAX_AREA) - MAX_AREA / 2.f, y + (rand() % MAX_AREA) - MAX_AREA / 2.f);
	m_spriteTamX = 76;
	m_spriteTamY = 76;
	m_sprite.setAnchorPoint(m_spriteTamX / 2, m_spriteTamY / 2);
	m_frame = 0;
	m_totalFrames = 8;

}


void Inimigo::mover(ofVec2f posJogador, ofVec2f mund, float tam){
	m_velocidade = (posJogador - mund) - m_posicao;

	direcao(posJogador, mund);

	if (m_velocidade.length() >= (tam + m_spriteTamX) * 0.52f){
		m_velocidade.normalize();
		m_posicao += (VELOCIDADE * ofGetLastFrameTime()) * m_velocidade;
	}
}


void Inimigo::levardano(){


}


void Inimigo::atacar(){


}


//---------------- Animacao do jogador------------------------------------------------------------
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

void Inimigo::direcao(ofVec2f player, ofVec2f mund) {

	float tmp_dirc = m_posicao.angle(m_velocidade);

	std::cout << tmp_dirc << std::endl;
	m_direcao = ((tmp_dirc > 135) && (tmp_dirc < -135)) ? 0 : m_direcao;
	m_direcao = ((tmp_dirc < 135) && (tmp_dirc > 45)) ? 1 : m_direcao;
	m_direcao = ((tmp_dirc < 45) && (tmp_dirc > -45)) ? 2 : m_direcao;
	m_direcao = ((tmp_dirc > -45) && (tmp_dirc < -135)) ? 3 : m_direcao;


	/*if (m_velocidade.x < 0) {
		return 0;
	}
	if (m_velocidade.x > 0) {
		return 2;
	}
	if (m_velocidade.y > 0) {
		return 3;
	}
	if (m_velocidade.y < 0) {
		return 1;
	}*/
}


//---------------- Desenhar o jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::desenhar(ofVec2f mund) {

	m_sprite.drawSubsection(m_posicao.x + mund.x, m_posicao.y + mund.y, m_spriteTamX, m_spriteTamY, m_spriteTamX * m_frame, m_spriteTamY * m_direcao);

}


