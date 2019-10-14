#pragma once

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace cv;

class VideoSave {
public:
	Mat frame;
	VideoCapture video;
	double timeStart;  //tempo inicial da partida
	double time;		//tempo atual da partida
	double whiteTime;	//tempo de jogo do jogador Branco
	double whiteTimeAux;	//auxiliar de tempo Branco
	double blackTime;		//tempo de jogo do jogador Preto
	double blackTimeAux;	//auxiliar de tempo Preto
	double timeAssist;		//tempo inicial relativo a cada turno
	int team;				//flag para indicar de que jogador o turno pertence
	int idSource;		//id da fonte 1 -> webcam externa, 0 -> webcam interna
	bool endGame;		//flag para fim de jogo


	VideoSave(int source);
	void getFrame();										//Captura um frame do video, e ao final da partida fecha a webcam
	void startTimer();										//inicia o timer da partida
	void timeAssistance();									//atualiza o tempo auxiliar de cada time
	void updateTimer(int team);								//atualiza o timer
	void printTimer(Mat& frame);							//imprime na tela o tempo da partida em tempo real


};