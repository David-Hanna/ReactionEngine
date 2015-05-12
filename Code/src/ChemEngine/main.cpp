//
//  main.cpp
//  ChemEngine
//
//  Created by David Hanna on 2015-05-11.
//  Copyright (c) 2015 Anon. All rights reserved.
//

#include "ElementFactory.h"
#include "Element.h"

#include <memory>
#include <iostream>

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    
    std::shared_ptr<Element> carbon = ElementFactory::instance().createElement("carbon");
    std::shared_ptr<Element> hydrogen = ElementFactory::instance().createElement("hydrogen");
    
    std::cout << "Carbon's name: " << carbon->Name() << std::endl;
    std::cout << "Carbon's ID: " << carbon->InstanceID() << std::endl;
    std::cout << "Carbon's free electrons: " << carbon->FreeElectrons() << std::endl;
    
    std::cout << "Hydrogen's name: " << hydrogen->Name() << std::endl;
    std::cout << "Hydrogen's ID: " << hydrogen->InstanceID() << std::endl;
    std::cout << "Hydrogen's free electrons: " << hydrogen->FreeElectrons() << std::endl;
    
    return 0;
}
