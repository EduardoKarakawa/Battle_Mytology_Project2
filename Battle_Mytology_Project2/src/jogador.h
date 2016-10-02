#pragma once

#include "ofApp.h";

#define MAXSPEED 300.f
#define FAT_ATRITO 8.f
#define VELOCIDADE 30.f

#define VELOCIDADE_ANIMACAO 0.7f

class Jogador {
	public:
		ofImage m_sprite;
		ofVec2f m_posicao;
		float m_frameTime;
		int m_frame, m_totalFrames, m_spriteTamX, m_spriteTamY, m_direcao;
		char m_action[15];


		void iniciar();
		void animacao(float game_time);
		void acoes(ofApp::KeyInput teclas);
		void desenhar(ofVec2f mund);
		void colidiuCom(ofVec2f objeto, ofVec2f& mnd, ofVec2f& vel, float raioObj);
		int getAngulo(ofVec2f pos, ofVec2f mund);
		void atacar(ofVec2f inimi, float tam, ofApp::KeyInput tecla);
};