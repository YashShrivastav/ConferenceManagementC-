#pragma once
#include<vector>
#include<string>
class Tasks
{
private:

	int minutes;
	std::string title;
	int id;
	bool lunchFlag = false;
	std::string networkingTitle;
	bool networkingFlag = false;
	std::string sessionTime;
	std::string lunchTitle;
	std::string trackTitle;

public:
	//constructors=
	Tasks(int minutes, std::string title, int id);


	//setter and getter
	int getMinutes();

	void setMinutes(int minute);

	std::string getTitle();

	void setTitle(std::string titles);

	int getId();

	void setId(int ids);

	std::string getSessionTime();

	void setSessionTime(std::string sessionsTime);

	std::string getLunchTitle();

	void setLunchTitle(std::string lunchsTitle);

	bool isLunchFlag();

	void setLunchFlag(bool lunchsFlag);

	std::string getNetworkingTitle();

	void setNetworkingTitle(std::string networkTitle);

	bool isNetworkingFlag();

	void setNetworkingFlag(bool networkFlag);

	std::string getTrackTitle();

	void setTrackTitle(std::string trackTitles);

	//operator overloading
	bool operator < (const Tasks& Obj);

};

