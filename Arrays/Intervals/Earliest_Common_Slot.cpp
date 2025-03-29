//Simple approach-> suppose i is pointing slots in slot1 and j is pointing slots in slot2. Now if we can't find any common time b/w these two slots, we need to leave them. But which one to leave. We will leave that 
//slot which is fully completed. Suppose the end time of slot i < start time of slot j. So till the time slot 2 starts, slot 1 is already done. Now next in the slot of slot 2 will be greater than the current slot 2.
//so obviously there won't be any match. But slot j is still left, so there might be chances that the next slot in slot 1 might have a match desired with this slot. So we will not move slot j. we will only more i. 
//Similarly goes other way around. 

//Now if there is a common time between the two slots, then check the common time and compare it with the d required. If ok return. Else move from the slot completed. Let's understand this. Which slot is completed and
// what is the common time? It is the difference b/w max_start_time and min_end_time right and the slot with the end time as min_end_time has actually ended. So move from that slot and stay on incompleted slot. Simple
// if both are equal to min_end_time, means both are done, so i++ and j++ simultaneously. Hope this make sense. If not please write your queries in the comments. I will try to resolve them. Thank you for your time.
// Here is the code
class Solution {
  public:
    vector<int> commonSlot(vector<vector<int>> &a, vector<vector<int>> &b, int d) {
        // Code Here
        int n=a.size(), m=b.size();
        int i=0, j=0;
        
        while(i<n && j<m){
            // when slot1 end time is less than slot2 start time
            if(a[i][1]<b[j][0]) i++;
            
            else if(a[i][0]>b[j][1]) j++;
            
            else{
                int max_start_time=max(a[i][0],b[j][0]);
                int min_end_time=min(a[i][1],b[j][1]);
                
                if(min_end_time-max_start_time>=d) return {max_start_time, max_start_time+d};
                
                if(a[i][1]==min_end_time) i++;
                else if(b[j][1]==min_end_time) j++;
                else {
                    i++;
                    j++;
                }
            }
        }
        
        return {};
    }
};
