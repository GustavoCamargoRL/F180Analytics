#pragma once

#include <iostream>

using namespace std;

class Finalization {
public:
	int kicksAtGoalTeamWhite;
	int kicksAtGoalTeamBlack;
	int kicksTeamWhite;
	int kicksTeamBlack;
	int goalsTeamWhite;
	int goalsTeamBlack;

	Finalization();

	int getKicksAtGoal(int team);
	int getKicks(int team);
	int getGoals(int team);
};
