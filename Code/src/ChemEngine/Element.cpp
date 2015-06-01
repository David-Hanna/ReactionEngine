//
//  Element.cpp
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#include "Element.h"

unsigned int Element::nextInstanceID = 0;

Element::Element(const std::string _name) :
name(_name),
instanceID(nextInstanceID++),
bondCount(0)
{
    if (name == "hydrogen")
    {
        freeElectrons = 1;
    }
    else if (name == "carbon")
    {
        freeElectrons = 4;
    }
    else
    {
        std::cout << "Unrecognized element name: " << name << std::endl;
        assert(false);
    }
}

bool Element::CreateBond(Element* element, bool bidirectional/*=true*/)
{
    if (freeElectrons == 0)
        return false;
    
    bonds[element->InstanceID()] = element;
    freeElectrons--;
    bondCount++;
    
    if (bidirectional)
        return element->CreateBond(this, false);
    
    return true;
}

bool Element::DetachBond(const unsigned int ID, bool bidirectional/*=true*/)
{
    BondsMap::const_iterator iter = bonds.find(ID);
    
    if (iter == bonds.end())
        return false;
    
    if (bidirectional)
        iter->second->DetachBond(instanceID, false);
    
    bonds.erase(ID);
    freeElectrons++;
    bondCount--;
    
    return true;
}