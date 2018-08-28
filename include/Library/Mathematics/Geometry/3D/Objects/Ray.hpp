////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/3D/Objects/Ray.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Mathematics_Geometry_3D_Objects_Ray__
#define __Library_Mathematics_Geometry_3D_Objects_Ray__

#include <Library/Mathematics/Geometry/3D/Objects/Point.hpp>
#include <Library/Mathematics/Geometry/3D/Object.hpp>

#include <Library/Core/Types/Real.hpp>

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

using library::core::types::Real ;

using library::math::obj::Vector3d ;
using library::math::geom::d3::Object ;
using library::math::geom::d3::objects::Point ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Line ;
class Segment ;
class Plane ;
class Polygon ;
class Sphere ;
class Ellipsoid ;
class Pyramid ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Ray
///
/// @ref                        https://en.wikipedia.org/wiki/Line_(geometry)#Ray

class Ray : public Object
{

    public:

        /// @brief              Constructor
        ///
        /// @code
        ///                     Ray ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }) ;
        /// @endcode
        ///
        /// @param              [in] anOrigin A ray origin
        /// @param              [in] aDirection A ray direction

                                Ray                                         (   const   Point&                      anOrigin,
                                                                                const   Vector3d&                   aDirection                                  ) ;

        /// @brief              Clone ray
        ///
        /// @return             Pointer to cloned ray

        virtual Ray*            clone                                       ( ) const override ;

        /// @brief              Equal to operator
        ///
        /// @code
        ///                     Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }) == Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }) ; // True
        /// @endcode
        ///
        /// @param              [in] aRay A ray
        /// @return             True if rays are equal

        bool                    operator ==                                 (   const   Ray&                        aRay                                        ) const ;

        /// @brief              Not equal to operator
        ///
        /// @code
        ///                     Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }) != Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 2.0 }) ; // True
        /// @endcode
        ///
        /// @param              [in] aRay A ray
        /// @return             True if rays not are equal

        bool                    operator !=                                 (   const   Ray&                        aRay                                        ) const ;

        /// @brief              Output stream operator
        ///
        /// @code
        ///                     std::cout << Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }) ;
        /// @endcode
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] aRay A ray
        /// @return             A reference to output stream

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Ray&                        aRay                                        ) ;

        /// @brief              Check if ray is defined
        ///
        /// @code
        ///                     Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }).isDefined() ; // True
        /// @endcode
        ///
        /// @return             True if ray is defined

        virtual bool            isDefined                                   ( ) const override ;

        /// @brief              Check if ray intersects point
        ///
        /// @code
        ///                     Ray ray = ... ;
        ///                     Point point = ... ;
        ///                     ray.intersects(point) ;
        /// @endcode
        ///
        /// @param              [in] anPoint An point
        /// @return             True if ray intersects point
        
        bool                    intersects                                  (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Check if ray intersects ellipsoid
        ///
        /// @code
        ///                     Ray ray = ... ;
        ///                     Ellipsoid ellipsoid = ... ;
        ///                     ray.intersects(ellipsoid) ;
        /// @endcode
        ///
        /// @param              [in] anEllipsoid An ellipsoid
        /// @return             True if ray intersects ellipsoid
        
        bool                    intersects                                  (   const   Ellipsoid&                  anEllipsoid                                 ) const ;

        /// @brief              Check if ray contains point
        ///
        /// @code
        ///                     Ray ray = ... ;
        ///                     Ellipsoid ellipsoid = ... ;
        ///                     ray.contains(ellipsoid) ;
        /// @endcode
        ///
        /// @param              [in] anEllipsoid An ellipsoid
        /// @return             True if ray contains point

        bool                    contains                                    (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Get ray origin
        ///
        /// @code
        ///                     Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }).getOrigin() ; // [0.0, 0.0, 0.0]
        /// @endcode
        ///
        /// @return             Ray origin

        Point                   getOrigin                                   ( ) const ;

        /// @brief              Get ray direction
        ///
        /// @code
        ///                     Ray({ 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }).getDirection() ; // [0.0, 0.0, 1.0]
        /// @endcode
        ///
        /// @return             Ray direction

        Vector3d                getDirection                                ( ) const ;

        /// @brief              Translate ray
        ///
        /// @param              [in] aTranslation A translation vector

        virtual void            translate                                   (   const   Vector3d&                   aTranslation                                ) override ;

        /// @brief              Rotate ray
        ///
        /// @param              [in] aRotation A rotation quaternion
        
        virtual void            rotate                                      (   const   Quaternion&                 aRotation                                   ) override ;

        /// @brief              Constructs an undefined ray
        ///
        /// @code
        ///                     Ray ray = Ray::Undefined() ; // Undefined
        /// @endcode
        ///
        /// @return             Undefined ray

        static Ray              Undefined                                   ( ) ;

    private:

        Point                   origin_ ;
        Vector3d                direction_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////