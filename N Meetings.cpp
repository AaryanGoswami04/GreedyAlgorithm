/*There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.*/
public:
    //TC:P(N log N)
    //SC:O(N)
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({end[i], start[i]});
        }
        
        sort(v.begin(), v.end()); //sort based on end times
        
        int cnt=1;
        int curr_end = v[0].first;
        
        for(int i=1; i<n; i++){
            if(v[i].second > curr_end){ //v[i].second stores starting time of next meeting
                cnt++;
                curr_end = v[i].first;
            }
        }
        
        return cnt;
    }
