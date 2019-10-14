#pragma once

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/aruco.hpp"
#include "TimeStatus.h"
#include "ArucoPlayer.h"
#include <iostream>

using namespace std;
using namespace cv;


class ArucoMarkers {
public:
	Ptr<aruco::Dictionary> markerDictionary;	//Salva o dicionario utilizado para os marcadores
	vector<vector<Point2f>> corners;			//Guarda a posição de cada quina dos marcadores
	vector<int> ids;							//Guarda o id dos marcadores identificados
	bool ballTeam1;								//flag para posse de bola time 1
	bool ballTeam2;								//flag para posse de bola time 2

	ArucoMarkers();
	void createArucoMarkers();			// Cria os marcadores e salva na extenção .jpg
	int detectAruco(Mat& currentFrame, vector<ArucoPlayer>& allArucoPlayers, bool gameStart); //Detecta os marcadores, desenhando um circulo preenchido centralizado
																							//junto com o nome da peça de acordo com seu id
																							//quando o jogo começar, passa a salvar as movimentações das peças
};
