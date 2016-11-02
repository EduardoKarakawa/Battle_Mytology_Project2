#pragma once

#include  "ofApp.h"

#define MAX_PEACEFUL 0.3f
#define MAX_BATTLE 0.5f



class Som {
	public:
		int DESBUGA_SOM;
		ofSoundPlayer m_jogador_atakeEspada[4];
		ofSoundPlayer m_jogador_andando[5];
		int m_andando;
		ofSoundPlayer m_inimigo_levaDano[4];

		ofSoundPlayer m_mapa_peacefulMusic;
		ofSoundPlayer m_mapa_battleMusic;



	
		void iniciar();


		void JogadorAtakeEspada();
		void InimigoLevaDano();
		void JogadorAndando();

		void AmbientePacifico(bool perseguido);
		void AmbienteBatalha(bool perseguido);

		void DiminuirVolume(ofSoundPlayer &sound);
		void AumentarVolume(ofSoundPlayer &sound, float max_vol);

		~Som();

};