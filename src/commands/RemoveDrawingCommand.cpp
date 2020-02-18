#include "RemoveDrawingCommand.hpp"
#include "DrawingManager.hpp"


namespace vizkit3dDebugDrawings
{
void RemoveDrawingCommand::execute(DrawingManager* drawingManager) const
{
    drawingManager->removeDrawing(getDrawingChannel());
}

RemoveDrawingCommand::RemoveDrawingCommand(const std::string& drawingChannel) :
        Command(drawingChannel)
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

