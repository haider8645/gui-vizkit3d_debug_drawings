#include "DrawAABBCommand.hpp"
#include <osgViz/modules/viz/Primitives/PrimitivesFactory.h>
#include <osgViz/OsgViz.hpp>


namespace vizkit3dDebugDrawings
{



osg::ref_ptr< osgviz::Object > DrawAABBCommand::createPrimitive() const
{
    auto const & fac = osgviz::OsgViz::getInstance()->getModuleInstance<osgviz::PrimitivesFactory>("PrimitivesFactory");
    const Eigen::Vector3d size = max - min;
    const Eigen::Vector3d center = min + size * 0.5;
    const osg::Vec4 color(colorRGBA[0], colorRGBA[1], colorRGBA[2], colorRGBA[3]);
    
    auto prim = fac->createWireframeBox(size.x(), size.y(), size.z(), center.x(),
                                        center.y(), center.z(), color);
    return prim;
}

DrawAABBCommand::DrawAABBCommand(const std::string& drawingGroupName,
                                 const Eigen::Vector3d& min,
                                 const Eigen::Vector3d& max,
                                 const Eigen::Vector4d& colorRGBA):
        DrawCommand(drawingGroupName), min(min), max(max), colorRGBA(colorRGBA)
{}
 
DrawAABBCommand::DrawAABBCommand(): DrawCommand("default")
{

}

DrawAABBCommand* DrawAABBCommand::clone() const
{
    return new DrawAABBCommand(*this);
}

}
