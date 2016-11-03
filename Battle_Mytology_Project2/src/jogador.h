#pragma once

#include "ofApp.h"
#include "som.h"

#define MAXSPEED 300.f
#define FAT_ATRITO 12.f
#define VELOCIDADE 30.f
#define VELOCIDADE_ANIMACAO 1.f / 7.f
#define TEMPO_ATAQUE 0.3f

class Jogador {
	public:
		ofImage m_sprite, m_espada;
		ofVec2f m_posicao;
		float m_frameTime, m_atakeTime;
		int m_frame, m_totalFrames, m_spriteTamX, m_spriteTamY, m_direcao, m_direcaoAtaque, r_raioColisao;
		char m_action[15];
		bool m_atakou, m_procurado;	


		void iniciar();
		void animacao(float game_time);
		void acoes(ofApp::KeyInput teclas);
		void desenhar(ofApp::KeyInput tecla);
		void colidiuCom(ofVec2f objeto, ofVec2f& mnd, ofVec2f& vel, float raioObj);
		int getAngulo(ofVec2f pos, ofVec2f mund);
		void atacar(ofApp::KeyInput tecla, Som tmp_som);

		~Jogador();
};