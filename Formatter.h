#include <string>
#include <vector>
#include "IndexPair.h"
using namespace std;

#ifndef Formatter_h
#define Formatter_h

//class that holds input strings and executes LCS algorithms

class Formatter {
	
private:
	//int len;
	//string subseq;
	string a;
	string b;
	
public:
	vector<IndexPair> tuples;      //holds the LCS tuples for ALL
	

	Formatter(string _a, string _b) {
		a = _a;
		b = _b;
	}
	void setA(string in) {
		a = in;
	}
	void setB(string in) {
		b = in;
	}
	string getA() {
		return a;
	}
	string getB() {
		return b;
	}

	int max(int a, int b) {           //return max function
	if (a > b)
		return a;
	else 
		return b;
	}

	void LCS(){

		int aLength = a.length();
		int bLength = b.length();
		int X[aLength + 1][bLength + 1];

		for(int q = 0; q <= aLength; q++) {
			X[q][0] = 0;
		}
		for(int w = 0; w <= bLength; w++) {
			X[0][w] = 0;
		}
		for(int i = 1; i <= aLength; i++) {
			for(int j = 1; j <= bLength; j++) {
			
				if(a[i - 1] == b[j - 1]) {
					X[i][j] = X[i - 1][j - 1] + 1;       
				}
				else {                                        //generating table for LCS
					X[i][j] = max(X[i - 1][j] , X[i][j - 1]);
				}      
			}
		}

		int lcsLength = X[aLength][bLength];
		int copy = X[aLength][bLength];

		char res[copy + 1];              //traverse table and add characters to the result character array
		res[copy] = '\0';

		while(aLength > 0 && bLength > 0) {
			if(a[aLength - 1] == b[bLength - 1]) {
				res[copy - 1] = a[aLength - 1];
				copy--;
				aLength--;
				bLength--;
		
			}
			else if(X[aLength - 1][bLength] > X[aLength][bLength - 1]) {
				aLength--;
			}
			else {
				bLength--;
			}
		}
		//print out the length the the actual subsequence
		cout << lcsLength << " " << res << endl;

	}

	vector<IndexPair> findAll(int** arr, int length1, int length2) {
		if (arr[length1][length2] == 0 || length1 == 0 || length2 == 0) {
			IndexPair ip = IndexPair(-1,-1);
			tuples.push_back(ip);                     //add dummy value
		}
		if (a[length1] == b[length2]) {
			IndexPair ip2 = IndexPair(length1,length2);
			tuples.push_back(ip2);
			findAll(arr, length1 - 1, length2 - 1);     //backtrack diagonal
		}

		else if(arr[length1][length2 - 1] < arr[length1 - 1][length2]) {
			findAll(arr, length1 - 1, length2);         //backtrack 
		}
		else {
			findAll(arr, length1, length1 - 1);    //backtrack
		}

		return tuples;

	}

	void LCSallHelper() {

		int aLength = a.length();
		int bLength = b.length();
		int **allTable;
		allTable = new int*[aLength + 1];
		
		for(int k = 0; k <= aLength; k++) {
			allTable[k] = new int[bLength + 1];
		}

		for(int q = 0; q <= aLength; q++) {
			allTable[q][0] = 0;
		}
		for(int w = 0; w <= bLength; w++) {
			allTable[0][w] = 0;
		}
		for(int i = 1; i <= aLength; i++) {           //generating the table
			for(int j = 1; j <= bLength; j++) {
			
				if(a[i - 1] == b[j - 1]) {
					allTable[i][j] = allTable[i - 1][j - 1] + 1;
				}
				else {
					allTable[i][j] = max(allTable[i - 1][j] , allTable[i][j - 1]);
				}
			}
		}
		vector<IndexPair> allIndices;
		allIndices = findAll(allTable, aLength, bLength); //call recursive function
		for (int n = 0; n < allIndices.size(); n++) {
			if (allIndices[n].getFirst() < 0) {
				continue;
			}
			allIndices[n].printOut();
		}                               //print out indices
		cout << endl;
		

	}


};

#endif