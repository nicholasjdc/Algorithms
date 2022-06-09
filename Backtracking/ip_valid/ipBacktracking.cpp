#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool secIsValid(string ipSection){
    int ipVal = stoi(ipSection);

    if (ipSection[0] == '0' || ipVal > 256) return false;
    else return true;
}

vector<string> ipSeparator(string ipUnsorted, int length, int index=0, 
                            int numSectionsLeft=4){
    
    int maxSegSize = 3;
    string currSec = "";
    vector<string> validIpAdds ={};

    if(numSectionsLeft == 1){
      
        string lastIpSec = ipUnsorted.substr(index);
        if(secIsValid(lastIpSec)){
            validIpAdds.push_back(ipUnsorted);
        }

    }else{
        for(int i=0; i<maxSegSize; i++){

            if(length - index- i < numSectionsLeft) break;
            currSec = ipUnsorted.substr(index, i+1);
        

            if(secIsValid(currSec)){
                string newIp (ipUnsorted);
                vector<string> validBranchIps = ipSeparator(newIp.insert(index+i+1, "."), length+1,index+i+2, numSectionsLeft-1);
                validIpAdds.insert(validIpAdds.end(), validBranchIps.begin(), validBranchIps.end());
            } 
        }
    }

    return validIpAdds;

    //Limiting factors:
    //Minimum of 1 number for each of the 4 sections
    //No starting w/ 0
    // Must be less than 256, max 3 digits


}

int main(){
string unsortedIp;
int input;

cout<< "Type Unsorted Ip Address: ";
cin>> input;

unsortedIp = to_string(input);

vector<string> validIps = ipSeparator(unsortedIp, unsortedIp.length());

for(string s: validIps) cout<<s<<endl;
}