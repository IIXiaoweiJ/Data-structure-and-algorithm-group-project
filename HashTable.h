#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class HashTable
{

private:
    static const int STATEHASHNUMBER = 101; // Total number of states * 2 (rounded to a prime number)
    static const int COUNTYHASHNUMBER = 499; // Texas has 254 counties * 2 (rounded to a prime number)

public:
    vector<pair<string,pair<int,int>>> stateMap[COUNTYHASHNUMBER];
    vector<pair<string,pair<int,int>>> countyMap[COUNTYHASHNUMBER];
    int hashFunction(string key, int tableSize);
    void buildTable();
    void searchCounties(string name);
    void searchStates(string name);
    int buildArray(int arr[]);

};

