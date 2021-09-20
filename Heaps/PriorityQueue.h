#include<vector>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    public:
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size(); 
    }

    int getMin(){
        if(isEmpty()){
            return -1;
        }
        return pq[0];
    }

    void insert(int x){
        pq.push_back(x);
        int index = pq.size()-1;
        while((index-1)/2 >=0 && pq[index] < pq[(index-1)/2]){
            swap(pq[index],pq[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    int removeMin(){
        if(isEmpty()){
            return -1;                                           
        }
        int x = pq[0];       
        int t = pq[pq.size()-1];
        pq.pop_back();
        pq[0] = t;
        int index = 0;
        int left = 2*index +1;
        int right = 2*index +2;
        while(left < pq.size()){
            int minIndex = index;
            if(pq[minIndex] >  pq[left]){
                minIndex = left;
            }
            if(right < pq.size() && pq[right] < pq[minIndex]){
                minIndex = right;
            }
            if(index == minIndex){
                break;
            }
            swap(pq[minIndex],pq[index]);

            index = minIndex;
             left = 2*index +1;
            right = 2*index +2;
        }
        return x;
    }
    
};