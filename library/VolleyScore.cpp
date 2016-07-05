#include "VolleyScore.h"

#define NUMPIXELS      192

void VolleyScore::addPointTeam1() {
  _team1Score++;
  if (_team1Score > pointToWin() && (_team1Score - 2) > _team2Score) {
	  _team1SetWon++;
	  resetScore();
  }
  _needRefresh = true;
}

void VolleyScore::addPointTeam2() {
  _team2Score++;
  if (_team2Score > pointToWin() && (_team2Score - 2) > _team1Score) {
	  _team2SetWon++;
	  resetScore();
  }
  _needRefresh = true;
}

void VolleyScore::resetScore() {
	_team1Score = 0;
	_team2Score = 0;
}

void VolleyScore::reset() {
	_team1Score = 0;
	_team2Score = 0;
	_team1SetWon = 0;
	_team2SetWon = 0;
	_needRefresh = true;
}

int VolleyScore::pointToWin() {
    if ((2 == _team1Score) && (2 == _team2Score)) {
        return POINT_TO_WIN_SET_5;
    }
    return POINT_TO_WIN;
}

bool VolleyScore::needRefresh() {
	bool tempNeed = _needRefresh;
	_needRefresh = false;
	return tempNeed;
}

int VolleyScore::getPointTeam1() {
	return _team1Score;
}
int VolleyScore::getPointTeam2() {
	return _team2Score;
}
int VolleyScore::getTeam1WonGame() {
	return _team1SetWon;
}
int VolleyScore::getTeam2WonGame() {
	return _team2SetWon;
}
