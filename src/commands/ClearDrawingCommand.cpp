#include "ClearDrawingCommand.hpp"
#include "DrawingManager.hpp"


namespace vizkit3dDebugDrawings
{
ClearDrawingCommand::ClearDrawingCommand(const std::string& drawingChannel) :
        Command(drawingChannel)
{}

ClearDrawingCommand::ClearDrawingCommand() : Command("default")
{

}


void ClearDrawingCommand::execute(DrawingManager* drawingManager) const
{
    drawingManager->clearDrawing(getDrawingChannel());
}

ClearDrawingCommand::~ClearDrawingCommand()
{}

ClearDrawingCommand* ClearDrawingCommand::clone() const
{
    return new ClearDrawingCommand(*this);
}

}
