#pragma once

#include "ofApp.h";

#define MAXSPEED 300.f
#define FAT_ATRITO 8.f
#define VELOCIDADE 30.f

class Mapa {

	public:
		ofVec2f posicao, velocidade;
		ofImage sprite;

		
		void iniciar(float x, float y);
		void mover(ofApp::KeyInput teclas);
		void atrito(ofApp::KeyInput teclas);
		void desenhar();
};