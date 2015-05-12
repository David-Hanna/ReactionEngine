//
//  Element.cpp
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#include "Element.h"

Element::Element(const std::string _name,
                 const unsigned int _instanceID,
                 const unsigned int _freeElectrons) :
name(_name),
instanceID(_instanceID),
freeElectrons(_freeElectrons)
{
    
}

bool Element::createBond(std::shared_ptr<Element> element)
{
    return true; // TODO
}

bool Element::detachBond(const unsigned int ID)
{
    return true; // TODO
}