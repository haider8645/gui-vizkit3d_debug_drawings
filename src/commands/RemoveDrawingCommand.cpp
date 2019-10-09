#include "RemoveDrawingCommand.hpp"
#include <vizkit3d_debug_drawings/DrawingManager.hpp>


namespace vizkit3dDebugDrawings
{
void RemoveDrawingCommand::execute(DrawingManager* drawingManager) const
{
    drawingManager->removeDrawing(getDrawingName());
}

RemoveDrawingCommand::RemoveDrawingCommand(const std::string& drawingGroupName) :
        Command(drawingGroupName)
{}

RemoveDrawingCommand::RemoveDrawingCommand() : Command("default")
{}


RemoveDrawingCommand::~RemoveDrawingCommand()
{}

RemoveDrawingCommand* RemoveDrawingCommand::clone() const
{
    return new RemoveDrawingCommand(*this);
}

}

