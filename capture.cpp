// capture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<windows.h>
#include <shellapi.h>
#include <string>
using namespace std;

int main()
{
    
    system("title TCPGuard.com");
     cout << "TCPGuard.com Capture Packets" << endl;

     wstring comm = L"";
    
     comm.append(L"/k cd C:\\Users\\%username%\\Desktop\\");
     comm.append(L" & C:\\Windows\\System32\\pktmon.exe start --etw");
     comm.append(L" && exit ");

	 HINSTANCE retVal = ShellExecuteW(NULL, L"open", L"cmd", comm.c_str(), NULL, SW_HIDE);

     Sleep(10000);

     comm = L"";
     comm.append(L"/k C:\\Windows\\System32\\pktmon.exe stop");
     comm.append(L" && exit ");

     ShellExecuteW(NULL, L"open", L"cmd", comm.c_str(), NULL, SW_HIDE);

     Sleep(10000);

     comm = L"";
     comm.append(L"/k cd C:\\Users\\%username%\\Desktop\\");
     comm.append(L" & C:\\Windows\\System32\\pktmon.exe pcapng PktMon.etl -o out.pcapng");
     comm.append(L" && exit ");

     ShellExecuteW(NULL, L"open", L"cmd", comm.c_str(), NULL, SW_HIDE);

     system("pause");
   

}
