//
//  Element.h
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#ifndef __ChemEngine__Element__
#define __ChemEngine__Element__

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <assert.h>

class Element
{
public:
    typedef std::unordered_map<unsigned int, Element*> BondsMap;
    
    Element(const std::string _name);

    const std::string& Name() const             { return name; }
    unsigned int InstanceID() const             { return instanceID; }
    unsigned int FreeElectrons() const          { return freeElectrons; }
    
    BondsMap::iterator Begin()                  { return bonds.begin(); }
    BondsMap::const_iterator Begin() const      { return bonds.begin(); }
    BondsMap::iterator End()                    { return bonds.end(); }
    BondsMap::const_iterator End() const        { return bonds.end(); }
    
    bool CreateBond(Element* element, bool bidirectional = true);
    bool DetachBond(const unsigned int ID, bool bidirectional = true);
    unsigned int BondCount() const              { return bondCount; }
    
private:
    const unsigned int instanceID;
    std::string name;
    unsigned int freeElectrons;
    BondsMap bonds;
    unsigned int bondCount;
    
    static unsigned int nextInstanceID;
};

#endif /* defined(__ChemEngine__Element__) */
