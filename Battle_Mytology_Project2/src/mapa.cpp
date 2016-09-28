#pragma once

#include "mapa.h";

void Mapa::iniciar(float x, float y) {
	posicao.set(x, y);
	sprite.load("mapa/terreno.png");
}


void Mapa::mover(ofVec2f direcao) {
	posicao -= direcao * ofGetLastFrameTime();
}


void Mapa::desenhar() {
	sprite.draw(posicao);
}