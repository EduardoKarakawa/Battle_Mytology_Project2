#pragma once

#include "ofApp.h";
#include "som.h"


#define MAXSPEED 100.f
#define FAT_ATRITO 15.f
#define VELOCIDADE 30.f

class Mapa {

	public:
		ofVec2f posicao, velocidade;
		ofImage sprite;

		
		void iniciar(float x, float y);
		void mover(KeyInput teclas, Som &tmp_som);
		void atrito(KeyInput teclas);
		void desenhar();


		~Mapa();
};