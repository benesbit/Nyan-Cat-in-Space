#pragma once

#include "ofMain.h"

struct score * scoreConstruct(ofTrueTypeFont* thisFont);

void scoreDraw(struct score* thisScore);

void scoreIncrease(struct score* thisScore, int incAmount);

void scoreDecrease(struct score* thisScore, int decAmount);

void scoreSetZero(struct score* thisScore);

bool scoreIsNegative(struct score* thisScore);

void scoreStayCentered(struct score* thisScore);