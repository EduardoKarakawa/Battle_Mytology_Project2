#pragma once

#include "ofApp.h";


class Mapa {

	public:
		ofVec2f posicao;
		ofImage sprite;

		
		void iniciar(float x, float y);
		void mover(ofVec2f direcao);
		void desenhar();
};