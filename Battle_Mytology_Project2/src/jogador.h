#pragma once

#include "ofApp.h";

#define MAXSPEED 300.f
#define FAT_ATRITO 8.f
#define VELOCIDADE 30.f

class Jogador {
	public:
		ofImage sprite;
		ofVec2f posicao, velocidade;
		float velocidadeAnimacao, frameTime;
		int frame, totalFrames, spriteTamX, spriteTamY, direcao;
		char action[15];
		bool colidiu;


		void iniciar();
		void mover(ofApp::KeyInput teclas, float tempo);
		void atrito(ofApp::KeyInput teclas, float tempo);
		void animacao(float game_time);
		void acoes(ofApp::KeyInput teclas);
		void desenhar(ofVec2f mund);
		void colidiuCom(ofVec2f objeto, ofVec2f& mnd, float raioObj);
};