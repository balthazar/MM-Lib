/******************************************************************************
 * Copyright (c) 2013-2014, Amsterdam University of Applied Sciences (HvA) and
 *                          Centrum Wiskunde & Informatica (CWI)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   * Riemer van Rozen - rozen@cwi.nl - HvA / CWI
 ******************************************************************************/
//
//  Deletion.cpp
//  mm
//
//  Created by Riemer van Rozen on 9/29/13.
//

#include <stdio.h>
#include <stdlib.h>
#include "YYLTYPE.h"
#include "Types.h"
#include "Recyclable.h"
#include "Vector.h"
#include "Recycler.h"
#include "Location.h"
#include "String.h"
#include "Name.h"
#include "Element.h"
#include "Deletion.h"

const MM::CHAR * MM::Deletion::DELETE_STR = "delete";
const MM::UINT32 MM::Deletion::DELETE_LEN = strlen(MM::Deletion::DELETE_STR);

MM::Deletion::Deletion(MM::Name * name) : MM::Element(name)
{
  this->loc = MM_NULL;
}

MM::Deletion::Deletion(MM::Location * loc, MM::Name * name) : MM::Element(name)
{
  this->loc = loc;
}

MM::Deletion::~Deletion()
{
  loc = MM_NULL;
}

MM::VOID MM::Deletion::recycle(MM::Recycler * r)
{
  if(loc != MM_NULL)
  {
    loc->recycle(r);
  }
  this->Element::recycle(r);
}

MM::TID MM::Deletion::getTypeId()
{
  return MM::T_Deletion;
}

MM::BOOLEAN MM::Deletion::instanceof(MM::TID tid)
{
  if(tid == MM::T_Deletion)
  {
    return MM_TRUE;
  }
  else
  {
    return MM::Element::instanceof(tid);
  }
}

MM::Location * MM::Deletion::getLocation()
{
  return loc;
}

MM::VOID MM::Deletion::toString(MM::String * buf)
{
  toString(buf, 0);
}

MM::VOID MM::Deletion::toString(MM::String * buf, MM::UINT32 indent)
{
  buf->space(indent);
  buf->append((MM::CHAR*)MM::Deletion::DELETE_STR, MM::Deletion::DELETE_LEN);
  buf->space();
  name->toString(buf);
}
