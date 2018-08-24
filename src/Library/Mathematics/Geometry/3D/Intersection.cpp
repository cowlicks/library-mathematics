////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/3D/Intersection.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/3D/Intersection.hpp>

#include <Library/Core/Error.hpp>
#include <Library/Core/Utilities.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace math
{
namespace geom
{
namespace d3
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Intersection::Intersection                  (   const   Array<Unique<Object>>&      anObjectArray                               )
                                :   type_(Intersection::TypeFromObjects(anObjectArray)),
                                    objects_(Array<Unique<Object>>::Empty())
{

    objects_.reserve(anObjectArray.getSize()) ;
    std::transform(anObjectArray.begin(), anObjectArray.end(), std::back_inserter(objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

}

                                Intersection::Intersection                  (   const   Intersection&               anIntersection                              )
                                :   type_(anIntersection.type_),
                                    objects_(Array<Unique<Object>>::Empty())
{

    objects_.reserve(anIntersection.objects_.getSize()) ;
    std::transform(anIntersection.objects_.begin(), anIntersection.objects_.end(), std::back_inserter(objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

}

                                Intersection::~Intersection                 ( )
{

}

Intersection&                   Intersection::operator =                    (   const   Intersection&               anIntersection                              )
{

    if (this != &anIntersection)
    {

        type_ = anIntersection.type_ ;

        objects_.clear() ;
        objects_.reserve(anIntersection.objects_.getSize()) ;
        std::transform(anIntersection.objects_.begin(), anIntersection.objects_.end(), std::back_inserter(objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

    }

    return (*this) ;

}

bool                            Intersection::operator ==                   (   const   Intersection&               anIntersection                              ) const
{

    if ((!this->isDefined()) || (!anIntersection.isDefined()))
    {
        return false ;
    }

    if (type_ != anIntersection.type_)
    {
        return false ;
    }

    // [TBI]

    throw library::core::error::runtime::ToBeImplemented("Intersection :: operator ==") ;

    return false ;

}

bool                            Intersection::operator !=                   (   const   Intersection&               anIntersection                              ) const
{
    return !((*this) == anIntersection) ;
}

bool                            Intersection::isDefined                     ( ) const
{
    return type_ != Intersection::Type::Undefined ;
}

bool                            Intersection::isEmpty                       ( ) const
{
    return type_ == Intersection::Type::Empty ;
}

Intersection::Type              Intersection::getType                       ( ) const
{
    return type_ ;
}

Intersection                    Intersection::Undefined                     ( )
{
    
    Intersection intersection = { Array<Unique<Object>>::Empty() } ;

    intersection.type_ = Intersection::Type::Undefined ;

    return intersection ;

}

Intersection                    Intersection::Empty                         ( )
{
    return Intersection(Array<Unique<Object>>::Empty()) ;
}

Intersection::Type              Intersection::TypeFromObjects               (   const   Array<Unique<Object>>&      anObjectArray                               )
{

    if (anObjectArray.isEmpty())
    {
        return Intersection::Type::Empty ;
    }

    Intersection::Type type = Intersection::Type::Undefined ;

    for (const auto& objectUPtr : anObjectArray)
    {

        const Intersection::Type objectType = Intersection::TypeFromObject(objectUPtr) ;

        if (type == Intersection::Type::Undefined)
        {
            type = objectType ;
        }
        else if (type != objectType)
        {
            return Intersection::Type::Complex ;
        }

    }

    return type ;

}

Intersection::Type              Intersection::TypeFromObject                (   const   Unique<Object>&             anObjectUPtr                                )
{

    if (dynamic_cast<const Point*>(anObjectUPtr.get()))
    {
        return Intersection::Type::Point ;
    }

    // if (dynamic_cast<PointSet*>(anObjectUPtr.get()))
    // {
    //     return Intersection::Type::PointSet ;
    // }

    // [TBI]

    if (dynamic_cast<Segment*>(anObjectUPtr.get()))
    {
        return Intersection::Type::Segment ;
    }

    if (dynamic_cast<Sphere*>(anObjectUPtr.get()))
    {
        return Intersection::Type::Sphere ;
    }

    if (dynamic_cast<Ellipsoid*>(anObjectUPtr.get()))
    {
        return Intersection::Type::Ellipsoid ;
    }

    return Intersection::Type::Undefined ;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////