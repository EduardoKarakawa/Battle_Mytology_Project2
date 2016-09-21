#pragma once

#include "ofMain.h"
#include "mover.h"

#define MAXSPEED 5.f




class ofApp : public ofBaseApp{
	

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
		
		struct Player {
			ofImage sprite;
			ofVec2f posicao;
			float velX, velY, velocidade, velocidadeAnimacao, frameTime;
			int frame, totalFrames;
		};

		struct KeyInput {
			bool keyUp, keyDown;
			bool keyLeft, keyRight;
			bool keyW, keyS;
			bool keyA, keyD;
		};


		Player personagem;
		float before, gameTime;
		KeyInput teclado;


		void drawNaTela(Player& objt);
		
		

		
};
