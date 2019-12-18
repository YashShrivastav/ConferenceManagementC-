# ConferenceManagementC++

You have recieved multiple talks request and that to be organised in a conference. Here are eight rules to oragnise talks in this conference :

1. The conference has multiple tracks each of which has a morning and afternoon session.
2. Each session contains multiple talks.
3. Morning sessions begin at 9am and must finish by 12 noon, for lunch.
4. Afternoon sessions begin at 1pm and must finish in time for the networking event.
5. The networking event can start no earlier than 4:00 and no later than 5:00.
6. No talk title has numbers in it.
7. All talk lengths are either in minutes (not hours) or lightning (5 minutes).
8. Presenters will be very punctual; there needs to be no gap between sessions.
This Java program receives below Test Input and apply the above eight rules, and produce an output to schedule talks in that conference
Test input:
Writing Fast Tests Against Enterprise Rails 60min

Overdoing it in Python 45min

Lua for the Masses 30min

Ruby Errors from Mismatched Gem Versions 45min

Common Ruby Errors 45min

Rails for Python Developers lightning

Communicating Over Distance 60min

Accounting-Driven Development 45min

Woah 30min

Sit Down and Write 30min

Pair Programming vs Noise 45min

Rails Magic 60min

Ruby on Rails: Why We Should Move On 60min

Clojure Ate Scala (on my project) 45min

Programming in the Boondocks of Seattle 30min

Ruby vs. Clojure for Back-End Development 30min

Ruby on Rails Legacy App Maintenance 60min

A World Without HackerNews 30min

User Interface CSS in Rails Apps 30min

Test output:
Track 1:
09:00AM Writing Fast Tests Against Enterprise Rails 60min

10:00AM Overdoing it in Python 45min

10:45AM Lua for the Masses 30min

11:15AM Ruby Errors from Mismatched Gem Versions 45min

12:00PM Lunch

01:00PM Ruby on Rails: Why We Should Move On 60min

02:00PM Common Ruby Errors 45min

02:45PM Pair Programming vs Noise 45min

03:30PM Programming in the Boondocks of Seattle 30min

04:00PM Ruby vs. Clojure for Back-End Development 30min

04:30PM User Interface CSS in Rails Apps 30min

05:00PM Networking Event

Track 2:
09:00AM Communicating Over Distance 60min

10:00AM Rails Magic 60min

11:00AM Woah 30min

11:30AM Sit Down and Write 30min

12:00PM Lunch

01:00PM Accounting-Driven Development 45min

01:45PM Clojure Ate Scala (on my project) 45min

02:30PM A World Without HackerNews 30min

03:00PM Ruby on Rails Legacy App Maintenance 60min

04:00PM Rails for Python Developers lightning

05:00PM Networking Event

Conference Track Management Solutions
There could be various ways to design the solution of this problem. One of the possible approach as used in bin packing problem.In the bin packing problem, "objects of different volumes must be packed into a finite number of bins or containers each of volume V in a way that minimizes the number of bins used". Lets have a real example of this: Suppose you have to pack items based on the baggage allowance permitted by the international/national airlines. It’s like you are allowed to have four bags A,B,C,D with a max capacity of each bag is 40 KG. You have N items to pack, those N items are with different size and shapes. Lets say you have one item with weight 1 KG and another Item with a weight of 5 KG and so on. You need to devise a strategy so that optimal steps could be performed to fill the bags under the permitted limits or reduce the number of bags.

This following solution uses a heuristic approach to provide one approximate solution:

Step-1: Calculate No. Of Tracks Needed It extracts the following input from the given input information: It calculates the total no. of minutes available for talk on each track (180 minutes for morning session and 240 minutes for afternoon session). Total no. of minutes of talks needed to be schedule on these tracks. It calculates that how many morning and afternoon session required. Based on the above it calculates the no. of tracks.

Step-2: Sort All The Talks in Decending Order- It sorts all the talks in descending ordered based on the given talks timings.

Step-3: Schedule In A Track- It picks talk one by one and schedule in a track and put into the Morning session or afternoon session without caring the left empty minutes in morning or afternoon session.

Step-4: Pics All The Talks Which Are Now With The Assoicated Track No- It picks all the talks which are now with the associated track no. , its scheduled time and other relevant information. It processes that information and output as a solution.

Step-5: Add Rules To Re-evaluate The Schedule Of Talks Into Tracks- TBD Add rules to re-evaluate the Schedule of Talks into Tracks e.g. If on evaluation its found that on Track-1 have 30 free minutes and on Track-2 have 45 free minutes, and one talk of 60 minutes need to schedule. It can shuffle 30 mins talks (if possible) from Track-1 to Track-2 , and accommodate this 60 mins talk to track-1,only varieties of input will provide right sense and this solution will improve.

The above solution designed based on the given talks input set and various other parameters (e.g. missing information). Initially it design the appropriate conference schedule based on the given talks input, and continuously add the rules based on the received further inputs. It checks the received input patterns and optimizes the solution.
