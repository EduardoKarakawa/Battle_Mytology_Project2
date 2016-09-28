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
	sprite.setAnchorPoint(spriteTamX / 2, spriteTamY / 2);
	velocidadeAnimacao = 0.7f;
	frame = 0;
	totalFrames = 8;
	direcao = 1;
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


//---------------- Desenhar o jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::desenhar(ofVec2f mund) {

	sprite.drawSubsection(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, spriteTamX, spriteTamY, spriteTamX * frame, spriteTamY * direcao);

}


//---------------- Colisao do jogador-------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void Jogador::colidiuCom(ofVec2f objeto, ofVec2f& mnd, ofVec2f& vel, float raioObj){
	//Verifica se o jogador colidiu com um determinado objeto e realiza uma subtracao de 
	//vetor de posicao do (objeto + mundo) - player para fazer aumentar a velocidade 
	//contraria da movimentacao do mundo

	if (posicao.distance((objeto + mnd)) <= raioObj + spriteTamX / 2) {
		vel = -((mnd + objeto) - posicao) / 4.f; //Divide por 4 para diminuir a tremedeira
	}
}