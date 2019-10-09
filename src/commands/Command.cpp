#include "Command.hpp"
#include <stdexcept>

namespace vizkit3dDebugDrawings
{
void Command::execute(vizkit3dDebugDrawings::DrawingManager* drawingManager) const
{
    //NOTE This method should be pure virtual, however pure virtual classes cannot
    //     be used in orogen.
    throw std::runtime_error("called base class execute()");
}

Command* Command::clone() const
{
    //NOTE This method should be pure virtual, however pure virtual classes cannot
    //     be used in orogen.
    throw std::runtime_error("called base class clone()");
}

const std::string& Command::getDrawingName() const
{
    return drawingGroupName;
}

Command::Command(const std::string& drawingGroupName) : drawingGroupName(drawingGroupName)
{
    
}
Command::Command() : drawingGroupName("default")
{

}



Command::~Command()
{
}

}

