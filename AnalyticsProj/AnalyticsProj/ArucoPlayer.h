#pragma once

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;


class ArucoPlayer {
public:
	int id, B, G, R;  //identificador, valor de azul, verde e vermelho (a fim de identificar os times)
	Point2f center;	  //Coordenadas do centro do marcador
	vector<Point2f> pieceMovesPoints;	//Salva os movimentos das pe�as

	ArucoPlayer(int id);
	void getCenterCoord(Point2f p1, Point2f p2);  //c�lculo da coordenada central atual da pe�a
};