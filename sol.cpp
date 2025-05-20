// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
     

//      // using the brute force solution.

//      int count = 0;

//      for(int i = 0; i<arr.size(); i++){
//          int xr1 = arr[i];
//      for(int j = i+1; j<arr.size(); j++){
//            xr1 ^= arr[j];
//            int xr2 = arr[j];
//        for(int k = j; k<arr.size(); k++){
//           xr2  ^= arr[k];

//           if(xr1 == xr2 )count++;
//        }

//      }






//      }


//     return count;
//     }
// };



// optimal solution

class Solution {
    public:
        int countTriplets(std::vector<int>& arr) {
            int n = arr.size();
            std::vector<int> prefix(n + 1, 0);
    
            for (int i = 0; i < n; ++i) {
                prefix[i + 1] = prefix[i] ^ arr[i];
            }
    
            int count = 0;
            for (int i = 0; i < n; ++i) {
                for (int k = i + 1; k < n; ++k) {
                    if (prefix[i] == prefix[k + 1]) {
                        count += (k - i);
                    }
                }
            }
    
            return count;
        }
    };