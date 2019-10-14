#include "BallPossetion.h"
#include "TimeStatus.h"

BallPossetion::BallPossetion() {
	this->ballPosition.x = 0;
	this->ballPosition.y = 0;
	this->teamBlackTime = 0;
	this->teamWhiteTime = 0;
	this->totalTime = 0;
	this->fractionBlackTime = 0;
	this->fractionWhiteTime = 0;
	this->totalFraction = 0;
}

void BallPossetion::ballPosAtt(Point2f ballcoord){

	ballPosition = ballcoord;

}

int BallPossetion::getBallPossetion(Point2f playerCoord, int playerID) {
	if (abs(playerCoord.x - ballPosition.x) + abs(playerCoord.y - ballPosition.y) <= 50) {
		if (playerID >= 7) {
			return 2;
		}
		else if (playerID > 0 && playerID <=6){
			return 1;
		}
		else {
			return 0;
		}
	}
}

void BallPossetion::attTime(double Total, double whiteTime, double blackTime) {
	this->totalTime = Total;
	this->teamWhiteTime = whiteTime;
	this->teamBlackTime = blackTime;
	this->totalFraction = this->teamBlackTime + this->teamWhiteTime;
	this->fractionBlackTime = (100 * blackTime) / totalFraction;
	//this->fractionWhiteTime = (100 * whiteTime) / totalFraction;
	this->fractionWhiteTime = abs(this->fractionBlackTime - 100);

}
