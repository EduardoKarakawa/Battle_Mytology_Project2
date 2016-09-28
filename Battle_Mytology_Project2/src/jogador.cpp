#pragma once

#include "jogador.h"

ofApp ofappname;

void Jogador::iniciar() {
	//Funcao para iniciar os parametros do Jogador 
	strcpy(action, "iddle");
	sprite.loadImage("iddle.png");
	spriteTamX = 76;
	spriteTamY = 76;
	posicao.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	sprite.setAnchorPoint(0, 0);
	velocidade.set(0,0);
	velocidadeAnimacao = 0.7f;
	frame = 0;
	totalFrames = 8;
	direcao = 1;
	colidiu = false;
}


//---------------- Movimentação do jogador--------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::mover(ofApp::KeyInput teclas, float tempo) {
	//Aumenta a velocidade de X ou Y ate o maximo de velocidade de acordo com a tecla precionada
	if (teclas.keyD && (velocidade.x < MAXSPEED)) {
		velocidade.x += VELOCIDADE;
	}
	if (teclas.keyA && (velocidade.x > -MAXSPEED)) {
		velocidade.x -= VELOCIDADE;
	}
	if (teclas.keyS && (velocidade.y < MAXSPEED)) {
		velocidade.y += VELOCIDADE;
	}
	if (teclas.keyW && (velocidade.y > -MAXSPEED)) {

		velocidade.y -= VELOCIDADE;
	}

	//Chama a funcao de atrito para diminuir a velocidade nas direcoes que nao precisa mover 
	atrito(teclas, tempo);

	//Atualiza a posicao do player
	 
	posicao += velocidade * ofGetLastFrameTime();

}



//---------------- Atrito de movimentação do jogador----------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::atrito(ofApp::KeyInput teclas, float tempo) {

	//Diminui a velocidade de X ou Y gradualmente ate chegar em 0, so diminui para nas direcoes que a
	//tecla nao estiver precionada
	if (!teclas.keyD && !teclas.keyA) {
		if (velocidade.x > 0) {
			velocidade.x -= FAT_ATRITO;
			if (velocidade.x < 0)
				velocidade.x = 0;
		}
		if (velocidade.x < 0) {
			velocidade.x += FAT_ATRITO;
			if (velocidade.x > 0)
				velocidade.x = 0;
		}
	}

	if (!teclas.keyW && !teclas.keyS) {
		if (velocidade.y > 0) {
			velocidade.y -= FAT_ATRITO;
			if (velocidade.y < 0)
				velocidade.y = 0;
		}
		if (velocidade.y < 0) {
			velocidade.y += FAT_ATRITO;
			if (velocidade.y > 0)
				velocidade.y = 0;
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
		//sprite.setAnchorPoint(spriteTamX * frame, spriteTamY * direcao);
		frame = (frame + 1) % totalFrames;
		frameTime = 0;
	}
}

void Jogador::desenhar(ofVec2f mund) {

	//sprite.drawSubsection(posicao.x, posicao.y, spriteTamX, spriteTamY, spriteTamX * frame, spriteTamY * direcao);
	sprite.drawSubsection(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, spriteTamX, spriteTamY, spriteTamX * frame, spriteTamY * direcao);
	//sprite.drawSubsection(512, 384, spriteTamX, spriteTamY, spriteTamX * frame, spriteTamY * direcao);

}


void Jogador::colidiuCom(ofVec2f objeto, ofVec2f& mnd, float raioObj){


	if (posicao.distance(objeto + mnd) <= raioObj) {
		//mnd += objeto - posicao;
		//posicao =
		velocidade.set(0, 0);
		colidiu = true;
	}
	else if (posicao.distance(objeto) >= raioObj)
		colidiu = false;

}