#pragma once

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

class BallPossetion {
public:
	double teamWhiteTime;
	double teamBlackTime;
	double totalTime;
	int fractionWhiteTime;
	int fractionBlackTime;
	double totalFraction;
	Point2f ballPosition;

	BallPossetion();
	void ballPosAtt(Point2f ballcoord);                             //atualiza posicao da bola
	int getBallPossetion(Point2f playerCoord, int playerID);		//verifica a posse de bola
	void attTime(double totalTime, double whiteTime, double blackTime);
};
