#pragma once

#include <string>
#include "inimigo.h"
#include "jogador.h"
#include "mapa.h"
#include "KeyInput.h"
#include "som.h"

#define TEMPO_TROCA_ROUND 10.f

class GameControl {
public:
	int m_round;
	Inimigo *m_inimigos;
	ofImage m_spriteInimigo;
	float m_timeToggleRound;
	bool m_desenharMudarRound;
	ofTrueTypeFont m_textos50, m_textos20;


	void Iniciar(ofVec2f mundo);
	Inimigo* IniciarInimigos(ofVec2f mundo);
	Inimigo* CriarInimigos(bool tudoMorto, ofVec2f mundo);
	void UpdateGame(Jogador& player, Mapa& mundo, KeyInput& teclado, Som& sons, float gameTime);
	bool GetTudoMorto();
	bool MudarRound(bool tudoMorto, bool mudarRound);
	ofImage GetSpriteInimigo();



	~GameControl() {
	};
};