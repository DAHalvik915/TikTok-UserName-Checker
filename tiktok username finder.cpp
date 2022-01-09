#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <urlmon.h>
#include <fstream>
#include <string>
#pragma comment(lib, "Urlmon.lib")
int main() {
    std::string url = "https://www.tiktok.com/@";
    std::string username;
    std::cout << "TikTok UserName Checker\n";
    std::cout << "Enter UserName: ";
    std::cin >> username;
    std::string together = url + username;
    std::string search = "Followers";
    std::string line;
    int found = 0;
    std::wstring stemp = std::wstring(together.begin(), together.end());
    LPCWSTR FinalURL = stemp.c_str();
    TCHAR Output[] = _T("C:\\Temp\\result.txt");
    URLDownloadToFile(0, FinalURL, Output, 0, 0);
    unsigned int curLine = 0;
    std::ifstream myfile("C:\\Temp\\result.txt");
    while (getline(myfile, line)) {
        curLine++;
        if (line.find(search, 0) != std::string::npos) {

            found = 1;
            std::cout << "username taken\n";
        }
    }
    myfile.close();
    remove("C:\\Temp\\result.txt");
    if (found == 0) {
        std::cout << "username not taken\n";
    }
    system("pause");
    return 0;
}