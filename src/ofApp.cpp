#include "ofApp.h"
#include "ofMain.h"
#include "star.h"
#include "ship.h"
#include "score.h"
#include "laser.h"
#include "planet.h"
#include "globals.h"

void ofApp::setup() {
	ofSetBackgroundColor(0);

	nyan.loadImage("images/nyanCat.png");
	rainbow.loadImage("images/rainbow.jpg");
	tacNyan.loadImage("images/tacNyan.png");
	graybow.loadImage("images/graybow.png");
	orangePlanet.loadImage("images/orangePlanet.png");
	purplePlanet.loadImage("images/purplePlanet.png");
	moonPlanet.loadImage("images/moon.png");
	earthPlanet.loadImage("images/earthPlanet.png");
	waterPlanet.loadImage("images/waterPlanet.png");
	scoreFont.loadFont("fonts/XPED_Shadow.ttf", 33);
	laserPlayerSound.load("sounds/laserSound.wav");
	laserEnemySound.load("sounds/enemyLaserShot.wav");

	nyanShip = shipConstruct(100, ofGetHeight() / 2, 0, PLAYER_ACCELERATION, 125, 125 / 2, false, &nyan);
	enemyShip = shipConstruct(ofGetWidth() - 125, ofGetHeight() / 2, 0, ENEMY_ACCELERATION, 125, 125 / 2, true, &tacNyan);

	stars = starsConstruct();

	planets = (ofImage**)malloc(5 * sizeof(ofImage*));

	planets[0] = &orangePlanet;
	planets[1] = &purplePlanet;
	planets[2] = &moonPlanet;
	planets[3] = &earthPlanet;
	planets[4] = &waterPlanet;

	aPlanet = planetConstruct(planets);

	playerShots = lasersConstruct(2, false, &rainbow, &laserPlayerSound);
	enemyShots = lasersConstruct(-2, true, &graybow, &laserEnemySound);

	laserCounter = laserCounterConstruct();
	enemyLaserCounter = laserCounterConstruct();
	enemyShotTimer = laserCounterConstruct();

	playerScore = scoreConstruct(&scoreFont);
}

void ofApp::update() {
	starMoveField(stars);
	planetDetermineSpawn(aPlanet);
	planetMovePlanet(aPlanet);
	shipMove(nyanShip);
	shipEnemyMove(enemyShip, enemyShotTimer);
	laserMoveLasers(playerShots);
	laserDetermineEnemyShot(enemyShotTimer, enemyShots[*enemyLaserCounter], enemyShip, enemyLaserCounter);
	laserMoveLasers(enemyShots);
	// Needs Logic Work
	for (int i = 0; i < MAX_NUMBER_OF_LASERS; ++i) {
		if (laserOnScreen(playerShots[i])) {
			for (int k = 0; k < MAX_NUMBER_OF_LASERS; ++k) {
				if (laserOnScreen(enemyShots[k])) {
					if (laserLasersAreTouching(playerShots[i], enemyShots[k])) {
						laserStore(playerShots[i]);
						laserStore(enemyShots[k]);
						scoreIncrease(playerScore, 10);
						// Display firework image for some frames
					}
				}
			}
		}
	}
}

void ofApp::draw() {
	starDrawField(stars);
	planetDraw(aPlanet);
	shipDraw(nyanShip);
	shipDraw(enemyShip);
	laserDrawLasers(playerShots);
	laserDrawLasers(enemyShots);
	scoreDraw(playerScore);
}

void ofApp::keyPressed(int key) {
	if (key == OF_KEY_UP || key == 'w') {
		shipThrustUp(nyanShip);
	}
	else if (key == OF_KEY_DOWN || key == 's') {
		shipThrustDown(nyanShip);
	}
	if (key == ' ') {
		laserFire(playerShots[*laserCounter], nyanShip);
		//scoreIncrease(playerScore, 10);
		laserModifyCounter(laserCounter);
	}
	if (key == 'k') {
		scoreDecrease(playerScore, 10);
	}
}

void ofApp::keyReleased(int key) {
	// put code here that will remove 
	// instructions on how to play
	// once all instructions are gone.
	// after movement and firing explained,
	// spawn enemy ship, and warn about enemy
	// shots.
	// Fade this out after enemy fires 3 shots?
}

void ofApp::mouseMoved(int x, int y) {

}

void ofApp::mouseDragged(int x, int y, int button) {

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button) {

}

void ofApp::mouseEntered(int x, int y) {

}

void ofApp::mouseExited(int x, int y) {

}

void ofApp::windowResized(int w, int h) {
	shipPositionEnemyShip(enemyShip);
	scoreStayCentered(playerScore);
}

void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::dragEvent(ofDragInfo dragInfo) {

}
