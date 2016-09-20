#pragma once

#include "ofMain.h"

#define MAXSPEED 5.f

struct Player {
	ofImage sprite;
	ofVec2f posicao;
	float velX, velY , velocidade, velocidadeAnimacao, frameTime;
	int frame, totalFrames;
};


struct KeyInput {
	bool keyUp, keyDown;
	bool keyLeft, keyRight;
	bool keyW, keyS;
	bool keyA, keyD;
};


class ofApp : public ofBaseApp{

	Player personagem;
	float before, gameTime;
	KeyInput teclado;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void drawNaTela(Player& objt);
		
		void movimentaPlayer(Player& ply, KeyInput teclas, float tempo) {
			if (teclas.keyD && (ply.velX < MAXSPEED)) {
				ply.velX += ply.velocidade * tempo;
			}
			if (teclas.keyA && (ply.velX > -MAXSPEED)) {
				ply.velX -= ply.velocidade * tempo;
			}
			if (teclas.keyS && (ply.velY < MAXSPEED)) {
				ply.velY += ply.velocidade * tempo;
			}
			if (teclas.keyW && (ply.velY > -MAXSPEED)) {
				ply.velY -= ply.velocidade * tempo;
			}

			ply.posicao.x += ply.velX;
			ply.posicao.y += ply.velY;
		}

		void movAtritoPlayer(Player& ply, KeyInput teclas, float tempo) {
			if (!teclas.keyD && !teclas.keyA) {
				if (ply.velX > 0) {
					ply.velX -= ply.velocidade * tempo;
					if (ply.velX < 0)
						ply.velX = 0;
				}
				if (ply.velX < 0) {
					ply.velX += ply.velocidade * tempo;
					if (ply.velX > 0)
						ply.velX = 0;
				}
			}

			if (!teclas.keyW && !teclas.keyS) {
				if (ply.velY > 0) {
					ply.velY -= ply.velocidade * tempo;
					if (ply.velY < 0)
						ply.velY = 0;
				}
				if (ply.velY < 0) {
					ply.velY += ply.velocidade * tempo;
					if (ply.velY > 0)
						ply.velY = 0;
				}
			}
		}

		
};
