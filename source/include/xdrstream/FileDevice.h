  /// \file FileDevice.h
/*
 *
 * FileDevice.h header template automatically generated by a class generator
 * Creation date : dim. janv. 17 2016
 *
 * This file is part of xdrstream libraries.
 * 
 * xdrstream is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * xdrstream is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with xdrstream.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef FILEDEVICE_H
#define FILEDEVICE_H

#include "IODevice.h"


namespace xdrstream {

/** 
 * @brief FileDevice class
 */ 
class FileDevice : public IODevice 
{
 public:
 /**
  * @brief Ctor
  */
 FileDevice();

 /**
  * @brief Dtor 
  */
 virtual ~FileDevice();

protected:


}; 

} 

#endif  //  FILEDEVICE_H
