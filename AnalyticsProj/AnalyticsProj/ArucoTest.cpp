#include "ArucoTest.h"
#include "BallPossetion.h"


ArucoMarkers::ArucoMarkers() {
	//escolhe marcadores de tamanho 4x4 pixels de acordo com a biblioteca
	markerDictionary = aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);

}

void ArucoMarkers::createArucoMarkers() {
	Mat outputMarker;				//Matriz na qual os marcadores serão criados

	for (int i = 0; i < 13; i++) {  // criando 12 marcadores para servir como exemplos de jogadores
		aruco::drawMarker(markerDictionary, i, 125, outputMarker, 1); //Gera os marcadores com 125x125 pixels
		ostringstream convert;
		string imageName = "4x4Marker_";
		convert << imageName << i << ".jpg"; //salva o arquivo como uma imagem .jpg
		imwrite(convert.str(), outputMarker);

	}
}

int ArucoMarkers::detectAruco(Mat& currentFrame, vector<ArucoPlayer>& allArucoPlayers, bool gameStart) {
	Point2f center;
	Point2f ballCenter;
	BallPossetion ball;
	int teamBall = 0;
	bool ballInGame = false;
	// Detecta todos os marcadores que estão na imagem atual de acordo com o dicionario escolhido, guardando as posicoes corners e o id de cada marcador
	aruco::detectMarkers(currentFrame, markerDictionary, corners, ids);

	

	if (ids.size() > 0) {	
		for (int i = 0; i < ids.size(); i++) {												//Detecta a bola em jogo e salva sua posicao
			if (allArucoPlayers[ids[i]].id == 0) {
				ballInGame = true;
				if (corners[i][0].x < corners[i][2].x) {
					ballCenter.x = corners[i][0].x + ((abs(corners[i][2].x - corners[i][0].x)) / 2);
				}
				else {
					ballCenter.x = corners[i][2].x + ((abs(corners[i][2].x - corners[i][0].x)) / 2);
				}
				if (corners[i][0].y < corners[i][2].y) {
					ballCenter.y = corners[i][0].y + ((abs(corners[i][2].y - corners[i][0].y)) / 2);
				}
				else {
					ballCenter.y = corners[i][2].y + ((abs(corners[i][2].y - corners[i][0].y)) / 2);
				}
				ball.ballPosAtt(ballCenter);
				//std::cout << "bola em campo" << std::endl;
			}
			/*if (allArucoPlayers[ids[i]].id >= 1 && allArucoPlayers[ids[i]].id < 7) {
				std::cout << "Time branco em campo" << std::endl;
			}
			if (allArucoPlayers[ids[i]].id >= 7) {
				std::cout << "Time preto em campo" << std::endl;
			}*/
		}
		bool foundBall = false;
		for (int i = 0; i < ids.size(); i++) {													//detecta os jogadores em campo e checa sua posse de bola
			//localização do centro da peça para escrita do nome e identificação do time
			if (corners[i][0].x < corners[i][2].x) {
				center.x = corners[i][0].x + ((abs(corners[i][2].x - corners[i][0].x)) / 2);
			}
			else {
				center.x = corners[i][2].x + ((abs(corners[i][2].x - corners[i][0].x)) / 2);
			}
			if (corners[i][0].y < corners[i][2].y) {
				center.y = corners[i][0].y + ((abs(corners[i][2].y - corners[i][0].y)) / 2);
			}
			else {
				center.y = corners[i][2].y + ((abs(corners[i][2].y - corners[i][0].y)) / 2);
			}
			// desenha um circulo no marcador indicando o time branco ou preto 
			circle(currentFrame, center, 22, Scalar(allArucoPlayers[ids[i]].B, allArucoPlayers[ids[i]].G, allArucoPlayers[ids[i]].R), -2, LINE_AA, 0);
			if (!foundBall) {     // checa se ja encontrou a posse de bola
				teamBall = ball.getBallPossetion(center, allArucoPlayers[ids[i]].id);
				if (teamBall != 0) {
					foundBall = true;
				}
			}
			//encontra o centro do marcador a partir de 2 pontos "em diagonais"
			allArucoPlayers[ids[i]].getCenterCoord(corners[i][0], corners[i][2]);

		}
	}
	return teamBall;
}