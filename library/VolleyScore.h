#ifndef VolleyScore_h
#define VolleyScore_h

#define POINT_TO_WIN 25

#include <Arduino.h>

class VolleyScore {
	public:
		void addPointTeam1();
		void addPointTeam2();
		void reset();
		bool needRefresh();
		int getPointTeam1();
		int getPointTeam2();
		int getTeam1WinnedGame();
		int getTeam2WinnedGame();
	private:
		int _team1Score = 0;
		int _team2Score = 0;
		int _team1GameWin = 0;
		int _team2GameWin = 0;
		bool _needRefresh;
		void resetScore();
};	
#endif
