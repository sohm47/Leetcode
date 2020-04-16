class UndergroundSystem {
    unordered_map<int, pair<string, int>> cache1; 
    unordered_map<string, pair<int, double>> averageTime;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cache1[id]= {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> station = cache1[id];
        averageTime[cache1[id].first + "+" + stationName].first += t-cache1[id].second;
        averageTime[station.first + "+" + stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return averageTime[startStation + "+" + endStation].first/averageTime[startStation + "+" + endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
