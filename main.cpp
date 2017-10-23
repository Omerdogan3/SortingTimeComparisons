#include "main.h"
float distanceBetweenTwo(float lat1, float lon1, float lat2, float lon2);
template<typename T> void mergesort(T begin, T end, T res);
template<typename T> void bubblesort(T a, int n);
template<typename T> void swap(T *xp, T *yp);

int main(){
	int numEnter = -1;

	float lon =  41.015137;
	float lat = 28.979530;

	string line;
	ofstream MyExcelFile;
	ifstream myfile("location.txt");
	MyExcelFile.open("test.csv");

	MyExcelFile << "Size, BubbleSort, MergeSort" << endl;

	if(myfile.is_open()){
		for(int i=0; numEnter != 0; ++i){
			cout << "Please enter size you want to sort (0 to exit): ";
			cin >> numEnter;

			float distances[numEnter];
			float sorted[numEnter];

			for(int i=0; i<numEnter; ++i){
				getline(myfile, line);
				unsigned pos = line.find("\t");
				string city = line.substr(0,pos);
				line = line.substr(pos+1);
				pos = line.find("\t");
				float latitude = atof(line.substr(0,pos).c_str());
				line = line.substr(pos+1);
				float longitude = atof(line.substr(0,pos).c_str());
				distances[i] = distanceBetweenTwo(lat,lon,latitude,longitude);
			}

			clock_t mergeBegin = clock();
			mergesort(distances, distances + numEnter, sorted);
			clock_t mergeEnd = clock();
			cout << "MergeSort: " << ((float)(mergeEnd-mergeBegin))/CLOCKS_PER_SEC << endl;

			//In mergesort program will generate an another sorted array
			//So bubblesort will sort unsorted array

			clock_t bubbleBegin = clock();
			bubblesort(distances,numEnter);
			clock_t bubbleEnd = clock();
			cout << "BubbleSort: " << ((float)(bubbleEnd-bubbleBegin))/CLOCKS_PER_SEC << endl;

			float test1 = ((float)(mergeEnd-mergeBegin))/CLOCKS_PER_SEC;
			float test2 = ((float)(bubbleEnd-bubbleBegin))/CLOCKS_PER_SEC;

			stringstream ss (stringstream::in | stringstream::out);

			ss << numEnter;
			ss <<',';
			ss << test2;
			ss << ',';
			ss << test1;

			string test = ss.str();

			if(numEnter != 0){
				MyExcelFile << test << endl;
				cout << "Results saved in 'test.csv' file" << endl;
			}
		}
	  MyExcelFile.close();
	  myfile.close();
	  return 0;
  }else
	  cout << "File could not be opened." << endl;
  return 0;
}
