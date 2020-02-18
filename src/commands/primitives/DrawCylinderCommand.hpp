#pragma once
#include "commands/DrawCommand.hpp"
#include <string>
#include <Eigen/Core>
#include "commands/BoostSerializationHelpers.hpp"

namespace osg
{
    class Node;
}

namespace vizkit3dDebugDrawings
{
class DrawCylinderCommand : public DrawCommand
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        // serialize base class information
        ar & boost::serialization::base_object<DrawCommand>(*this);
        ar & position;
        ar & orientation;
        ar & size;
        ar & colorRGBA;
    }
    

    
public:
    DrawCylinderCommand();
    
    DrawCylinderCommand(const std::string& drawingChannel, const Eigen::Vector3d& position,
                     const Eigen::Quaterniond& orientation, const Eigen::Vector3d& size,
                      const Eigen::Vector4d& colorRGBA);
    
    virtual osg::ref_ptr<osgviz::Object> createPrimitive() const;
    
    virtual DrawCylinderCommand* clone() const;
    
private:
    Eigen::Vector3d position;
    Eigen::Quaterniond orientation;
    Eigen::Vector3d size;
    Eigen::Vector4d colorRGBA;

};
}
