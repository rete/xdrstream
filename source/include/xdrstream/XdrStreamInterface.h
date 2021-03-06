 /// \file XdrStreamInterface.h
/*
 *
 * XdrStreamInterface.h header template automatically generated by a class generator
 * Creation date : dim. janv. 24 2016
 *
 * This file is part of xdrtstream libraries.
 * 
 * xdrtstream is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * xdrtstream is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with xdrtstream.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef XDRSTREAMINTERFACE_H
#define XDRSTREAMINTERFACE_H

#include "xdrstream/XdrDefinitions.h"

namespace xdrstream
{

/**
 *  @brief  XdrStream class
 */
class XdrStream 
{
public:
	/**
	 *  @brief  Constructor
	 */
	XdrStream();

	/**
	 *  @brief  Destructor
	 */
	~XdrStream();

	/**
	 *  @brief  Write a target record into the io device
	 *
	 *  @param  recordName the registered record name
	 *  @param  pDevice the device to write into
	 */
	Status writeRecord(const std::string &recordName, IODevice *pDevice);

	/**
	 *  @brief  Read a target record from the io device
	 *
	 *  @param  pRecord the record pointer to receive
	 *  @param  pDevice the device to read from
	 */
	Status readRecord(Record *&pRecord, IODevice *pDevice);

	/**
	 *  @brief  Read the next record from the io device.
	 *          The record name must be the one specified else it is skipped
	 *
	 *  @param  recordName the target record name
	 *  @param  pRecord the record pointer to receive
	 *  @param  pDevice the device to read from
	 */
	Status readRecord(const std::string &recordName, Record *&pRecord, IODevice *pDevice);

	/**
	 *  @brief  Skip the next record in the io device
	 *
	 *  @param  pDevice the io device to skip the next record
	 */
	Status skipNextRecord(IODevice *pDevice);

	/**
	 *  @brief  Skip the next records until recordName appears.
	 *          When the target record name is found, the device cursor
	 *          is set just before the record, ready to read it
	 *
	 *  @param  recordName the target record name
	 *  @param  pDevice the device to read from
	 */
	Status skipRecordsUntill(const std::string &recordName, IODevice *pDevice);

	/**
	 *  @brief  Create a record with the target name.
	 *          If the record already exists, it is returned.
	 *          Note that XdrStream owns the record.
	 *
	 *  @param  recordName the name of the record to create
	 */
	Record *createRecord(const std::string &recordName);

	/**
	 *  @brief  Get a created record with the target name
	 *
	 *  @param  recordName the record name to query
	 *
	 *  @return the queried record pointer
	 */
	Record *getRecord(const std::string &recordName) const;

	/**
	 *  @brief  Remove the record with the target name
	 *          Note that the record is remove and the
	 *          pointer deleted
	 *
	 *  @param  pRecord the record to remove and delete
	 */
	Status removeRecord(Record *pRecord);

	/**
	 *  @brief  Remove the record with the target name
	 *          Note that the record is remove and the
	 *          pointer deleted
	 *
	 *  @param  recordName the name of the record to remove and delete
	 */
	Status removeRecord(const std::string &recordName);

	/**
	 *  @brief  Get a block with the target name
	 *
	 *  @param  blockName the target block name to query
	 *
	 *  @return the queried block pointer
	 */
	Block *getBlock(const std::string &blockName) const;

private:
	/**
	 *  @brief  Add a block into this xdr stream.
	 *          Private method called by blocks to register themselves in the xdr stream
	 *
	 *  @param  pBlock the block pointer to register
	 */
	Status addBlock(Block *pBlock);

	/**
	 *  @brief  Remove a block from this xdr stream.
	 *          Private method called by blocks to auto remove them from the xdr stream.
	 *          Called from Block destructor
	 *
	 *  @param  pBlock the block to remove
	 */
	Status removeBlock(Block *pBlock);

private:
	BlockMap                       m_blockMap;
	RecordMap                      m_recordMap;

	friend class Block;  // for block registration
}; 

} 

#endif  //  XDRSTREAMINTERFACE_H
