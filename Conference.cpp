#include "Conference.h"
#include "Tasks.h"
#include<iostream>
#include<algorithm>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>

using namespace std;


    int Conference::getTotalTrackMinutes() {
        return totalTrackMinutes;
    }

    void Conference::setTotalTrackMinutes(int totalTrackMinute) {
        totalTrackMinutes = totalTrackMinute;
    }

    int Conference::getCountTrack() {
        return countTrack;
    }

    void Conference::setCountTrack(int countTracks) {
        countTrack = countTracks;
    }

    int Conference::getCountTasks() {
        return countTasks;
    }
    vector<Tasks> Conference::getTrackTasks() {
        return trackTasks;
    }
    void Conference::setTrackTasks(vector<Tasks> trackTask) {
        trackTasks = trackTask;
    }


    void Conference::ProcessTasksInput(std::string fileName)
    {
        int id = 0;
        int noOfTracks = 0;
        int minutes;
        int totalMinutes = 0;
        std::string line;
        cout << "Test input :\n";


        fstream fs;
        fs.open(fileName.c_str(), ios::in);
        if (fs.is_open())
        {
            while (getline(fs, line))
            {
                id = id + 1;

                std::string title = line.substr(0, line.rfind(" "));
                stringstream forMins;
                forMins << line;
                string temp;
                while (!forMins.eof())
                {
                    forMins >> temp;
                    if (stringstream(temp) >> minutes)
                    {
                        totalMinutes += minutes;
                    }
                    Tasks singleTask = Tasks(minutes, title, id);
                    trackTasks.push_back(singleTask);
                }
                setCountTrack(id);
                setTotalTrackMinutes(totalMinutes);
                double totalMinsDouble = (double)totalMinutes;
                double numberOfTracks = (totalMinsDouble /  420);
                double fractionalPart =fmod(numberOfTracks, 1);
                double integralPart = numberOfTracks - fractionalPart;
                int leftMinutes = totalMinutes - 420;
                if (leftMinutes > 0)
                {
                    noOfTracks = (int)integralPart + 1;
                }
                else
                {
                    noOfTracks = (int)integralPart;
                }
                setCountTrack(noOfTracks);
                std::sort(trackTasks.begin(), trackTasks.end());
                fs.close();
            }
        }
        cout << endl << endl;
    }

    int Conference::ScheduleTalksIntoTracks(int trackCountIndex, vector<Tasks> trackTasks, int trackCount, int starttaskIndex, int totalTaskCount)
        {
            int morning = 180;
            int afternoon =240;
            int taskIndex;
            std::string sessionTime;
            std::string sessionTitle;
            std::string startTime = "09 : 00 AM";
            for (taskIndex = starttaskIndex; taskIndex < totalTaskCount; taskIndex++)
            {

                if (morning >= trackTasks.at(taskIndex).getMinutes())
                {
                    morning = morning - trackTasks.at(taskIndex).getMinutes();
                    sessionTime = startTime + " " + trackTasks.at(taskIndex).getTitle() + " " + std::to_string(trackTasks.at(taskIndex).getMinutes()) + "min";
                    trackTasks.at(taskIndex).setTitle(sessionTime);
                    startTime = addTime(startTime, trackTasks.at(taskIndex).getMinutes());
                    sessionTitle = "Track" + space + std::to_string(trackCountIndex + 1);
                    trackTasks.at(taskIndex).setTrackTitle(sessionTitle);
                }
                if (morning < trackTasks.at(taskIndex).getMinutes())
                    break;

                if (morning > 0)
                    continue;

                if (morning <= 0)
                    break;
            }
            trackTasks.at(taskIndex).setLunchFlag(true);
            sessionTime = "12 : 00 PM" + space + "Lunch";
            trackTasks.at(taskIndex).setLunchTitle(sessionTime);
            taskIndex++;
            startTime = "01 : 00 PM";
            for (; taskIndex < totalTaskCount; taskIndex++)
            {

                if (afternoon >= trackTasks.at(taskIndex).getMinutes())
                {
                    afternoon = afternoon - trackTasks.at(taskIndex).getMinutes();
                    sessionTime = startTime + " " + trackTasks.at(taskIndex).getTitle() + " " + std::to_string(trackTasks.at(taskIndex).getMinutes()) + "min";
                    trackTasks.at(taskIndex).setTitle(sessionTime);
                    startTime = addTime(startTime, trackTasks.at(taskIndex).getMinutes());
                    sessionTitle = "Track" + space + std::to_string(trackCountIndex + 1);
                    trackTasks.at(taskIndex).setTrackTitle(sessionTitle);
                }
                if (afternoon < trackTasks.at(taskIndex).getMinutes())
                    break;

                if (afternoon > 0)
                    continue;

                if (afternoon <= 0)
                    break;
            }

            if (totalTaskCount == (taskIndex))
                --taskIndex;
            trackTasks.at(taskIndex).setNetworkingFlag(true);
            sessionTime = "05 : 00 PM" + space + "Networking Event";
            trackTasks.at(taskIndex).setNetworkingTitle(sessionTime);

            taskIndex++;
            return taskIndex;
        }
        std::string Conference::addTime(std::string clock, int offset)
        {
            
            stringstream time;
            time << clock;
            int minutes = offset;
            std::string temp, hr, min, ampm;
            ampm = clock.substr(clock.length()-2);
            int num, hour, mins;
            int flag = 0;
            while (!time.eof())
            {
                time >> temp;
                if (stringstream(temp) >> num)
                {
                    if (flag == 0)
                    {
                        hour = num;
                        flag++;
                    }
                    else
                    {
                        mins = num;
                    }
                }
                temp = " ";

            }
            int result = mins + minutes;
            if (result > 59)
            {
                hour = hour + 1;
                result = result - 60;
            }
            if (hour < 10)
            {
                hr = "0" + std::to_string(hour);
            }
            else
            {
                hr = std::to_string(hour);
            }
            if (result < 10)
            {
                min = "0" + std::to_string(result);
            }
            else
            {
                min = std::to_string(result);
            }
            std::string str = hr + " : " + min + " " + ampm;
            return str;
        }
        void Conference::OutputOfTalksIntoTracks(vector<Tasks> trackTasks) {

            cout<<"Test Output :";
            cout<<"";
            std::string TrackTitle = "dummyValue";

            // Output the talks into tracks based on the totalTalks and the count of Talks.
            for (int trackCountIndex = 0; trackCountIndex < trackTasks.size(); trackCountIndex++)
            {

                // Print the Track Title
                if (!TrackTitle.compare(trackTasks.at(trackCountIndex).getTrackTitle()))
                {
                    cout<<trackTasks.at(trackCountIndex).getTrackTitle() + ":";
                    cout<<"";
                    TrackTitle = trackTasks.at(trackCountIndex).getTrackTitle();
                }

                // Print the prepared talk's title for this Track
                cout<<trackTasks.at(trackCountIndex).getTitle();

                // if lunch flag set then output the Lunch Title
                if (trackTasks.at(trackCountIndex).isLunchFlag())
                {
                    cout<<trackTasks.at(trackCountIndex).getLunchTitle();
                }

                // if networking flag set then output the Networking Title
                if (trackTasks.at(trackCountIndex).isNetworkingFlag())
                {
                    cout<<trackTasks.at(trackCountIndex).getNetworkingTitle();
                    // simple convention to display extra lines.
                    cout<<"";
                    cout<<"";
                }

            }
        }
