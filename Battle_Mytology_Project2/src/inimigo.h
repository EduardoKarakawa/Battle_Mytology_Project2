#pragma once

#include "ofApp.h";

#define MAX_AREA 500
#define VELOCIDADE_ANIMACAO 0.7f
#define VELOCIDADE 200.f

class Inimigo {
	public:
		ofVec2f m_posicao, m_velocidade;
		ofImage m_sprite;
		float m_velocidadeAnimacao, m_frameTime;
		int m_frame, m_totalFrames, m_spriteTamX, m_spriteTamY, m_direcao;

		void iniciar(int x, int y);
		void mover(ofVec2f posJogador, ofVec2f mund, float tam);
		void levardano();
		void atacar();
		void animar(float game_time);
		void desenhar(ofVec2f mund);
		void direcao(ofVec2f player, ofVec2f mund);
};