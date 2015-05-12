//
//  ElementFactory.h
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#ifndef __ChemEngine__ElementFactory__
#define __ChemEngine__ElementFactory__

#include "Element.h"

#include <iostream>
#include <string>
#include <memory>

class ElementFactory
{
private:
    unsigned int currentID;
    
    ElementFactory() : currentID(0) {}
    
    ElementFactory(const ElementFactory& copy);             // not implemented
    ElementFactory operator=(const ElementFactory& copy);   // not implemented
    
public:
    static ElementFactory& instance();
    std::shared_ptr<Element> createElement(std::string name);
};

#endif /* defined(__ChemEngine__ElementFactory__) */
