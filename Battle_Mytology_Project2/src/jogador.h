#pragma once

#include "ofApp.h"
#include "som.h"

#define MAXSPEED 1000.f
#define FAT_ATRITO 10.f
#define VELOCIDADE 250.f
#define VELOCIDADE_ANIMACAO 1.f / 7.f
#define VELOCIDADE_ATAKE 1.f / 30.f
#define TEMPO_ATAQUE 0.3f

class Jogador {
	public:
		ofImage m_sprite, m_vidaVazia, m_vidaCheia;
		ofVec2f m_posicao;
		float m_frameTime, m_atakeTime;
		int m_frame, m_totalFrames, m_spriteTamX, m_spriteTamY, m_direcao, m_direcaoAtaque, r_raioColisao;
		char m_action[15];
		bool m_atakou, m_procurado;	
		float m_vida;


		void iniciar();
		void animacao(float game_time);
		void acoes(KeyInput teclas);
		void desenhar(KeyInput tecla);
		void colidiuCom(ofVec2f objeto, ofVec2f& mnd, ofVec2f& vel, float raioObj);
		int getAngulo(ofVec2f pos, ofVec2f mund);
		void atacar(KeyInput tecla, Som tmp_som);
		void DrawVida();
		void levardano(float dano);
		~Jogador();
};