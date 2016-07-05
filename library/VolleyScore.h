#ifndef VolleyScore_h
#define VolleyScore_h

#define POINT_TO_WIN 25
#define POINT_TO_WIN_SET_5 15

#include <Arduino.h>

class VolleyScore {
	public:
		void addPointTeam1();
		void addPointTeam2();
		void reset();
		bool needRefresh();
		int getPointTeam1();
		int getPointTeam2();
		int getTeam1WonGame();
		int getTeam2WonGame();
	private:
		int _team1Score = 0;
		int _team2Score = 0;
		int _team1SetWon = 0;
		int _team2SetWon = 0;
		bool _needRefresh;
		void resetScore();
		int pointToWin();
};	
#endif
