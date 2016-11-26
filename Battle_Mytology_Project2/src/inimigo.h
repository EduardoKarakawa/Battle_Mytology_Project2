#pragma once

#include "ofApp.h"
#include "jogador.h"
#include "som.h"

#define VELOCIDADE_ANIMACAO 1.f / 8.f
#define VELOCIDADE 70.f
#define CAMPO_VISAO 500.f
#define STUN_TIME 0.17f

class Inimigo {

public:
	ofVec2f m_posicao, m_velocidade;
	float m_velocidadeAnimacao, m_frameTime, m_stunTime, m_raioColisao;
	int m_frame, m_atakouFrame, m_totalFrames, m_spriteTamX, m_spriteTamY, m_direcao, m_dano;
	bool m_seguirJogador, m_morto;
	int m_vida;
	float m_timeAtack;



		void iniciar(int x, int y);
		void mover(ofVec2f posJogador, ofVec2f mund, float tam);
		void levardano(ofVec2f player, ofVec2f mund, float tamArea, KeyInput teclas, bool levadano, Som tmp_som);
	
		void animar();
		void colidiuCom(Inimigo inim, ofVec2f mund);
		void desenhar(ofVec2f mund, ofImage sprite);
		void direcao(ofVec2f player, ofVec2f mund);
		bool seguir(ofVec2f player, ofVec2f mund);
		float getAngulo(ofVec2f pos);
		float Atacar(ofVec2f jogador, float radius, ofVec2f mundo);

		~Inimigo();
};