#pragma once

#include "ofApp.h";

#define MAXSPEED 300.f
#define FAT_ATRITO 8.f
#define VELOCIDADE 30.f

class Jogador {
	public:
		ofImage sprite;
		ofVec2f posicao;
		float velocidadeAnimacao, frameTime;
		int frame, totalFrames, spriteTamX, spriteTamY, direcao;
		char action[15];


		void iniciar();
		void animacao(float game_time);
		void acoes(ofApp::KeyInput teclas);
		void desenhar(ofVec2f mund);
		void colidiuCom(ofVec2f objeto, ofVec2f& mnd, ofVec2f& vel, float raioObj);
};