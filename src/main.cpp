// Term Project: NYAN TO THE RESCUE!
// Benjamin Nesbit
// OSU CS 161 2018
// Ex 17
// The latest changes are more internal and cannot be seen
// by the program user. I put a lot of timers and images
// INTO the structs themselves. This can be most noticed in
// my draw() section, where each funstion is only passed one 
// pointer.
// As of right now, pressing space increases the score,
// and pressing k will decrease the score.
// Use 'w' and 's' or the up and down arrow keys to 
// controll nyan cat.
// Press space to fire.
// Watch out for tacNyan and his blasts!
// Although there is no hit boxes, and the score does not
// correlate to any game, it is getting there!

#include "ofMain.h"
#include "ofApp.h"
#include "globals.h"

int main() {
	ofSetupOpenGL(WINDOW_WIDTH, WINDOW_HEIGHT, OF_WINDOW);
	ofApp *myApp = new ofApp();
	ofRunApp(new ofApp());
}
