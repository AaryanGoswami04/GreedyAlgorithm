/*Ishika got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.*/
//TC:O(1) SC:O(1)
class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sundays = S/7;
        int buying_days = S-sundays;
        int TotalFood = N*M;
        int ans=0;
        
        if(TotalFood%N == 0)  ans = TotalFood%N;
     
        else ans = TotalFood%N + 1;
        
        return ans <= buyingDays ? ans : -1;
    }
};
