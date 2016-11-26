#pragma once

#include "inimigo.h"
#include <time.h>


//---------------- Inicializando o inimigo -------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::iniciar(int x, int y){
	m_posicao.set(x, y);
	m_spriteTamX = 110.f;
	m_raioColisao = (m_spriteTamX * 0.6f) / 2.f;
	m_spriteTamY = 110.f;
	m_frame = 1;
	m_totalFrames = 6;
	m_frameTime = 0;
	m_seguirJogador = false;
	m_morto = false;
	m_vida = 10;
	m_stunTime = 0;
	m_timeAtack = (10 + rand() % 20) * 0.1f;

}



//---------------- Movimentacao do inimigo -------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::mover(ofVec2f posJogador, ofVec2f mund, float tam) {
	m_stunTime = m_stunTime >= 0 ? m_stunTime - ofGetLastFrameTime() : 0;
	if (seguir(posJogador, mund) && (m_stunTime <= 0)) {

		m_velocidade = (posJogador - mund) - m_posicao;

		float tmp = m_velocidade.length();

		m_velocidade.normalize();

		if (tmp >= (tam + m_raioColisao*2.f) * 0.52f)
			m_posicao += (VELOCIDADE * ofGetLastFrameTime()) * m_velocidade;
		
	}
	direcao(posJogador, mund);
}

//---------------- Levar Dano --------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::levardano(ofVec2f player, ofVec2f mund,float tamArea, KeyInput teclas, bool levadano, Som tmp_som) {
	m_dano = 0;
	if (levadano && (player.distance(m_posicao + mund) <= (tamArea + m_raioColisao*2.f) / 2.f)) {
		m_dano = (teclas.keyUp && (player.y  > m_posicao.y + mund.y)) ? 4 :
		(teclas.keyDown && (player.y  < m_posicao.y + mund.y)) ? 4 :
		(teclas.keyLeft && (player.x  > m_posicao.x + mund.x)) ? 4 :
		(teclas.keyRight && (player.x  < m_posicao.x + mund.x)) ? 4 : m_dano;
		tmp_som.InimigoLevaDano();
		m_stunTime = STUN_TIME;
	}
	
	m_vida = m_dano != 0 ? (m_vida - ((10 + rand() % 50) * 0.1f)): m_vida;
	m_morto = m_vida <= 0 ? true : false;
}


//---------------- Atacar ------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
float Inimigo::Atacar(ofVec2f jogador, float radius, ofVec2f mundo){
	bool tmp_1, tmp_2;
	tmp_1 = (m_timeAtack < 1);
	tmp_2 = (jogador.distance(m_posicao + mundo) <= 30 + radius + m_raioColisao);
	if (m_timeAtack == 0)
		m_timeAtack = (10 + rand() % 30) * 0.1f;

	else {
		m_timeAtack -= ofGetLastFrameTime();
		if (tmp_1 && tmp_2) {
			m_timeAtack = 0;
			return (10 + rand() % 50) * 0.1f;
		}
	}

	return -1;
}


//---------------- Animacao do inimigo------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::animar() {
	//Trocando os frames do player para animar
	m_frameTime += ofGetLastFrameTime(); //Fazendo contagem de tempo

	

	//Trocando o indice de posição do frame do player
	if (m_frameTime >= VELOCIDADE_ANIMACAO) {
		m_frame = (m_frame + 1) % m_totalFrames;
		m_frameTime = 0;
	}

}


//---------------- Direcao do inimigo ------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::direcao(ofVec2f player, ofVec2f mund) {

	//Encontrando o angulo de direcao do inimigo
	float tmp_dirc = getAngulo(m_velocidade);

	//Mudando a direcao de acordo com o agulo de direcao
	m_direcao = ((tmp_dirc > -45) && (tmp_dirc < 45)) ? 0 : m_direcao;
	m_direcao = ((tmp_dirc > 45) && (tmp_dirc < 135)) ? 1 : m_direcao;
	m_direcao = ((tmp_dirc > 135) || (tmp_dirc < -135)) ? 2 : m_direcao;
	m_direcao = ((tmp_dirc > -135) && (tmp_dirc < -45)) ? 3 : m_direcao;
	
}


//---------------- Desenhar o inimigo-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::desenhar(ofVec2f mund, ofImage sprite) {
	//sprite.setAnchorPoint(76.f / 2.f, 76.f / 2.f);
	int tmp = m_stunTime > 0 ? 4 : 0;
	sprite.drawSubsection(m_posicao.x + mund.x - 55.f, m_posicao.y + mund.y - 55.f, m_spriteTamX, m_spriteTamY, m_spriteTamX * m_frame, m_spriteTamY * (m_direcao + tmp));

}




bool Inimigo::seguir(ofVec2f player, ofVec2f mund) {
	ofVec2f tmp = m_posicao + mund;
	return tmp.distance(player + mund) <= CAMPO_VISAO;
}


void Inimigo::colidiuCom(Inimigo inim, ofVec2f mund) {
		if (!inim.m_morto) {
			float tmp_dist = inim.m_posicao.distance(m_posicao);
			if (tmp_dist <= (inim.m_raioColisao + m_raioColisao) / 2.f) {
				ofVec2f tmp;
				tmp = (inim.m_posicao - m_posicao) *0.52f;
				m_posicao -= (VELOCIDADE * ofGetLastFrameTime()) * tmp.normalized();
			}
		}
}

float Inimigo::getAngulo(ofVec2f pos) {

	ofVec2f tpm_prox_posicao;
	tpm_prox_posicao = m_posicao + pos; //Posicao atual mais a velocidade igual a proxima posicao
	return atan2f(m_posicao.y - tpm_prox_posicao.y, m_posicao.x - tpm_prox_posicao.x) * 180 / 3.14;
}

Inimigo::~Inimigo() {
}