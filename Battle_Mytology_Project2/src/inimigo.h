#pragma once

#include "ofApp.h"
#include "jogador.h"
#include "som.h"

#define MAX_AREA 500
#define VELOCIDADE_ANIMACAO 0.7f
#define VELOCIDADE 100.f
#define CAMPO_VISAO 1200.f
#define STUN_TIME 0.17f

class Inimigo {

public:
	ofVec2f m_posicao, m_velocidade;
	ofImage m_sprite;
	float m_velocidadeAnimacao, m_frameTime, m_stunTime;
	int m_frame, m_totalFrames, m_spriteTamX, m_spriteTamY, m_direcao, m_dano;
	bool m_seguirJogador;
	int m_vida;



		void iniciar(int x, int y, ofVec2f mund);
		void mover(ofVec2f posJogador, ofVec2f mund, float tam);
		void levardano(ofVec2f player, ofVec2f mund, float tamArea, ofApp::KeyInput teclas, bool levadano, Som tmp_som);
		void atacar();
		void animar(float game_time);
		void colidiuCom(Inimigo inim[2], ofVec2f mund, int id);
		void desenhar(ofVec2f mund);
		void direcao(ofVec2f player, ofVec2f mund);
		bool seguir(ofVec2f player, ofVec2f mund);
		float getAngulo(ofVec2f pos);
};