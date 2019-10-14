// Software de analises de jogos de futebol F180

#include "ArucoPlayer.h"
#include "ArucoTest.h"
#include "TimeStatus.h"
#include "BallPossetion.h"



using namespace cv;
using namespace std;

int main(int argv, char** argc)
{
	bool gameStart = false;		//flag para inicio de partida
	int team = 0;
	int BallTeam = 0;
	bool changeBallTeam = false;
	Point2f ballInitial;
	ballInitial.x = 0;
	ballInitial.y = 0;
	//double t_assist;
	ArucoMarkers markers = ArucoMarkers();
	//markers.createArucoMarkers();		//cria os marcadores para serem impressos
	BallPossetion ball = BallPossetion();
	//inicializa os jogadores, salvando cada um no vetor abaixo
	vector<ArucoPlayer> ArucoPlayers;
	for (int i = 0; i < 13; i++) {
		ArucoPlayers.push_back(ArucoPlayer(i));
	}

	//inicializa a captura da imagem da webcam externa(source = 1)
	VideoSave video = VideoSave(0);
	Mat frameInitial;

	while (!video.endGame) {
		video.getFrame(); // salva uma imagem
		char key = (char)waitKey(30);


		if (!gameStart) {
			if (key == 105) {  //apertar a tecla i para iniciar a partida
				video.startTimer(); //inicia o tempo de partida
				team = markers.detectAruco(video.frame, ArucoPlayers, gameStart); //detecta as peças de xadrez para a captura das posições iniciais
				//video.frame.copyTo(frameInitial);  //captura o frame inicial da partida com as posições iniciais das peças """futuro heat map"""
				gameStart = true;		  		   //flag para inicio de jogo
			}
		}
		else {
			video.updateTimer(team);  // atualiza o tempo de partida
		}
		team = markers.detectAruco(video.frame, ArucoPlayers, gameStart); // detecta os marcadores na imagem e os identifica com os respectivos nomes e times das peças
		if (team != BallTeam) {
			if (team == 1 && (BallTeam == 2 || BallTeam == 0)) {
				changeBallTeam = true;
				BallTeam = team;
			}
			else if (team == 2 && (BallTeam == 1 || BallTeam == 0)) {
				changeBallTeam = true;
				BallTeam = team;
			}

		}
		if (changeBallTeam) {
			video.timeAssistance();
			changeBallTeam = false;
		}
		ball.attTime(video.time, video.whiteTime, video.blackTime);
		std::cout << ball.fractionBlackTime << "   " << ball.fractionWhiteTime << std::endl;
		video.printTimer(video.frame);
		imshow("Webcam", video.frame);		//retorna o feedback da partida
		if (key == 102) {	//apertar a tecla f para finalizar a partida
			video.endGame = true;
			//video.gameOver(frameInitial, ArucoPlayers);
			break;
		}
	}
	return 0;
}