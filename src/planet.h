// planet.h

#pragma once
#include "ofMain.h"

struct planet * planetConstruct(ofImage* thisPlanetImages[]);

void planetDraw(struct planet* thisPlanet);

void planetMovePlanet(struct planet* thisPlanet);

void planetStayInbounds(struct planet* thisPlanet);

void planetChangePlanet(struct planet* thisPlanet);

bool planetOnScreen(struct planet* thisPlanet);

bool planetShouldSpawn(struct planet* thisPlanet);

void planetDetermineSpawn(struct planet* thisPlanet);