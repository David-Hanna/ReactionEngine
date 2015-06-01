//
//  main.cpp
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#include "Element.h"

#include <memory>
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    Element carbon("carbon");
    
    std::vector<Element> hydroVec;
    
    for (int i = 0; i < 5; i++)
    {
        Element hydrogen("hydrogen");
        hydroVec.push_back(hydrogen);
    }
    
    for (std::vector<Element>::iterator iter = hydroVec.begin(); iter != hydroVec.end(); iter++)
    {
        if (carbon.CreateBond(&*iter))
            std::cout << "Successfully created bond." << std::endl;
        else
            std::cout << "Failed to create bond." << std::endl;
    }
    
    for (Element::BondsMap::const_iterator iter = carbon.Begin(); iter != carbon.End(); iter++)
    {
        std::cout << "Bonded with " << iter->second->Name() << " with ID " << iter->second->InstanceID() << std::endl;
    }
    
    for (std::vector<Element>::iterator iter = hydroVec.begin(); iter != hydroVec.end(); iter++)
    {
        if (carbon.DetachBond(iter->InstanceID()))
            std::cout << "Successfully detached bond." << std::endl;
        else
            std::cout << "Failed to detach bond." << std::endl;
    }
    
    if (carbon.BondCount() == 0)
    {
        std::cout << "Carbon has no bonds!" << std::endl;
    }
    else
    {
        for (Element::BondsMap::const_iterator iter = carbon.Begin(); iter != carbon.End(); iter++)
        {
            std::cout << "Bonded with " << iter->second->Name() << " with ID " << iter->second->InstanceID() << std::endl;
        }
    }
    
    return 0;
}
