//Nathan Van De Vyvere
//CMPS 4883 Programming Techniques
//Sep 9,2021

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int x,_size,mov1,mov2;
	bool check=true;
	vector<int> vec1,vec2;
	
	//loop to read all of the input
	while (cin >> x) {
		_size = x;//takes the first input from each line to determine the size of the vector
		//loop to fill the first vector
		for (int z = 0; z < _size; z++) {
			cin >> x;
			vec1.push_back(x);
		}

		if (vec1.size() > 1) {
			//this loop takes the absolute value of the difference between each consecutive
			//element in the vector and stores those values in a new vector
			while (vec1.size() != 1) {
				mov1 = vec1.back();
				vec1.pop_back();
				mov2 = vec1.back();
				mov1 = abs(mov1 - mov2);
				vec2.push_back(mov1);
			}
			//this sorts the elements of the vector in order to make testing for jolly 
			//jumper easier
			sort(vec2.begin(), vec2.end());
			//unique moves duplicate elements to the end of the vector
			unique(vec2.begin(), vec2.end()), vec2.end();
			//this loop checks that each integer between 0 and n are in the vector
			for (int i = 1; i < _size; i++) {
				if (i == vec2[i - 1])
					check = true;
				else {
					check = false;
					i = _size;
				}
			}
		}
		// if the vector only had 1 or 0 elements it returned true
		else
			check = true;

		//prints the results of the vector
		if (check == true)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

		//empties both vectors 
		vec2.clear();
		vec1.clear();
	}
    return 0;
}

