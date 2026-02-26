class Solution {
public:
    
    int romanToInt(string s) {
        
        unordered_map<string, int> values = {
            {"I",1},{"V",5},{"X",10},{"L",50},
            {"C",100},{"D",500},{"M",1000},
            {"IV",4},{"IX",9},{"XL",40},
            {"XC",90},{"CD",400},{"CM",900}
        };

        int sum = 0;
        int i = 0;

        while (i < s.length()){
            
            if (i < s.length()-1){
                string twoSymbols = s.substr(i,2);
                if(values.count(twoSymbols)){
                    sum += values[twoSymbols];
                    i += 2;
                    continue;
                }
            }

            string oneSymbol = s.substr(i,1);
            sum += values[oneSymbol];
            i += 1;
        }

        return sum;
    }
};