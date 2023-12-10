#include <iostream>
#include <Node.h>
#include <fstream>
#include <vector>
#include <map>

#define LOG(X) std::cout << X << "\n"

uint64_t gcd(uint64_t a, uint64_t b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

uint64_t findlcm(std::vector<uint64_t> arr)
{
    // Initialize result
    uint64_t ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < arr.size(); i++)
        ans = (((arr[i] * ans)) /
            (gcd(arr[i], ans)));

    return ans;
}
void makeNodes(std::map<std::string, std::vector<std::string>>& dataMap, const std::string line)
{
    std::string val = line.substr(0, 3);
    std::string left = line.substr(7, 3);
    std::string right = line.substr(12, 3);
    std::vector<string> _ =  { left,right };
    dataMap.emplace(val, _);
    
  
}
std::vector<string>* findDesired(const std::map<std::string, std::vector<std::string>>& dataMap, char desiredChar)
{
    std::vector<string>* desired = new std::vector<string>();

    for (auto kv : dataMap)    
        if (kv.first[2] == desiredChar)
            desired->push_back(kv.first);
    

    return desired;
}

uint64_t findZZZ(const std::map<std::string, std::vector<std::string>>& dataMap, std::string NavigationElements)
{
    using std::string;
    uint64_t i = 0;
    std::vector<uint64_t> result;
    
    std::vector<string>* withA = findDesired(dataMap, 'A');
    std::vector<string>* withZ = findDesired(dataMap, 'Z');
    string first;
    for(int k = 0; k< withA->size(); k++)
    {
        i = 0;
        first = withA->at(k);
        while (first[2] != 'Z')
        {
            
            for (int j = 0; j < NavigationElements.size() && first[2] != 'Z'; i++, j++)
            {

                switch (NavigationElements[j])
                {

                case 'L':
                    first = dataMap.at(first)[0];
                    break;
                case 'R':
                    first = dataMap.at(first)[1];
                    break;


                }

            }

        }
        result.push_back(i);
    }
    for (auto _ : result)
    {
        LOG(_);
    }
    delete withA;
    delete withZ;
    return findlcm(result);
}



int main()
{

    {
        
        std::string navigationElements;
        std::string line;
        std::ifstream file("input.txt");

        std::map<std::string, std::vector<std::string>> dataMap;

        int lineCounter = 0;
        if (file.is_open())
        {
            Timer timer = Timer();
            while (getline(file, line)) {
                switch (lineCounter)
                {
                case 0:
                    navigationElements = line;
                    lineCounter++;
                    break;
                case 1:
                    lineCounter++;
                    break;
                default:
                    makeNodes(dataMap, line);


                    lineCounter++;
                    break;
                }

            }
            
            file.close();
        }



        std::cout << findZZZ(dataMap, navigationElements);

    }
    std::cin.get();
}