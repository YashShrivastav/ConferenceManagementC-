#include "Tasks.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


	Tasks::Tasks(int minute, string titles, int ids)
	{
		minutes = minute;
		title = titles;
		id = ids;

	}

	int Tasks::getMinutes() {
		return minutes;
	}
	void Tasks::setMinutes(int minute) {
		minutes = minutes;
	}
	std::string Tasks::getTitle() {
		return title;
	}
	void Tasks::setTitle(std::string titles) {
		title = title;
	}
	int Tasks::getId() {
		return id;
	}
	void Tasks::setId(int ids) {
		id = id;
	}
	std::string Tasks::getSessionTime() {
		return sessionTime;
	}
	void Tasks::setSessionTime(std::string sessionsTime) {
		sessionTime = sessionsTime;
	}

	std::string Tasks::getLunchTitle() {
		return lunchTitle;
	}
	void Tasks::setLunchTitle(std::string lunchsTitle) {
		lunchTitle = lunchsTitle;
	}
	bool Tasks::isLunchFlag() {
		return lunchFlag;
	}
	void Tasks::setLunchFlag(bool lunchsFlag) {
		lunchFlag = lunchsFlag;
	}
	std::string Tasks::getNetworkingTitle() {
		return networkingTitle;
	}
	void Tasks::Tasks::setNetworkingTitle(std::string networkTitle) {
		networkingTitle = networkingTitle;
	}
	bool Tasks::Tasks::isNetworkingFlag() {
		return networkingFlag;
	}
	void Tasks::setNetworkingFlag(bool networkFlag) {
		networkingFlag = networkFlag;
	}

	std::string Tasks::getTrackTitle() {
		return trackTitle;
	}
	void Tasks::setTrackTitle(std::string trackTitles) {
		trackTitle = trackTitles;
	}


	bool Tasks::operator < (const Tasks& obj)
	{
		return minutes < obj.minutes;
	}