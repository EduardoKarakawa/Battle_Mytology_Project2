#pragma once

#include "mapa.h";


void Mapa::iniciar(float x, float y) {
	posicao.set(x, y);
	sprite.load("mapa/terreno.png");
}


void Mapa::mover(ofApp::KeyInput teclas) {
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
	atrito(teclas);

	//Atualiza a posicao do player
	 
	posicao -= velocidade * ofGetLastFrameTime();

}


void Mapa::desenhar() {
	sprite.draw(posicao);
}



//---------------- Atrito de movimentação do jogador----------------------------------------------
//------------------------------------------------------------------------------------------------
void Mapa::atrito(ofApp::KeyInput teclas) {

	//Diminui a velocidade de X ou Y gradualmente ate chegar em 0, so diminui para nas direcoes que a
	//tecla nao estiver precionada
	if (!teclas.keyD && !teclas.keyA) {
		if (velocidade.x < 0) {
			velocidade.x += FAT_ATRITO;
			if (velocidade.x > 0)
				velocidade.x = 0;
		}
		if (velocidade.x > 0) {
			velocidade.x -= FAT_ATRITO;
			if (velocidade.x < 0)
				velocidade.x = 0;
		}
	}

	if (!teclas.keyW && !teclas.keyS) {
		if (velocidade.y < 0) {
			velocidade.y += FAT_ATRITO;
			if (velocidade.y > 0)
				velocidade.y = 0;
		}
		if (velocidade.y > 0) {
			velocidade.y -= FAT_ATRITO;
			if (velocidade.y < 0)
				velocidade.y = 0;
		}
	}

}