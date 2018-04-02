// planet.cpp

#include "ofMain.h"
#include "ofApp.h"
#include "planet.h"
#include "globals.h"

struct planet {
	float x;
	float y;
	float w;
	float h;
	float speed;
	bool onScreen;
	float timer;
	ofImage** planetImages;
	int planetIndex;
};

struct planet * planetConstruct(ofImage* thisPlanetImages[]) {
	// Allocate memory
	struct planet * thisPlanet = (struct planet*)malloc(sizeof(struct planet));
	thisPlanet->planetImages = (ofImage**)malloc(sizeof(thisPlanetImages) * sizeof(ofImage*));
	// Set up params
	thisPlanet->x = ofGetWidth() + 50;
	thisPlanet->y = (int)ofRandom(ofGetHeight());
	thisPlanet->w = 350;
	thisPlanet->h = 350;
	thisPlanet->speed = 0.5;
	thisPlanet->timer = 1;
	thisPlanet->onScreen = false;
	thisPlanet->planetIndex = (int)ofRandom(sizeof(thisPlanetImages));

	for (int i = 0; i < sizeof(thisPlanetImages); ++i) {
		thisPlanet->planetImages[i] = thisPlanetImages[i];
	}
	
	return thisPlanet;
}

void planetDraw(struct planet* thisPlanet) {
	if (planetOnScreen(thisPlanet)) {
		ofSetColor(255);
		thisPlanet->planetImages[(thisPlanet->planetIndex)]->draw(thisPlanet->x, thisPlanet->y, thisPlanet->w, thisPlanet->h);
	}
}

void planetMovePlanet(struct planet* thisPlanet) {
	if (planetOnScreen(thisPlanet)) {
		thisPlanet->x -= thisPlanet->speed;
		planetStayInbounds(thisPlanet);
	}
	else {
		thisPlanet->timer += 0.1;
	}
}

void planetStayInbounds(struct planet* thisPlanet) {
	if ((thisPlanet->x) < (-1 * thisPlanet->w)) {
		thisPlanet->x = ofGetWidth() + 10;
		thisPlanet->y = (float)ofRandom(ofGetHeight());
		thisPlanet->onScreen = false;
		planetChangePlanet(thisPlanet);
	}
}

void planetChangePlanet(struct planet* thisPlanet) {
	thisPlanet->planetIndex = (int)ofRandom(sizeof(thisPlanet->planetImages));
}

bool planetOnScreen(struct planet* thisPlanet) {
	return (thisPlanet->onScreen);
}

void planetDetermineSpawn(struct planet* thisPlanet) {
	if (planetShouldSpawn(thisPlanet)) {
		thisPlanet->onScreen = true;
	}
}

bool planetShouldSpawn(struct planet* thisPlanet) {
	if (((int)(thisPlanet->timer) % PLANET_SPAWN_RATE) == 0) {
		thisPlanet->timer = 1;
		return true;
	}
}