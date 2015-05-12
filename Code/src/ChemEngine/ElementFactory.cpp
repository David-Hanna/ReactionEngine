//
//  ElementFactory.cpp
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#include "ElementFactory.h"

ElementFactory& ElementFactory::instance()
{
    static ElementFactory* instance = new ElementFactory();
    return *instance;
}

std::shared_ptr<Element> ElementFactory::createElement(std::string name)
{
    unsigned int freeElectrons;
    
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
        std::cout << "Unrecognized element name submitted to element factory: " << name << std::endl;
        return NULL;
    }
    
    return std::shared_ptr<Element>(new Element(name, currentID++, freeElectrons));
}