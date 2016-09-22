#pragma once

#include "ofApp.h"
#include "jogador.h"



void Jogador::iniciar() {
	sprite.loadImage("andando.png");
	posicao.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	sprite.setAnchorPoint(sprite.getWidth() / 2, sprite.getWidth() / 2);
	velocidade = 500.f;
	velocidadeAnimacao = 0.5f;
	frame = 0;
	totalFrames = sprite.getHeight() / sprite.getWidth();
}


//---------------- Movimentação do jogador--------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::mover(ofApp::KeyInput teclas, float tempo) {
	if (teclas.keyD && (velX < MAXSPEED)) {
		velX += velocidade;
	}
	if (teclas.keyA && (velX > -MAXSPEED)) {
		velX -= velocidade;
	}
	if (teclas.keyS && (velY < MAXSPEED)) {
		velY += velocidade;
	}
	if (teclas.keyW && (velY > -MAXSPEED)) {
		velY -= velocidade;
	}

	posicao.x += velX * tempo;
	posicao.y += velY * tempo;
}



//---------------- Atrito de movimentação do jogador----------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::atrito( ofApp::KeyInput teclas, float tempo) {
	if (!teclas.keyD && !teclas.keyA) {
		if (velX > 0) {
			velX -= velocidade * tempo;
			if (velX < 0)
				velX = 0;
		}
		if (velX < 0) {
			velX += velocidade * tempo;
			if (velX > 0)
				velX = 0;
		}
	}

	if (!teclas.keyW && !teclas.keyS) {
		if (velY > 0) {
			velY -= velocidade * tempo;
			if (velY < 0)
				velY = 0;
		}
		if (velY < 0) {
			velY += velocidade * tempo;
			if (velY > 0)
				velY = 0;
		}
	}
}
