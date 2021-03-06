/* 
 *  Copyright (c) 2010,
 *  Gavriloaie Eugen-Andrei (shiretu@gmail.com)
 *
 *  This file is part of crtmpserver.
 *  crtmpserver is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  crtmpserver is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with crtmpserver.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifdef NET_EPOLL
#ifndef _UDPCARRIER_H
#define	_UDPCARRIER_H

#include "netio/epoll/iohandler.h"

class BaseProtocol;

class UDPCarrier
: public IOHandler {
private:
	sockaddr_in _peerAddress;
	sockaddr_in _nearAddress;
	string _nearIp;
	uint16_t _nearPort;
	uint64_t _rx;
	uint64_t _tx;
public:
	UDPCarrier(int32_t fd);
	virtual ~UDPCarrier();

	virtual bool OnEvent(struct epoll_event &event);
	virtual bool SignalOutputData();
	virtual operator string();
	virtual void GetStats(Variant &info);

	string GetFarEndpointAddress();
	uint16_t GetFarEndpointPort();
	string GetNearEndpointAddress();
	uint16_t GetNearEndpointPort();

	static UDPCarrier* Create(string bindIp, uint16_t bindPort);
	static UDPCarrier* Create(string bindIp, uint16_t bindPort, BaseProtocol *pProtocol);
private:
	bool Setup(Variant &settings);
	bool GetEndpointsInfo();
};


#endif	/* _UDPCARRIER_H */
#endif /* NET_EPOLL */

