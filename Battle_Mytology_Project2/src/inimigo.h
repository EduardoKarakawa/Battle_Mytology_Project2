#pragma once

#include "ofApp.h";

#define MAX_AREA 500
#define VELOCIDADE_ANIMACAO 0.7f
#define VELOCIDADE 100.f
#define CAMPO_VISAO 1200.f

class Inimigo { 
		
	public:
		ofVec2f m_posicao, m_velocidade;
		ofImage m_sprite;
		float m_velocidadeAnimacao, m_frameTime;
		int m_frame, m_totalFrames, m_spriteTamX, m_spriteTamY, m_direcao;
		bool m_seguirJogador;


		void iniciar(int x, int y);
		void mover(ofVec2f posJogador, ofVec2f mund, float tam);
		void levardano();
		void atacar();
		void animar(float game_time);
		void colidiuCom(Inimigo inim[2], ofVec2f mund, int id);
		void desenhar(ofVec2f mund);
		void direcao(ofVec2f player, ofVec2f mund);
		bool seguir(ofVec2f player, ofVec2f mund);
};