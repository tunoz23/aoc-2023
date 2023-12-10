#include <iostream>
#include <Node.h>
#include <fstream>
#include <vector>
#include <map>

void makeNodes(std::map<std::string, std::vector<std::string>>& dataMap, const std::string line)
{
    std::string val = line.substr(0, 3);
    std::string left = line.substr(7, 3);
    std::string right = line.substr(12, 3);
    std::vector<string> _ =  { left,right };
    dataMap.emplace(val, _);
    //dataMap[val] = { left,right };
  
}
uint64_t findZZZ(const std::map<std::string, std::vector<std::string>>& dataMap, std::string NavigationElements)
{
    using std::string;
    uint64_t i = 0;
   
    string first = "AAA";
    
    while (first != "ZZZ")
    {
        for (int j = 0; j < NavigationElements.size() && first != "ZZZ"; i++, j++)
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

    return i;
}
int main()
{
    std::string navigationElements;
    std::string line;
    std::ifstream file("input.txt");
    ;
    std::map<std::string, std::vector<std::string>> dataMap;
   
    int lineCounter = 0;
    if (file.is_open()) {

        while (getline(file, line)) {
            switch (lineCounter )
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
        //std::cout << navigationElements;
        file.close();
    }
    std::cout << findZZZ(dataMap,navigationElements);
    
}