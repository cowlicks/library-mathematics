////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/3D/Objects/Composite.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/3D/Transformation.hpp>
#include <Library/Mathematics/Geometry/3D/Intersection.hpp>
#include <Library/Mathematics/Geometry/3D/Objects/Composite.hpp>

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
namespace objects
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Composite::Composite                        (   const   Object&                     anObject                                    )
                                :   Object(),
                                    objects_(Array<Unique<Object>>::Empty())
{

    objects_.emplace_back(Unique<Object>(anObject.clone())) ;

}

                                Composite::Composite                        (   const   Unique<Object>&             anObjectUPtr                                )
                                :   Object(),
                                    objects_(Array<Unique<Object>>::Empty())
{

    objects_.emplace_back(Unique<Object>(anObjectUPtr->clone())) ;

}

                                Composite::Composite                        (           Array<Unique<Object>>&&     anObjectArray                               )
                                :   Object(),
                                    objects_(Array<Unique<Object>>::Empty())
{

    objects_.reserve(anObjectArray.getSize()) ;

    std::transform(anObjectArray.begin(), anObjectArray.end(), std::back_inserter(objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

}

                                Composite::Composite                        (   const   Composite&                  aComposite                                  )
                                :   Object(),
                                    objects_(Array<Unique<Object>>::Empty())
{

    objects_.reserve(aComposite.objects_.getSize()) ;

    std::transform(aComposite.objects_.begin(), aComposite.objects_.end(), std::back_inserter(objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

}

Composite*                      Composite::clone                            ( ) const
{
    return new Composite(*this) ;
}

Composite&                      Composite::operator =                       (   const   Composite&                  aComposite                                  )
{

    if (this != &aComposite)
    {

        objects_.clear() ;

        objects_.reserve(aComposite.objects_.getSize()) ;

        std::transform(aComposite.objects_.begin(), aComposite.objects_.end(), std::back_inserter(objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

    }

    return *this ;

}

bool                            Composite::operator ==                      (   const   Composite&                  aComposite                                  ) const
{

    if ((!this->isDefined()) || (!aComposite.isDefined()))
    {
        return false ;
    }

    if (objects_.getSize() != aComposite.objects_.getSize())
    {
        return false ;
    }

    for (const auto objectTuple : library::core::ctnr::iterators::Zip(objects_, aComposite.objects_))
    {

        if ((*std::get<0>(objectTuple)) != (*std::get<1>(objectTuple)))
        {
            return false ;
        }

    }

    return true ;

}

bool                            Composite::operator !=                      (   const   Composite&                  aComposite                                  ) const
{
    return !((*this) == aComposite) ;
}

Composite                       Composite::operator +                       (   const   Composite&                  aComposite                                  ) const
{

    if (!aComposite.isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    Composite composite = Composite::Undefined() ;

    composite.objects_.reserve(objects_.getSize() + aComposite.objects_.getSize()) ;
    
    std::transform(objects_.begin(), objects_.end(), std::back_inserter(composite.objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;
    std::transform(aComposite.objects_.begin(), aComposite.objects_.end(), std::back_inserter(composite.objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

    return composite ;

}

Composite&                      Composite::operator +=                      (   const   Composite&                  aComposite                                  )
{

    if (!aComposite.isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    objects_.reserve(objects_.getSize() + aComposite.objects_.getSize()) ;
    
    std::transform(aComposite.objects_.begin(), aComposite.objects_.end(), std::back_inserter(objects_), [] (const Unique<Object>& anObjectUPtr) -> Unique<Object> { return Unique<Object>(anObjectUPtr->clone()) ; }) ;

    return *this ;

}

bool                            Composite::isDefined                        ( ) const
{
    return (!objects_.isEmpty()) && std::all_of(objects_.begin(), objects_.end(), [] (const Unique<Object>& anObjectUPtr) -> bool { return anObjectUPtr->isDefined() ; }) ; ;
}

bool                            Composite::intersects                       (   const   Object&                     anObject                                    ) const
{

    if (!anObject.isDefined())
    {
        throw library::core::error::runtime::Undefined("Object") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    return std::any_of(objects_.begin(), objects_.end(), [&anObject] (const Unique<Object>& anObjectUPtr) -> bool { return anObjectUPtr->intersects(anObject) ; }) ;

}

bool                            Composite::intersects                       (   const   Composite&                  aComposite                                  ) const
{

    if (!aComposite.isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    return std::any_of(aComposite.objects_.begin(), aComposite.objects_.end(), [this] (const Unique<Object>& anObjectUPtr) -> bool { return this->intersects(*anObjectUPtr) ; }) ;

}

bool                            Composite::contains                         (   const   Object&                     anObject                                    ) const
{

    if (!anObject.isDefined())
    {
        throw library::core::error::runtime::Undefined("Object") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    return std::all_of(objects_.begin(), objects_.end(), [&anObject] (const Unique<Object>& anObjectUPtr) -> bool { return anObjectUPtr->contains(anObject) ; }) ;

}

bool                            Composite::contains                         (   const   Composite&                  aComposite                                  ) const
{

    if (!aComposite.isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    return std::all_of(aComposite.objects_.begin(), aComposite.objects_.end(), [this] (const Unique<Object>& anObjectUPtr) -> bool { return this->contains(*anObjectUPtr) ; }) ;

}

const Object&                   Composite::accessObjectAt                   (   const   Index&                      anIndex                                     ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    if (anIndex >= objects_.getSize())
    {
        throw library::core::error::RuntimeError("Object index [{}] out of bounds [{}].", anIndex, objects_.getSize()) ;
    }

    return *(objects_.at(anIndex).get()) ;

}

const Array<Unique<Object>>&    Composite::accessObjects                    ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }
    
    return objects_ ;

}

Size                            Composite::getObjectCount                   ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }
    
    return objects_.getSize() ;

}

Intersection                    Composite::intersectionWith                 (   const   Object&                     anObject                                    ) const
{

    if (!anObject.isDefined())
    {
        throw library::core::error::runtime::Undefined("Object") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    Intersection intersection = Intersection::Empty() ;

    for (const auto& objectUPtr : objects_)
    {

        const Intersection objectToObjectIntersection = objectUPtr->intersectionWith(anObject) ;

        if (objectToObjectIntersection.isDefined() && (!objectToObjectIntersection.isEmpty()))
        {
            intersection += objectToObjectIntersection ;
        }

    }

    return intersection ;

}

Intersection                    Composite::intersectionWith                 (   const   Composite&                  aComposite                                  ) const
{

    if (!aComposite.isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    Intersection intersection = Intersection::Empty() ;

    for (const auto& objectUPtr : aComposite.objects_)
    {

        const Intersection compositeToObjectIntersection = this->intersectionWith(*objectUPtr) ;

        if (compositeToObjectIntersection.isDefined() && (!compositeToObjectIntersection.isEmpty()))
        {
            intersection += compositeToObjectIntersection ;
        }

    }

    return intersection ;

}

Composite::ConstIterator        Composite::begin                            ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }
    
    return objects_.begin() ;

}

Composite::ConstIterator        Composite::end                              ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }
    
    return objects_.end() ;

}

void                            Composite::print                            (           std::ostream&               anOutputStream,
                                                                                        bool                        displayDecorators                           ) const
{

    displayDecorators ? library::core::utils::Print::Header(anOutputStream, "Composite") : void () ;

    if (!objects_.isEmpty())
    {

        library::core::utils::Print::Separator(anOutputStream, "Objects") ;

        for (const auto& objectUPtr : objects_)
        {
            anOutputStream << (*objectUPtr) ;
        }

    }
    else
    {
        library::core::utils::Print::Line(anOutputStream) << "Empty" ;
    }

    displayDecorators ? library::core::utils::Print::Footer(anOutputStream) : void () ;

}

void                            Composite::applyTransformation              (   const   Transformation&             aTransformation                             )
{

    using library::math::geom::d3::trf::rot::RotationMatrix ;

    if (!aTransformation.isDefined())
    {
        throw library::core::error::runtime::Undefined("Transformation") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("Composite") ;
    }

    if (aTransformation.isIdentity())
    {
        return ;
    }

    for (auto& objectUPtr : objects_)
    {
        objectUPtr->applyTransformation(aTransformation) ;
    }

}

Composite                       Composite::Undefined                        ( )
{   
    return Composite { Array<Unique<Object>>::Empty() } ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////