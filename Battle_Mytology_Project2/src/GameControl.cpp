#include "GameControl.h"


Inimigo* GameControl::CriarInimigos(bool tudoMorto, ofVec2f mundo) {
	if (tudoMorto) {
		m_inimigos = new Inimigo[m_round];
		m_inimigos = IniciarInimigos(mundo);
	}
	
	return m_inimigos;

}



bool GameControl::GetTudoMorto(){
	bool tmp_tudoMorto = true;
	for (int i = 0; i < m_round; i++) {
		tmp_tudoMorto = tmp_tudoMorto && m_inimigos[i].m_morto;
	}
	return tmp_tudoMorto;
}


void GameControl::Iniciar(ofVec2f mundo){
	m_round = 0; 
	m_spriteInimigo.load("inimigo/inimigo.png");
	m_inimigos = CriarInimigos(true, mundo);
	m_timeToggleRound = TEMPO_TROCA_ROUND;
	m_desenharMudarRound = false;
	m_textos50.loadFont("font/ariblk.ttf", 50, true, true, false, 5.f, 0);
	m_textos20.loadFont("font/ariblk.ttf", 20, true, true, false, 5.f, 0);
	
}

Inimigo* GameControl::IniciarInimigos(ofVec2f mundo) {
	for (int i = 0; i < m_round; i++) {
		m_inimigos[i].iniciar(480 + rand() % 600, 250 + rand() % 100);
	}
	return m_inimigos;
}


void GameControl::UpdateGame(Jogador& player, Mapa& mundo, KeyInput& teclado,Som& sons,float gameTime) {
	//Controla tudo aki, colisao, movimentacao de inimigo .......
	for (int i = 0; i < m_round; i++) {
		if (!m_inimigos[i].m_morto) {
			player.colidiuCom(m_inimigos[i].m_posicao, mundo.posicao, mundo.velocidade, m_inimigos[i].m_spriteTamX / 2.f);

			m_inimigos[i].animar();

			/* Verifica se um inimigo esta colidindo com outro inimigo*/
			for (int j = 0; j < m_round; j++) {
				if(i != j)
					m_inimigos[i].colidiuCom(m_inimigos[j], mundo.posicao);
			}

			m_inimigos[i].mover(player.m_posicao, mundo.posicao, player.m_spriteTamX);
			m_inimigos[i].levardano(player.m_posicao, mundo.posicao, player.m_spriteTamX, teclado, (player.m_atakeTime <= ofGetLastFrameTime()) && player.m_atakou, sons);
			
			player.m_procurado = m_inimigos[i].seguir(player.m_posicao, mundo.posicao);
			player.levardano(m_inimigos[i].Atacar(player.m_posicao, player.r_raioColisao, mundo.posicao));
		}
	}

	if (GetTudoMorto())
		player.m_procurado = false;

	
	if(GetTudoMorto() || (m_round == 0))
		m_inimigos = CriarInimigos(MudarRound(GetTudoMorto(), teclado.keySpace), mundo.posicao);



}



bool GameControl::MudarRound(bool tudoMorto, bool mudarRound) {
	std::cout << m_timeToggleRound << std::endl;
	if (tudoMorto && (m_timeToggleRound > 0)) {
		m_timeToggleRound -= ofGetLastFrameTime();
		m_desenharMudarRound = false;
		if (m_timeToggleRound <= 2) {
			m_desenharMudarRound = true;
		}
	}
	else if ((mudarRound && tudoMorto) || (m_timeToggleRound <= 0)) {
			m_timeToggleRound = TEMPO_TROCA_ROUND;
			m_round++;
			m_desenharMudarRound = false;
			return true;

	}
	return false;
}

ofImage GameControl::GetSpriteInimigo(){
	return m_spriteInimigo;
}




