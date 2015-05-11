//
//  ChemEngine.h
//  ChemEngine
//
//  Created by David Hanna on 2015-05-10.
//
//

#ifndef __ChemEngine__
#define __ChemEngine__

#include <memory>

class Mixture; // todo

class ChemEngine
{
private:
    std::shared_ptr<Mixture> input, output;
    
public:
    ChemEngine()  {}
    ~ChemEngine() {}
    
    void setInput(std::shared_ptr<Mixture> _input) { input = _input; }
    std::shared_ptr<Mixture> getInput() { return input; }
    
    void Mix();
    
    std::shared_ptr<Mixture> getOutput() { return output; }
};

#endif /* defined(__ChemEngine__) */