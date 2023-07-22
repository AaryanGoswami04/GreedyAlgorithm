/*Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. */
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item> a, pair<double,Item> b){
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>> v;
        
        for(int i=0; i<n; i++){
            double perUnitVal = (double) arr[i].value/arr[i].weight;
            v.push_back({perUnitVal,arr[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        double ans=0.0;
        for(int i=0; i<n; i++){
            if(v[i].second.weight > W){
                ans += W*v[i].first;
                break;
            }
            else{
                ans += v[i].second.value;
                W = W-v[i].second.weight;
            }
        }
        
        return ans;
    }
