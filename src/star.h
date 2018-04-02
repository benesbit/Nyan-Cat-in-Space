// stars.h

#pragma once

struct star * starConstruct();

struct star ** starsConstruct();

void starSetRandomColor(struct star* thisStar);

void starSetSpeed(struct star* thisStar);

void starSetRadius(struct star* thisStar);

void starDraw(struct star* thisStar);

void starMove(struct star* thisStar);

void starStayInbounds(struct star* thisStar);

void starDrawField(struct star* thisField[]);

void starMoveField(struct star* thisField[]);