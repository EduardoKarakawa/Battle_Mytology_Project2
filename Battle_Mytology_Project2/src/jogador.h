#pragma once

#include "ofApp.h";


class Jogador {
	public:
		ofImage sprite;
		ofVec2f posicao;
		float velX, velY, velocidade, velocidadeAnimacao, frameTime;
		int frame, totalFrames;


		void iniciar();
		void mover(ofApp::KeyInput teclas, float tempo);
		void atrito(ofApp::KeyInput teclas, float tempo);
};