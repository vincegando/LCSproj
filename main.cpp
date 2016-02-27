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
    
    while(getline(cin,line)) {      //get every line from standard input
    	count = 0;
    	string num;
    	istringstream iss(line);
    	while(iss >> num) {

    		count++;            // keep a count of how many strings are on a line
    		    	
    	}
    	if (count == 1) {
	       numCases = stoi(num);
    	   continue;
    	}
    	if (count > 2) {
    			continue;
    	}


    	istringstream iss2(line);
    	iss2 >> first >> second;          //split lines with two inputs into two variables
    	if (!iss2) {
    		iss2.clear();
    		continue;
    	}

    	Formatter newResult(first, second);    //add each pair of inputs into a class
    	results.push_back(newResult);          // then add them into a vector
    	casesCounter++;
    	if (casesCounter == numCases) {         //if the count of lines = number of testcases, stop this loop
    		break;
    	}
    	
    }
    
    if (argc != 1 && argv[1] == isAll) {
    	
        for(int i = 0; i < results.size(); i++) {   //print out all indices
            results[i].LCSallHelper();
        }
    }
    else {

    	for(int n = 0; n < results.size(); n++) {
   			results[n].LCS();                       // print out LCS length and string
   		}
    }
	

	return 0;

}
