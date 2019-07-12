#include <stdio.h>
#include <cstring>
#include <fstream>
#include <map>
#include <string>

namespace Json {
using namespace std;

bool writeSingleLine(ofstream& outJson, const string name, const string value) {
    outJson << "\"" << name << "\":\"" << value << "\",";	// "a":"b",
    return outJson.fail();
}

template <class T>
int writeJson(std::map<T, T> table) {
    ofstream outJson("data.json");
    if (!outJson.is_open())
        return -1;  //opening file faild

    outJson << "{" << endl;
    for (auto iter = table.begin(); iter != table.end() - 1; iter++) {
        std::string name2String = std::to_string(iter->first);
        std::string value2String = std::to_string(iter->second);
        bool isFaild = writeSingleLine(outJson, name2String, value2String);

        if (isFaild) {
            perror("Error: ");
            outJson.close();
            return 0;
        }
    }

    outJson << to_string((table.end() - 1)->first) << to_string((table.end() - 1)->second) << "}" << endl;  //write the last line
    outJson.close();
    return 1;
}
}  // namespace Json
