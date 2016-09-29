#pragma once

#include "inimigo.h"
#include <time.h>

void Inimigo::iniciar(int x, int y){
	srand(time(NULL));

	sprite.load("inimigo/inimigo.png");
	posicao.set(x + (rand() % MAX_AREA) - MAX_AREA / 2.f, y + (rand() % MAX_AREA) - MAX_AREA / 2.f);
	spriteTamX = 76;
	spriteTamY = 76;
	sprite.setAnchorPoint(spriteTamX / 2, spriteTamY / 2);
	frame = 0;
	totalFrames = 8;
	direcao = 1;

}


void Inimigo::mover(ofVec2f posJogador, ofVec2f mund){

	ofVec2f tmp;
	posicao += tmp * (VELOCIDADE * ofGetLastFrameTime());

}


void Inimigo::levardano(){


}


void Inimigo::atacar(){


}


//---------------- Animacao do jogador------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::animar(float game_time) {
	//Trocando os frames do player para animar
	frameTime += game_time; //Fazendo contagem de tempo

							//Trocando o indice de posição do frame do player
	if (frameTime >= VELOCIDADE_ANIMACAO) {
		frame = (frame + 1) % totalFrames;
		frameTime = 0;
	}
}


//---------------- Desenhar o jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Inimigo::desenhar(ofVec2f mund) {

	sprite.drawSubsection(posicao.x + mund.x, posicao.y + mund.y, spriteTamX, spriteTamY, spriteTamX * frame, spriteTamY * direcao);

}