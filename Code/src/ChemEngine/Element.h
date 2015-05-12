//
//  Element.h
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#ifndef __ChemEngine__Element__
#define __ChemEngine__Element__

#include <string>
#include <vector>
#include <memory>

class ElementFactory;

class Element
{
    friend class ElementFactory;
    
private:
    std::string name;
    unsigned int instanceID;
    unsigned int freeElectrons;
    std::vector<std::shared_ptr<Element>> bonds;
    
    Element(const std::string _name,
            const unsigned int _instanceID,
            const unsigned int _freeElectrons);
    
public:
    std::string Name() const                { return name; }
    unsigned int InstanceID() const         { return instanceID; }
    unsigned int FreeElectrons() const      { return freeElectrons; }
    
    bool createBond(std::shared_ptr<Element> element);
    bool detachBond(const unsigned int ID);
};

#endif /* defined(__ChemEngine__Element__) */
