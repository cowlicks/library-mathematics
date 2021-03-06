////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/2D/Objects/Point.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/2D/Transformation.hpp>
#include <Library/Mathematics/Geometry/2D/Objects/Point.hpp>

#include <Library/Core/Error.hpp>
#include <Library/Core/Utilities.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace math
{
namespace geom
{
namespace d2
{
namespace objects
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Point::Point                                (   const   Real&                       aFirstCoordinate,
                                                                                const   Real&                       aSecondCoordinate                           )
                                :   Object(),
                                    x_(aFirstCoordinate),
                                    y_(aSecondCoordinate)
{
    
}

Point*                          Point::clone                                ( ) const
{
    return new Point(*this) ;
}

bool                            Point::operator ==                          (   const   Point&                      aPoint                                      ) const
{

    if ((!this->isDefined()) || (!aPoint.isDefined()))
    {
        return false ;
    }

    return (x_ == aPoint.x_) && (y_ == aPoint.y_) ;

}

bool                            Point::operator !=                          (   const   Point&                      aPoint                                      ) const
{
    return !((*this) == aPoint) ;
}

Point                           Point::operator +                           (   const   Vector2d&                   aVector                                     ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    if (!aVector.isDefined())
    {
        throw library::core::error::runtime::Undefined("Vector") ;
    }

    return { x_ + aVector.x(), y_ + aVector.y() } ;
    
}

Point                           Point::operator -                           (   const   Vector2d&                   aVector                                     ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    if (!aVector.isDefined())
    {
        throw library::core::error::runtime::Undefined("Vector") ;
    }
    
    return { x_ - aVector.x(), y_ - aVector.y() } ;

}
        
Vector2d                        Point::operator -                           (   const   Point&                      aPoint                                      ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    if (!aPoint.isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    return { x_ - aPoint.x_, y_ - aPoint.y_ } ;

}

bool                            Point::isDefined                            ( ) const
{
    return x_.isDefined() && y_.isDefined() ;
}

bool                            Point::isNear                               (   const   Point&                      aPoint,
                                                                                const   Real&                       aTolerance                                  ) const
{

    if (!aTolerance.isDefined())
    {
        throw library::core::error::runtime::Undefined("Tolerance") ;
    }

    return this->distanceTo(aPoint) <= aTolerance ;

}

const Real&                     Point::x                                    ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }
    
    return x_ ;

}

const Real&                     Point::y                                    ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }
    
    return y_ ;

}

Vector2d                        Point::asVector                             ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }
    
    return { x_, y_ } ;

}

Real                            Point::distanceTo                           (   const   Point&                      aPoint                                      ) const
{

    if (!aPoint.isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    return ((*this) - aPoint).norm() ;

}

String                          Point::toString                             (   const   Object::Format&             aFormat,
                                                                                const   Integer&                    aPrecision                                  ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    switch (aFormat)
    {

        case Object::Format::Standard:
            return String::Format("[{}, {}]", x_.toString(aPrecision), y_.toString(aPrecision)) ;

        case Object::Format::WKT:
            return String::Format("POINT({} {})", x_.toString(aPrecision), y_.toString(aPrecision)) ;

        default:
            throw library::core::error::runtime::Wrong("Format") ;
            break ;

    }

    return String::Empty() ;
   
}

void                            Point::print                                (           std::ostream&               anOutputStream,
                                                                                        bool                        displayDecorators                           ) const
{

    displayDecorators ? library::core::utils::Print::Header(anOutputStream, "Point") : void () ;

    library::core::utils::Print::Line(anOutputStream) << "X:"                   << (x_.isDefined() ? x_.toString() : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "Y:"                   << (y_.isDefined() ? y_.toString() : "Undefined") ;

    displayDecorators ? library::core::utils::Print::Footer(anOutputStream) : void () ;

}

void                            Point::applyTransformation                  (   const   Transformation&             aTransformation                             )
{

    if (!aTransformation.isDefined())
    {
        throw library::core::error::runtime::Undefined("Transformation") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    (*this) = aTransformation.applyTo(*this) ;

}

Point                           Point::Undefined                            ( )
{
    return { Real::Undefined(), Real::Undefined() } ;
}

Point                           Point::Origin                               ( )
{
    return { 0.0, 0.0 } ;
}

Point                           Point::Vector                               (   const   Vector2d&                   aVector                                     )
{
    return { aVector.x(), aVector.y() } ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////