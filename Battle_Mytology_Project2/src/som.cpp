#pragma once

#include "som.h"

void Som::iniciar() {
	m_andando = 0;
	m_jogador_atakeEspada[0].loadSound("jogador/som/sword_00.wav");
	m_jogador_atakeEspada[1].loadSound("jogador/som/sword_01.wav");
	m_jogador_atakeEspada[2].loadSound("jogador/som/sword_02.wav");
	m_jogador_atakeEspada[3].loadSound("jogador/som/sword_03.wav");

	m_jogador_andando[0].loadSound("jogador/som/walk_grass_00.wav");
	m_jogador_andando[1].loadSound("jogador/som/walk_grass_01.wav");
	m_jogador_andando[2].loadSound("jogador/som/walk_grass_02.wav");
	m_jogador_andando[3].loadSound("jogador/som/walk_grass_03.wav");
	m_jogador_andando[4].loadSound("jogador/som/walk_grass_04.wav");
	
	for (int i = 0; i < 5; i++){
		m_jogador_andando[i].setSpeed(m_jogador_andando[i].getSpeed() * 1.40f);
		m_jogador_andando[i].setVolume(0.3f);
	}


	m_inimigo_levaDano[0].loadSound("inimigo/som/punch_00.wav");
	m_inimigo_levaDano[1].loadSound("inimigo/som/punch_01.wav");
	m_inimigo_levaDano[2].loadSound("inimigo/som/punch_02.wav");
	m_inimigo_levaDano[3].loadSound("inimigo/som/punch_03.wav");

	m_mapa_peacefulMusic.loadSound("mapa/som/peaceful_moment.wav");
	m_mapa_peacefulMusic.setVolume(MAX_PEACEFUL);

	m_mapa_battleMusic.loadSound("mapa/som/battle_music.mp3");
	m_mapa_battleMusic.setVolume(MAX_BATTLE);
	

}



void Som::InimigoLevaDano() {
	m_inimigo_levaDano[rand() % 3].play();

}



void Som::JogadorAtakeEspada() {
	m_jogador_atakeEspada[rand() % 3].play();

}



void Som::JogadorAndando(){
	
	if (!m_jogador_andando[m_andando].getIsPlaying()) {
		m_andando = rand() % 4;
		m_jogador_andando[m_andando].play();
		
		 std::cout << m_andando << std::endl;
	}
}



void Som::AmbientePacifico(bool perseguido) {
	if (!m_mapa_peacefulMusic.getIsPlaying() && !perseguido) {
		m_mapa_peacefulMusic.setLoop(true);
		m_mapa_peacefulMusic.play();
	}
	std::cout << "Pacifico ";
	if(perseguido){
		DiminuirVolume(m_mapa_peacefulMusic);
	}

	else if (!perseguido) {
		AumentarVolume(m_mapa_peacefulMusic, MAX_PEACEFUL);
	}
}



void Som::AmbienteBatalha(bool perseguido) {
	std::cout << "Batalha ";
	if (!m_mapa_battleMusic.getIsPlaying() && perseguido) {
		m_mapa_battleMusic.setLoop(true);
		m_mapa_battleMusic.play();
	}
	
	if (perseguido) {
		AumentarVolume(m_mapa_battleMusic, MAX_BATTLE);
	}

	else if (!perseguido) {
		DiminuirVolume(m_mapa_battleMusic);
	}

}



void Som::DiminuirVolume(ofSoundPlayer &sound) {
	std::cout << sound.getVolume();
	sound.getVolume() > 0 ? sound.setVolume(sound.getVolume() - 0.2f * ofGetLastFrameTime()) : sound.setVolume(0);

}


void Som::AumentarVolume(ofSoundPlayer &sound, float max_vol) {
	std::cout << sound.getVolume();
	sound.getVolume() < max_vol ? sound.setVolume(sound.getVolume() + 0.2f * ofGetLastFrameTime()) : sound.setVolume(max_vol);
}