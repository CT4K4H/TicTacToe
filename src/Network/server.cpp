// #include <iostream>
// #include <WinSock2.h>
// #include <WS2tcpip.h>
// #include <stdio.h>
// #include <vector>

// int main() {

//     const int WSVer = MAKEWORD(2, 2);
//     WSAData WsaData1;
//     hostent* ht;
//     char buff[128];
//     if (WSAStartup(WSVer, &WsaData1) == 0)
//     {
//         if(gethostname(buff, 128) == 0)
//         {
//             ht = gethostbyname(buff);
//             if (ht != NULL)
//             {
//                 std::cout << inet_ntoa(*(reinterpret_cast<in_addr *>(*(ht->h_addr_list))));
//             }
//         }
//         WSACleanup();
//     }

//     system("pause");
    
// 	const int PORT_NUM = 55555;				// Enter Open working server port
// 	const short BUFF_SIZE = 1024;	

//     WSADATA wsaData;
    
//     int erStat = WSAStartup(MAKEWORD(2,2), &wsaData);

//     if (erStat != 0 ) {
//         std::cout << "Error initialization!: ";
//         std::cout << WSAGetLastError();
//         return 1;
//     }
//     else {
//         std::cout << "Initialization complete!\n";
//     }

//     SOCKET ServSock = socket(AF_INET, SOCK_STREAM, 0);
//     if (ServSock == INVALID_SOCKET) {
//         std::cout << "Error initialization socket!: ";
//         std::cout << WSAGetLastError();
//         closesocket(ServSock);
//         WSACleanup();
//         return 1;
//     }
//     else {
//         std::cout << "Server socket initialazied successefully!\n";
//     }

//     // in_addr ip_to_num;
    
//     // erStat = inet_pton(AF_INET, IP_SERV, &ip_to_num);
//     // if (erStat <= 0) {
//     //     std::cout << "Error in IP translation to numeric format\n";
//     //     return -1;
//     // }

//     sockaddr_in servInfo;
//     ZeroMemory(&servInfo, sizeof(servInfo));

//     servInfo.sin_family = AF_INET;
//     servInfo.sin_addr.s_addr = INADDR_ANY;
//     servInfo.sin_port = htons(PORT_NUM);

//     erStat = bind(ServSock, (sockaddr*)&servInfo, sizeof(servInfo));
//     if (erStat != 0) {
//         std::cout << "Error socket binding! " << WSAGetLastError();
//         closesocket(ServSock);
//         WSACleanup();
//         return -1;
//     }
//     else { 
//         std::cout << "Socket building complete!\n";
//     }

//     erStat = listen(ServSock, SOMAXCONN);
//     if (erStat != 0) {
//         std::cout << "Can't start to listen to!: " << WSAGetLastError();
//         closesocket(ServSock);
//         WSACleanup();
//         return -1;
//     }
//     else {
//         std::cout << "Listening...\n";
//     }



//     sockaddr_in clientInfo; 
// 	ZeroMemory(&clientInfo, sizeof(clientInfo));	// Initializing clientInfo structure

// 	int clientInfo_size = sizeof(clientInfo);

// 	SOCKET ClientConn = accept(ServSock, (sockaddr*)&clientInfo, &clientInfo_size);

// 	if (ClientConn == INVALID_SOCKET) {
// 		std::cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << std::endl;
// 		closesocket(ServSock);
// 		closesocket(ClientConn);
// 		WSACleanup();
// 		return 1;
// 	}
// 	else {
// 		std::cout << "Connection to a client established successfully" << std::endl;
// 		char clientIP[22];

// 		inet_ntop(AF_INET, &clientInfo.sin_addr, clientIP, INET_ADDRSTRLEN);	// Convert connected client's IP to standard string format

// 		std::cout << "Client connected with IP address " << clientIP << std::endl;

// 	}

// 	//Exchange text data between Server and Client. Disconnection if a client send "xxx"

// 	std::vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);							// Creation of buffers for sending and receiving data
// 	short packet_size = 0;												// The size of sending / receiving packet in bytes
	
// 	while (true) {
// 		packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);					// Receiving packet from client. Program is waiting (system pause) until receive
// 		std::cout << "Client's message: " << servBuff.data() << std::endl; 

// 		std::cout << "Your (host) message: ";
// 		fgets(clientBuff.data(), clientBuff.size(), stdin);

// 		// Check whether server would like to stop chatting 
// 		if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
// 			shutdown(ClientConn, SD_BOTH);
// 			closesocket(ServSock);
// 			closesocket(ClientConn);
// 			WSACleanup();
// 			return 0;
// 		}

// 		packet_size = send(ClientConn, clientBuff.data(), clientBuff.size(), 0);

// 		if (packet_size == SOCKET_ERROR) {
// 			std::cout << "Can't send message to Client. Error # " << WSAGetLastError() << std::endl;
// 			closesocket(ServSock);
// 			closesocket(ClientConn);
// 			WSACleanup();
// 			return 1;
// 		}

// 	}

// 	closesocket(ServSock);
// 	closesocket(ClientConn);
// 	WSACleanup();

//     std::cout << "LOL!\n";
//     system("pause");
// }