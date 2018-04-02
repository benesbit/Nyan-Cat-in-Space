#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:

	struct star** stars;
	ofImage** planets;
	struct planet* aPlanet;
	struct ship* nyanShip;
	struct ship* enemyShip;
	struct score* playerScore;
	struct laser** playerShots;
	struct laser** enemyShots;
	int* laserCounter;
	int* enemyLaserCounter;
	int* enemyShotTimer;
	ofImage nyan;
	ofImage rainbow;
	ofImage tacNyan;
	ofImage graybow;
	ofImage orangePlanet;
	ofImage purplePlanet;
	ofImage moonPlanet;
	ofImage earthPlanet;
	ofImage waterPlanet;
	ofTrueTypeFont scoreFont;
	ofSoundPlayer laserPlayerSound;
	ofSoundPlayer laserEnemySound;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
