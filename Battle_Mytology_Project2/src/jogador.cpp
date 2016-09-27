#pragma once

#include "ofApp.h"
#include "jogador.h"





ofApp ofappname;

void Jogador::iniciar() {
	//Funcao para iniciar os parametros do Jogador 
	strcpy(action, "iddle");
	sprite.loadImage("iddle.png");
	spriteTamX = 76;
	spriteTamY = 76;
	posicao.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	sprite.setAnchorPoint(sprite.getWidth() / 2, sprite.getWidth() / 2);
	velocidade = 20.f;
	velocidadeAnimacao = 0.7f;
	frame = 0;
	totalFrames = 8;
	direcao = 1;
}


//---------------- Movimentação do jogador--------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::mover(ofApp::KeyInput teclas, float tempo) {
	//Aumenta a velocidade de X ou Y ate o maximo de velocidade de acordo com a tecla precionada
	if (teclas.keyD && (velX < MAXSPEED)) {
		if (velX < 0)
			velX = 0;
		velX += (velocidade) * tempo;
	}
	if (teclas.keyA && (velX > -MAXSPEED)) {
		if (velX > 0)
			velX = 0;
		velX -= velocidade * tempo;
	}
	if (teclas.keyS && (velY < MAXSPEED)) {
		if (velY < 0)
			velX = 0;
		velY += velocidade * tempo;
	}
	if (teclas.keyW && (velY > -MAXSPEED)) {
		if (velY > 0)
			velY = 0;
		velY -= velocidade * tempo;
	}

	//Chama a funcao de atrito para diminuir a velocidade nas direcoes que nao precisa mover 
	atrito(teclas, tempo);

	//Atualiza a posicao do player
	posicao.x += velX;
	posicao.y += velY;

}



//---------------- Atrito de movimentação do jogador----------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::atrito(ofApp::KeyInput teclas, float tempo) {

	//Diminui a velocidade de X ou Y gradualmente ate chegar em 0, so diminui para nas direcoes que a
	//tecla nao estiver precionada
	if (!teclas.keyD && !teclas.keyA) {
		if (velX > 0) {
			velX -= (velocidade * FAT_ATRITO) * tempo;
			if (velX < 0)
				velX = 0;
		}
		if (velX < 0) {
			velX += (velocidade * FAT_ATRITO) * tempo;
			if (velX > 0)
				velX = 0;
		}
	}

	if (!teclas.keyW && !teclas.keyS) {
		if (velY > 0) {
			velY -= (velocidade * FAT_ATRITO) * tempo;
			if (velY < 0)
				velY = 0;
		}
		if (velY < 0) {
			velY += (velocidade * FAT_ATRITO) * tempo;
			if (velY > 0)
				velY = 0;
		}
	}

}



//---------------- Acoes do jogador---------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::acoes(ofApp::KeyInput teclas) {
	//Definindo a direcao pela tecla que estiver precionada, se nao tiver nenhuma 
	//sera definido a ultima tecla precionada
	direcao = teclas.keyA ? 0 : direcao;
	direcao = teclas.keyW ? 1 : direcao;
	direcao = teclas.keyD ? 2 : direcao;	
	direcao = teclas.keyS ? 3 : direcao;

	//Verificando se esta parado
	if (!teclas.keyA && !teclas.keyD && !teclas.keyW && !teclas.keyS)
		sprite.loadImage("iddle.png");

	//Verificando se esta andando
	else if (teclas.keyA || teclas.keyD || teclas.keyW || teclas.keyS){
		sprite.loadImage("andando.png");
	}
		

}


//---------------- Animacao do jogador------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::animacao(float game_time) {
	//Trocando os frames do player para animar
	frameTime += game_time; //Fazendo contagem de tempo
								
	//Trocando o indice de posição do frame do player
	if (frameTime >= velocidadeAnimacao) {
		frame = (frame + 1) % totalFrames;
		frameTime = 0;
	}
}