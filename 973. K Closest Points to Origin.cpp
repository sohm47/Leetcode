class Solution {
    bool found;
    int partition(vector<vector<int>>& points, int low, int high) {
        int pivotTotal = points[high][0]*points[high][0]+points[high][1]*points[high][1]; 
        int i=low;
        
        for(int j=low; j<high; j++) {
            if(points[j][0]*points[j][0]+points[j][1]*points[j][1] < pivotTotal) {
                swap(points[i++], points[j]);
            }
        }
        
        swap(points[i], points[high]);
        return i;
    }
    
    void quickSort(vector<vector<int>>& points, int &K, int low, int high) {
        if(low<high && !found) {
            
            int pivot = partition(points, low, high);
            if(pivot == K) {
                found = true;
                return;
            }
            else if(K<pivot && !found) {
                quickSort(points, K, low, pivot-1);
            }
            else if (!found) {
                quickSort(points, K, pivot+1, high);
            }
        }
    }
    
public: 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        found = false;
        quickSort(points, K, 0, points.size()-1);
        vector<vector<int>> ret;
        for(int i=0; i<K; i++)
            ret.push_back(points[i]);
            
        return ret;
    }
};
