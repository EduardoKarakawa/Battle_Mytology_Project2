#pragma once
#include "ofApp.h"

#include "jogador.h"
#include "mapa.h"
#include "som.h"
#include "GameControl.h"

Jogador player;
GameControl gmControl;
Mapa mundo;
Som sons; 
ofVec2f paredeInv[41];


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::setup(){
	srand(time(NULL));
	//Iniciando contagem de tempo de execução
	before = ofGetElapsedTimef();
	sons.iniciar();
	//Iniciando o Mundo
	mundo.iniciar(-750 + ofGetWidth() / 2.f, -1200 + ofGetHeight() / 2.f);

	//Inicializando o Player

	player.iniciar();

	gmControl.m_round = 5;
	gmControl.Iniciar(mundo.posicao);
	
	

	// Blocos de colisao
	paredeInv[0].set(748, 1419);
	paredeInv[1].set(638, 1417);
	paredeInv[2].set(538, 1393);
	paredeInv[3].set(438, 1319);
	paredeInv[4].set(438, 1204);
	paredeInv[5].set(512, 1130);
	paredeInv[6].set(612, 1120);
	paredeInv[7].set(612, 1020);
	paredeInv[8].set(574, 916);
	paredeInv[9].set(438, 880);
	paredeInv[10].set(313, 831);
	paredeInv[11].set(239, 732);
	paredeInv[12].set(239, 600);
	paredeInv[13].set(239, 526);
	paredeInv[14].set(239, 412);
	paredeInv[15].set(239, 312);
	paredeInv[16].set(239, 201);
	paredeInv[17].set(313, 127);
	paredeInv[18].set(426, 89);
	paredeInv[19].set(538, 74);
	paredeInv[20].set(671, 74);
	paredeInv[21].set(814, 74);
	paredeInv[22].set(929, 89);
	paredeInv[23].set(1055, 97);
	paredeInv[24].set(1158, 127);
	paredeInv[25].set(1251, 167);
	paredeInv[26].set(1306, 264);
	paredeInv[27].set(1306, 378);
	paredeInv[28].set(1306, 460);
	paredeInv[29].set(1253, 560);
	paredeInv[30].set(1253, 674);
	paredeInv[31].set(1236, 768);
	paredeInv[32].set(1162, 842);
	paredeInv[33].set(1053, 872);
	paredeInv[34].set(921, 916);
	paredeInv[35].set(888, 1020);
	paredeInv[36].set(888, 1120);
	paredeInv[37].set(979, 1130);
	paredeInv[38].set(1053, 1204);
	paredeInv[39].set(1053, 1308);
	paredeInv[40].set(962, 1393);
	paredeInv[41].set(855, 1417);

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::update(){
	if (player.m_vida > 0) {

	//Atualizando a contagem de tempo de execução do jogo.
		gameTime = ofGetElapsedTimef() - before;
		before = ofGetElapsedTimef();

		
		for (int i = 0; i < 42; i++) {
			player.colidiuCom(paredeInv[i], mundo.posicao, mundo.velocidade, 70);
		}
		
		gmControl.UpdateGame(player, mundo, teclado, sons, gameTime);

		sons.AmbienteBatalha(player.m_procurado);
		sons.AmbientePacifico(player.m_procurado);

	//Controlando o player
		player.animacao(gameTime);
		player.acoes(teclado);
		player.atacar(teclado, sons);

	//Controlando o Mundo
		mundo.mover(teclado, sons);

	}
	

		
		
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::draw(){
	float centroTelaX = ofGetWidth() / 2.f;
	mundo.desenhar();

	ofSetColor(255, 255, 255);
	for (int i = 0; i < gmControl.m_round; i++) {
		if(!gmControl.m_inimigos[i].m_morto)
			gmControl.m_inimigos[i].desenhar(mundo.posicao, gmControl.m_spriteInimigo);
	}
	player.desenhar(teclado);
	player.DrawVida();

	if (gmControl.m_desenharMudarRound) {
		gmControl.m_textos50.drawString("WavE", centroTelaX - 100.f, ofGetHeight() * 0.24f);
		gmControl.m_textos50.drawString(to_string(gmControl.m_round + 1), centroTelaX - 25.f, (ofGetHeight() * 0.24f) + 70.f);
	}

	if (player.m_vida <= 0) {
		gmControl.m_textos50.drawString("Voce Morreu!", centroTelaX - 250.f, ofGetHeight() * 0.3f);
		gmControl.m_textos20.drawString("Aperte", centroTelaX - 50.f, (ofGetHeight() * 0.33f) + 250.f);
		gmControl.m_textos50.drawString("ESPACO", centroTelaX - 150.f, (ofGetHeight() * 0.33f) + 320.f);
		gmControl.m_textos20.drawString("para reiniciar", centroTelaX - 100.f, (ofGetHeight() * 0.33f) + 350.f);
	}
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::keyPressed(int key){
	//Inputs de movimentação
	if ((key == 'W') || (key == 'w'))
		teclado.keyW = true;
	if ((key == 'S') || (key == 's'))
		teclado.keyS = true;
	if ((key == 'A') || (key == 'a'))
		teclado.keyA = true;
	if ((key == 'D') || (key == 'd'))
		teclado.keyD = true;

	//Inputs de ataque
	if (key == OF_KEY_UP)
		teclado.keyUp = true;
	if (key == OF_KEY_DOWN)
		teclado.keyDown = true;
	if (key == OF_KEY_LEFT	)
		teclado.keyLeft= true;
	if (key == OF_KEY_RIGHT)
		teclado.keyRight = true;
	if (key == ' ') {
		if (player.m_vida <= 0)
			setup();
		teclado.keySpace = true;
	}
		

	if (key == OF_KEY_ESC) {
		player.~Jogador();
		sons.~Som();
		mundo.~Mapa();
		teclado.~KeyInput();
		gmControl.~GameControl();

	}
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::keyReleased(int key){
	//Inputs de movimentação
	if ((key == 'W') || (key == 'w'))
		teclado.keyW = false;
	if ((key == 'S') || (key == 's'))
		teclado.keyS = false;
	if ((key == 'A') || (key == 'a'))
		teclado.keyA = false;
	if ((key == 'D') || (key == 'd'))
		teclado.keyD = false;
	if (key == ' ')
		teclado.keySpace = false;

	//Inputs de ataque
	if (key == OF_KEY_UP)
		player.m_direcaoAtaque = 1;
		teclado.keyUp = false;
	if (key == OF_KEY_DOWN)
		player.m_direcaoAtaque = 3;
		teclado.keyDown = false;
	if (key == OF_KEY_LEFT)
		player.m_direcaoAtaque = 0;
		teclado.keyLeft = false;
	if (key == OF_KEY_RIGHT)
		player.m_direcaoAtaque = 2;
		teclado.keyRight = false;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
