
// Server.h

// Interfaces to the cServer class encapsulating the entire "server"





#pragma once

#include "SocketThreads.h"
#include "ListenThread.h"
#include "PolarSSL++/RsaPrivateKey.h"






class cServer
	: public cListenThread::cCallback
{
	SOCKET m_ListenSocket;
	cRsaPrivateKey m_PrivateKey;
	AString m_PublicKeyDER;
	short m_ConnectPort;

	
	
public:
	cServer(void);
	~cServer(void);
	
	int  Init(short a_ListenPort, short a_ConnectPort);
	
	cRsaPrivateKey & GetPrivateKey(void) { return m_PrivateKey; }
	const AString & GetPublicKeyDER (void) { return m_PublicKeyDER; }
	
	short GetConnectPort(void) const { return m_ConnectPort; }

	cSocketThreads m_SocketThreads;

private:

	cListenThread m_ListenThread;
	

	// cListenThread::cCallback overrides:
	virtual void OnConnectionAccepted(cSocket & a_Socket) override;

} ;




