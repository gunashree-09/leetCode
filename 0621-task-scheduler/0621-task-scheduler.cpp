class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it:mp){
            pq.push(it.second);

        }
        int time=0;
        while(!pq.empty()){

            vector<int> temp;

            int cyc=n+1;
            int task=0;
            while(task<cyc && !pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                if(freq>0){
                    temp.push_back(freq);
                }
                time++;
                task++;

            }

            if(!temp.empty()){
                for(int it:temp){
                    pq.push(it);
                }
            }

            if(!pq.empty()){
                time+=cyc-task;
            }
        }
        return time;
    }
};