#pragma once
#include "Tasks.h"
#include<vector>
#include<string>


class Conference
{
private:
    std::vector<Tasks> trackTasks;
    int totalTrackMinutes;
    int countTrack;
    int countTasks;
    std::string space = " ";


	
public:
    int getTotalTrackMinutes();

    void setTotalTrackMinutes(int totalTrackMinute);

    int getCountTrack();

    void setCountTrack(int countTracks);

    int getCountTasks();

    void setCountTasks(int countTask);

    std::vector<Tasks> getTrackTasks();

    void setTrackTasks(std::vector<Tasks> trackTask);
	
	void ProcessTasksInput(std::string fileName);
	int ScheduleTalksIntoTracks(int trackCountIndex, std::vector<Tasks> trackTasks, int trackCount, int starttaskIndex, int totalTaskCount);
	std::string addTime(std::string time, int offset);
    void OutputOfTalksIntoTracks(std::vector<Tasks> trackTasks);
};

