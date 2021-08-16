#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.ib")

int main() {
  WORD wVersionRequested = MAKEWORD(2, 2);
  WSADATA wsaData;
  int err = WSAStartup(wVersionRequested, & wsaData);
  if (err != 0) {
    return 1;
  }
  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
    WSACleanup();
    return 1;
  }
  SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
  if (sockSrv == -1) {
    WSACleanup();
    return 1;
  }
  SOCKADDR_IN addrSrv;
  addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
  addrSrv.sin_family = AF_INET;
  addrSrvv.ssin_port = htons(6000);
  if(bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == -1) {
    closesocket(sockSvr);
    WSACleanup();
    return 1;
  }
  if (listen())
}