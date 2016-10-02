#pragma once

#include "jogador.h"

ofApp ofappname;

void Jogador::iniciar() {
	//Funcao para iniciar os parametros do Jogador 
	strcpy(m_action, "iddle");
	m_sprite.loadImage("jogador/iddle.png");
	m_spriteTamX = 76;
	m_spriteTamY = 76;
	m_posicao.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	m_sprite.setAnchorPoint(m_spriteTamX / 2, m_spriteTamY / 2);
	m_frame = 0;
	m_totalFrames = 8;
	m_direcao = 1;
}


//---------------- Acoes do jogador---------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::acoes(ofApp::KeyInput teclas) {
	//Definindo a direcao pela tecla que estiver precionada, se nao tiver nenhuma 
	//sera definido a ultima tecla precionada
	m_direcao = teclas.keyA ? 0 : m_direcao;
	m_direcao = teclas.keyW ? 1 : m_direcao;
	m_direcao = teclas.keyD ? 2 : m_direcao;
	m_direcao = teclas.keyS ? 3 : m_direcao;

	//Verificando se esta parado
	if (!teclas.keyA && !teclas.keyD && !teclas.keyW && !teclas.keyS)
		m_sprite.loadImage("jogador/iddle.png");

	//Verificando se esta andando
	else if (teclas.keyA || teclas.keyD || teclas.keyW || teclas.keyS){
		m_sprite.loadImage("jogador/andando.png");
	}
		

}


//---------------- Animacao do jogador------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::animacao(float game_time) {
	//Trocando os frames do player para animar
	m_frameTime += game_time; //Fazendo contagem de tempo
								
	//Trocando o indice de posição do frame do player
	if (m_frameTime >= VELOCIDADE_ANIMACAO) {
		m_frame = (m_frame + 1) % m_totalFrames;
		m_frameTime = 0;
	}
}


//---------------- Desenhar o jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::desenhar(ofVec2f mund) {

	m_sprite.drawSubsection(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, m_spriteTamX, m_spriteTamY, m_spriteTamX * m_frame, m_spriteTamY * m_direcao);

}


//---------------- Colisao do jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::colidiuCom(ofVec2f objeto, ofVec2f& mnd, ofVec2f& vel, float raioObj){
	//Verifica se o jogador colidiu com um determinado objeto e realiza uma subtracao de 
	//vetor de posicao do (objeto + mundo) - player para fazer aumentar a velocidade 
	//contraria da movimentacao do mundo

	if (m_posicao.distance((objeto + mnd)) <= raioObj + m_spriteTamX / 2) {
		vel = -((mnd + objeto) - m_posicao); //Divide por 4 para diminuir a tremedeira
	}
}

int Jogador::getAngulo(ofVec2f pos, ofVec2f mund) {
	if ((pos.x < m_posicao.x + mund.x))
		return 0;
	if (pos.y < m_posicao.y + mund.y)
		return 1;
	if ((pos.x > m_posicao.x + mund.x))
		return 2;
	if ((pos.y > m_posicao.y + mund.y))
		return 3;
	//return atan2f(tmp_prox_posicao.y - m_posicao.y, tmp_prox_posicao.x - m_posicao.x) * 180 / 3.14;
}

void Jogador::atacar(ofVec2f inimi, float tam, ofApp::KeyInput tecla) {

}