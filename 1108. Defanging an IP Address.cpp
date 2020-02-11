class Solution {
public:
    string defangIPaddr(string address) {
        string ret = "";
        for(int i=0; i<address.length(); i++) {
            if(address[i] != '.')
                ret += address[i];
            else
                ret += "[.]";
        }
        
        return ret;
    }
};
