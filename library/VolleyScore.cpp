#include "VolleyScore.h"

#define NUMPIXELS      192

void VolleyScore::addPointTeam1() {
  _team1Score++;
  if (_team1Score > POINT_TO_WIN && (_team1Score - 2) > _team2Score) {
	  _team1GameWin++;
	  resetScore();
  }
  _needRefresh = true;
}

void VolleyScore::addPointTeam2() {
  _team2Score++;
  if (_team2Score > POINT_TO_WIN && (_team2Score - 2) > _team1Score) {
	  _team2GameWin++;
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
	_team1GameWin = 0;
	_team2GameWin = 0;
	_needRefresh = true;
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
int VolleyScore::getTeam1WinnedGame() {
	return _team1GameWin;
}
int VolleyScore::getTeam2WinnedGame() {
	return _team2GameWin;
}
