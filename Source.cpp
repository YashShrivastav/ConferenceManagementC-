#include<iostream>
#include<vector>
#include<string>
#include"Tasks.h"
#include"Conference.h"
using namespace std;

int main()
{
	Conference conference = Conference();
	conference.ProcessTasksInput("TaskFile.txt");
	int totalTracks = conference.getCountTrack();
	int index = 0;
	for (int trackCount = 0; trackCount < totalTracks; trackCount++)
	{
		index = conference.ScheduleTalksIntoTracks(trackCount, conference.getTrackTasks(), conference.getCountTrack(), index, conference.getCountTasks());
	}
	conference.OutputOfTalksIntoTracks(conference.getTrackTasks());
}