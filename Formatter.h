#include <string>
using namespace std;

#ifndef Formatter_h
#define Formatter_h



class Formatter {
	
private:
	//int len;
	//string subseq;
	string a;
	string b;
public:
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

	int max(int a, int b) {
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
				else {
					X[i][j] = max(X[i - 1][j] , X[i][j - 1]);
				}
			}
		}

		int lcsLength = X[aLength][bLength];
		int copy = X[aLength][bLength];

		char res[copy + 1];
		res[copy] = '\0';

		while(aLength > 0 && bLength > 0) {
			if(a[aLength - 1] == b[bLength - 1]) {
				res[copy - 1] = a[aLength - 1];
				aLength--;
				bLength--;
				copy--;
			}
			else if(X[aLength - 1][bLength] > X[aLength][bLength - 1]) {
				aLength--;
			}
			else {
				bLength--;
			}
		}

		cout << lcsLength << " " << res << endl;

	}

	void LCSall() {

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
				else {
					X[i][j] = max(X[i - 1][j] , X[i][j - 1]);
				}
			}
		}

	}


};

#endif