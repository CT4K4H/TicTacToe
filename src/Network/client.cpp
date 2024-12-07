// #include <iostream>
// #include <WinSock2.h>
// #include <WS2tcpip.h>
// #include <inaddr.h>
// #include <stdio.h>
// #include <vector>


// constexpr char SERVER_IP[] = "";					// Enter IPv4 address of Server
// constexpr short SERVER_PORT_NUM = 55555;				// Enter Listening port on Server side
// constexpr short BUFF_SIZE = 1024;


// void log(std::string msg) {
// 	std::cout << "---" << msg << '\n';
// }

// void clientInit(int& erStat) {
// 	// WinSock initialization
// 	WSADATA wsData;
// 	erStat = WSAStartup(MAKEWORD(2,2), &wsData);

// 	if (erStat != 0) {
// 		std::cout << "Error WinSock version initializaion #";
// 		std::cout << WSAGetLastError();
// 	}
// 	else 
// 		std::cout << "WinSock initialization is OK" << '\n';
// }


// SOCKET sockInit(int& erStat) {
// 	SOCKET client_sock = socket(AF_INET, SOCK_STREAM, 0);

// 	if (client_sock == INVALID_SOCKET) {
// 		std::cout << "Error initialization socket # " << WSAGetLastError() << '\n';
// 		closesocket(client_sock);
// 		WSACleanup();
// 	}
// 	else 
// 		std::cout << "Client socket initialization is OK" << '\n';

// 	return client_sock;
// }


// sockaddr_in setServerInfo(in_addr& ip_to_num, SOCKET& client_sock,int& erStat) {
// 	sockaddr_in servInfo;

// 	ZeroMemory(&servInfo, sizeof(servInfo));

// 	servInfo.sin_family = AF_INET;
// 	servInfo.sin_addr = ip_to_num;
// 	servInfo.sin_port = htons(SERVER_PORT_NUM);

// 	erStat = connect(client_sock, (sockaddr*)&servInfo, sizeof(servInfo));
	
// 	if (erStat != 0) {
// 		std::cout << "Connection to Server is FAILED. Error # " << WSAGetLastError() <<std:: endl;
// 		closesocket(client_sock);
// 		WSACleanup();
// 	}
// 	else 
// 		std::cout << "Connection established SUCCESSFULLY. Ready to send a message to Server" << '\n';
// }



// int main()
// {

// 	// Key variables for all program
// 	int erStat;										// For checking errors in sockets functions

// 	//IP in string format to numeric format for socket functions. Data is in "ip_to_num"
// 	in_addr ip_to_num;		
// 	inet_pton(AF_INET, SERVER_IP, &ip_to_num);



        
// 	//  Establishing a connection to Server



// 	//Exchange text data between Server and Client. Disconnection if a Client send "xxx"

// 	std::vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);							// Buffers for sending and receiving data
// 	short packet_size = 0;												// The size of sending / receiving packet in bytes
		
// 	while (true) {

// 		std::cout << "Your (Client) message to Server: ";
// 		fgets(clientBuff.data(), clientBuff.size(), stdin);

// 		// Check whether client like to stop chatting 
// 		if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
// 			shutdown(ClientSock, SD_BOTH);
// 			closesocket(ClientSock);
// 			WSACleanup();
// 			return 0;
// 		}

// 		packet_size = send(ClientSock, clientBuff.data(), clientBuff.size(), 0);

// 		if (packet_size == SOCKET_ERROR) {
// 			std::cout << "Can't send message to Server. Error # " << WSAGetLastError() << '\n';
// 			closesocket(ClientSock);
// 			WSACleanup();
// 			return 1;
// 		} 

// 		packet_size = recv(ClientSock, servBuff.data(), servBuff.size(), 0);

// 		if (packet_size == SOCKET_ERROR) {
// 			std::cout << "Can't receive message from Server. Error # " << WSAGetLastError() << '\n';
// 			closesocket(ClientSock);
// 			WSACleanup();
// 			return 1;
// 		}
// 		else
// 			std::cout << "Server message: " << servBuff.data() <<std:: endl;

// 	}

// 	closesocket(ClientSock);
// 	WSACleanup();

//     system("pause");

// }
