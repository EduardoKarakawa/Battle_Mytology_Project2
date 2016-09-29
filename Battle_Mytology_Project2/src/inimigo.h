#pragma once

#include "ofApp.h";

#define MAX_AREA 500
#define VELOCIDADE_ANIMACAO 0.7f
#define VELOCIDADE 100.f

class Inimigo {
	public:
		ofVec2f posicao, velocidade;
		ofImage sprite;
		float velocidadeAnimacao, frameTime;
		int frame, totalFrames, spriteTamX, spriteTamY, direcao;

		void iniciar(int x, int y);
		void mover(ofVec2f posJogador, ofVec2f mund);
		void levardano();
		void atacar();
		void animar(float game_time);

		void desenhar(ofVec2f mund);

};