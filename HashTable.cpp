#include "HashTable.h"


//Creates the hash code
int HashTable::hashFunction(string key, int tableSize)
{
    int sum = 0;
    string str = key;
    for (int i = 0; i < str.length(); i++)
    {
        sum += str[i];
    }
    sum = sum / tableSize;
    return sum;
}

void HashTable::buildTable()
{
    string garb1, garb2, state, county, cases, deaths;
    int line = 0;
    ifstream file("us-counties.csv");
    if (!file.is_open())
    {
        throw runtime_error("Could not open file");
    } else
    {
        file.ignore(35);
        int lineCount = 0;
        while (!file.eof())

        {

            getline(file, garb1, ','); // garb is data the program isn't grabbing
            getline(file, county, ',');
            getline(file, state, ',');
            getline(file, garb2, ',');
            getline(file, cases, ',');
            getline(file, deaths, '\n');

            int stateHash;
            int countyHash;
            stateHash = hashFunction(state, STATEHASHNUMBER);
            countyHash = hashFunction(county, COUNTYHASHNUMBER);
            lineCount++;


            bool inStateMap = false;
            for (int i = 0; i < stateMap[stateHash].size(); i++)
            {
                if (stateMap[stateHash][i].first == state)
                {

                    stateMap[stateHash][i].second.first = stoi(cases);
                    stateMap[stateHash][i].second.second = stoi(deaths);
                    inStateMap = true;

                }
            }

            if (!inStateMap)
            {
                stateMap[stateHash].emplace_back(state,make_pair(stoi(cases),stoi(deaths)));
            }

            bool inCountyMap = false;
            for (int i = 0; i < countyMap[countyHash].size(); i++)
            {
                if (countyMap[countyHash][i].first == county)
                {
                    countyMap[countyHash][i].second.first = stoi(cases);
                    countyMap[countyHash][i].second.second = stoi(deaths);
                    inCountyMap = true;
                }
            }

            if (!inCountyMap)
            {
                countyMap[countyHash].emplace_back(county,make_pair(stoi(cases),stoi(deaths)));
            }

                if (lineCount == 1)
                {
                    cout << "Loading data............" << endl;
                }
            }
        }
    }

void HashTable::searchCounties(string name)
{
    int hash = hashFunction(name,COUNTYHASHNUMBER);

    for (int i = 0; i < countyMap[hash].size(); i++)
    {
        if (countyMap[hash][i].first == name)
        {
            cout << "County Name: " << countyMap[hash][i].first << endl;
            cout << "Case Count: " << countyMap[hash][i].second.first << endl;
            cout << "Death Count: " << countyMap[hash][i].second.second << endl;
        }
    }
}
void HashTable::searchStates(string name)
{
    int hash = hashFunction(name,STATEHASHNUMBER);

    for (int i = 0; i < stateMap[hash].size(); i++)
    {
        if (stateMap[hash][i].first == name)
        {
            cout << "State Name: " << stateMap[hash][i].first << endl;
            cout << "Case Count: " << stateMap[hash][i].second.first << endl;
            cout << "Death Count: " << stateMap[hash][i].second.second << endl;
        }
    }
}

int HashTable::buildArray(int arr[])
{
    string garb1, garb2, state, county, cases, deaths;
    int line = 0;
    ifstream file("us-counties.csv");
    if (!file.is_open())
    {
        throw runtime_error("Could not open file");
    } else
    {
        file.ignore(35);
        int lineCount = 0;
        while (lineCount < 100000)
        {

            getline(file, garb1, ','); // garb is data the program isn't grabbing
            getline(file, county, ',');
            getline(file, state, ',');
            getline(file, garb2, ',');
            getline(file, cases, ',');
            getline(file, deaths, '\n');

            arr[line] = stoi(cases);

            lineCount++;


        }
    }
    return *arr;
}