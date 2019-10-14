#include "ArucoPlayer.h"

ArucoPlayer::ArucoPlayer(int pieceId) {
	id = pieceId;
	center.x = 0.0;
	center.y = 0.0;

	if (id >= 1 && id <= 6) {
		// peças brancas
		B = 255;
		G = 255;
		R = 255;
	}
	else if (id == 0)  // bola
	{
		B = 0;
		G = 0;
		R = 255;
	}
	else {
		//peças pretas
		B = 0;
		G = 0;
		R = 0;
	}
}

void ArucoPlayer::getCenterCoord(Point2f p1, Point2f p2) { // metodo para calcular as coordenadas centrais dos marcadores
	if (p1.x < p2.x) {								   // p1 = borda superior esquerda , p2= borda inferior direita, formando uma diagonal,
		center.x = p1.x + ((abs(p2.x - p1.x)) / 2);	   // que independente da rotação da peça irá identificar o centro corretamente
	}
	else {
		center.x = p2.x + ((abs(p2.x - p1.x)) / 2);
	}
	if (p1.y < p2.y) {
		center.y = p1.y + ((abs(p2.y - p1.y)) / 2);
	}
	else {
		center.y = p2.y + ((abs(p2.y - p1.y)) / 2);
	}
}