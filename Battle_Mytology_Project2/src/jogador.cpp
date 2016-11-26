#pragma once

#include "jogador.h"
#include <time.h>


ofApp ofappname;

void Jogador::iniciar() {
	//Funcao para iniciar os parametros do Jogador 
	strcpy(m_action, "iddle");
	m_sprite.loadImage("jogador/iddle.png");
	m_totalFrames = 6;
	m_spriteTamX = m_sprite.getWidth() / (m_totalFrames * 1.f);
	m_spriteTamY = m_sprite.getHeight() / 4.f;
	m_posicao.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	m_sprite.setAnchorPoint(m_spriteTamX / 2.f, m_spriteTamY * 0.8f);
	m_frame = 0;
	m_direcao = 1;
	m_atakou = false;
	m_procurado = false;
	r_raioColisao = 20.f;
	m_vida = 100.f;
	m_vidaVazia.load("ui/barraVidaVazia.png");
	m_vidaCheia.load("ui/barraVidaCheia.png");
}


//---------------- Acoes do jogador---------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::acoes(KeyInput teclas) {
	//Definindo a direcao pela tecla que estiver precionada, se nao tiver nenhuma 
	//sera definido a ultima tecla precionada
	m_direcao = teclas.keyA ? 0 :
		teclas.keyW ? 1 :
		teclas.keyD ? 2 :
		teclas.keyS ? 3 : m_direcao;

	m_direcao = teclas.keyLeft ? 0 :
		teclas.keyUp ? 1:
		teclas.keyRight ? 2 :
		teclas.keyDown ? 3 : m_direcao;
	
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
	if (m_atakou && (m_frameTime >= VELOCIDADE_ATAKE)) {
		m_frame = (m_frame + 1) % m_totalFrames;
		m_frameTime = 0;
	}
	else if (m_frameTime >= VELOCIDADE_ANIMACAO) {
		m_frame = (m_frame + 1) % m_totalFrames;
		m_frameTime = 0;
	}
}


//---------------- Desenhar o jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::desenhar(KeyInput tecla) {
	if (m_atakou) {
		m_sprite.loadImage("jogador/atacando.png");
	}

	m_spriteTamX = m_sprite.getWidth() / (m_totalFrames * 1.f);
	m_spriteTamY = m_sprite.getHeight() / 4.f;
	m_posicao.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	m_sprite.setAnchorPoint(m_spriteTamX / 2.f, m_spriteTamY * 0.8f);

	m_sprite.drawSubsection(m_posicao.x, m_posicao.y, m_spriteTamX, m_spriteTamY, m_spriteTamX * m_frame, m_spriteTamY * m_direcao);

}


//---------------- Colisao do jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::colidiuCom(ofVec2f objeto, ofVec2f& mnd, ofVec2f& vel, float raioObj){
	//Verifica se o jogador colidiu com um determinado objeto e realiza uma subtracao de 
	//vetor de posicao do (objeto + mundo) - player para fazer aumentar a velocidade 
	//contraria da movimentacao do mundo

	if (m_posicao.distance((objeto + mnd)) <= raioObj + r_raioColisao) {
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

void Jogador::atacar(KeyInput tecla, Som tmp_som) {
	if ((tecla.keyUp || tecla.keyDown || tecla.keyLeft || tecla.keyRight) && (m_atakeTime <= 0)) {
		tmp_som.JogadorAtakeEspada();
		m_atakou = true;
	}

		m_atakeTime = m_atakou && (m_atakeTime < TEMPO_ATAQUE) ? m_atakeTime + ofGetLastFrameTime() : 0;
		m_atakou = m_atakeTime <= 0 ? false : m_atakou;

}

Jogador::~Jogador() {

}

void Jogador::DrawVida() {
	m_vidaCheia.drawSubsection(100.f, ofGetHeight() - 100.f, m_vidaCheia.getWidth() * (m_vida / 100.f), m_vidaCheia.getHeight(), 90, 90);
	m_vidaVazia.draw(100.f, ofGetHeight() - 100.f);
}



//---------------- Levar Dano --------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::levardano(float dano) {
	if(dano != -1)
		m_vida -= dano;
}
