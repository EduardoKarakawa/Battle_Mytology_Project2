#pragma once

#include "mover.h"
#include "ofApp.h"


//---------------- Movimentação do jogador-------------------------------------------------------
//-----------------------------------------------------------------------------------------------
void Mover::jogador(ofApp::Player &ply, ofApp::KeyInput teclas, float tempo){
	if (teclas.keyD && (ply.velX < MAXSPEED)) {
		ply.velX += ply.velocidade;
	}
	if (teclas.keyA && (ply.velX > -MAXSPEED)) {
		ply.velX -= ply.velocidade;
	}
	if (teclas.keyS && (ply.velY < MAXSPEED)) {
		ply.velY += ply.velocidade;
	}
	if (teclas.keyW && (ply.velY > -MAXSPEED)) {
		ply.velY -= ply.velocidade;
	}

	ply.posicao.x += ply.velX * tempo;
	ply.posicao.y += ply.velY * tempo;
}



//---------------- Atrito de movimentação do jogador----------------------------------------------
//------------------------------------------------------------------------------------------------
void Mover::atritoPlayer(ofApp::Player &ply, ofApp::KeyInput teclas, float tempo) {
	if (!teclas.keyD && !teclas.keyA) {
		if (ply.velX > 0) {
			ply.velX -= ply.velocidade * tempo;
			if (ply.velX < 0)
				ply.velX = 0;
		}
		if (ply.velX < 0) {
			ply.velX += ply.velocidade * tempo;
			if (ply.velX > 0)
				ply.velX = 0;
		}
	}

	if (!teclas.keyW && !teclas.keyS) {
		if (ply.velY > 0) {
			ply.velY -= ply.velocidade * tempo;
			if (ply.velY < 0)
				ply.velY = 0;
		}
		if (ply.velY < 0) {
			ply.velY += ply.velocidade * tempo;
			if (ply.velY > 0)
				ply.velY = 0;
		}
	}
}