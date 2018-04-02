// ship.h

#pragma once
#include "ofMain.h"

struct ship * shipConstruct(float x, float y, float velocity,
							float acceleration, float width,
							float height, bool enemy,
							ofImage* thisImage);

void shipMove(struct ship* thisShip);

void shipEnemyMove(struct ship* thisShip, int* thisTimer);

void shipThrustUp(struct ship* thisShip);

void shipThrustDown(struct ship* thisShip);

void shipDraw(struct ship* thisShip);

void shipBounce(struct ship* thisShip);

bool shipIsAtEdge(struct ship* thisShip);

float shipGetX(struct ship* thisShip);

float shipGetY(struct ship* thisShip);

void shipPositionEnemyShip(struct ship* thisShip);