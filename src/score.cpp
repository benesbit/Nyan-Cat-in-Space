//score.cpp

#include "ofMain.h"
#include "ofApp.h"
#include "score.h"
#include "globals.h"

struct score {
	float x;
	float y;
	int currentScore;
	ofColor color;
	ofTrueTypeFont* scoreFont;
};

struct score * scoreConstruct(ofTrueTypeFont* thisFont) {
	// Allocate memory and get address of this memory
	struct score* thisScore = (struct score*)malloc(sizeof(struct score));
	thisScore->scoreFont = (ofTrueTypeFont*)malloc(sizeof(ofTrueTypeFont*));
	// Prep the score
	thisScore->x = (ofGetWidth() / 2)-100;
	thisScore->y = 50;
	thisScore->currentScore = 0;
	thisScore->color = ofColor(255);
	thisScore->scoreFont = thisFont;
	
	return thisScore;
}

void scoreDraw(struct score* thisScore) {
	ofSetColor(thisScore->color);
	thisScore->scoreFont->drawString("SCORE: " + ofToString(thisScore->currentScore), thisScore->x, thisScore->y);
}

void scoreIncrease(struct score* thisScore, int incAmount) {
	thisScore->currentScore += incAmount;
}

void scoreDecrease(struct score* thisScore, int decAmount) {
	thisScore->currentScore -= decAmount;
	if (scoreIsNegative(thisScore)) {
		scoreSetZero(thisScore);
	}
}

void scoreSetZero(struct score* thisScore) {
	thisScore->currentScore = 0;
}

bool scoreIsNegative(struct score* thisScore) {
	return ((thisScore->currentScore) < 0);
}

void scoreStayCentered(struct score* thisScore) {
	thisScore->x = (ofGetWidth() / 2) - 100;
}