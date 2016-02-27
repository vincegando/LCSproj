#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Formatter.h"

using namespace std;



int main(int argc, char *argv[]) {

    string isAll = "-all";

    int casesCounter = 0;
    int numCases;
    string line;
    string first;
    string second;
    int count;
    vector<Formatter> results;
    
    while(getline(cin,line)) {
    	count = 0;
    	string num;
    	istringstream iss(line);
    	while(iss >> num) {

    		count++;
    		    	
    	}
    	if (count == 1) {
	       numCases = stoi(num);
    	   continue;
    	}
    	if (count > 2) {
    			continue;
    	}


    	istringstream iss2(line);
    	iss2 >> first >> second;
    	if (!iss2) {
    		iss2.clear();
    		continue;
    	}

    	Formatter newResult(first, second);
    	results.push_back(newResult);
    	casesCounter++;
    	if (casesCounter == numCases) {
    		break;
    	}
    	
    }
    
    if (argc != 1 && argv[1] == isAll) {
    	cout << "all" << endl;
    }
    else {

    	for(int n = 0; n < results.size(); n++) {
   			results[n].LCS();
   		}
    }
	

	return 0;

}
