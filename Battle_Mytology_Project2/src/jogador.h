#pragma once

#include "ofApp.h";

#define MAXSPEED 5.f
#define FAT_ATRITO 0.3f

class Jogador {
	public:
		ofImage sprite;
		ofVec2f posicao;
		float velX, velY, velocidade, velocidadeAnimacao, frameTime;
		int frame, totalFrames, spriteTamX, spriteTamY, direcao;
		char action[15];


		void iniciar();
		void mover(ofApp::KeyInput teclas, float tempo);
		void atrito(ofApp::KeyInput teclas, float tempo);
		void animacao(float game_time);
		void acoes(ofApp::KeyInput teclas);
};