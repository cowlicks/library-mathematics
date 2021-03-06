////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/3D/Transformation.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Mathematics_Geometry_3D_Transformation__
#define __Library_Mathematics_Geometry_3D_Transformation__

#include <Library/Mathematics/Geometry/3D/Transformations/Rotations/RotationVector.hpp>
#include <Library/Mathematics/Geometry/3D/Objects/Point.hpp>
#include <Library/Mathematics/Geometry/3D/Object.hpp>
#include <Library/Mathematics/Geometry/Angle.hpp>
#include <Library/Mathematics/Objects/Vector.hpp>

#include <Library/Core/Types/String.hpp>
#include <Library/Core/Types/Unique.hpp>

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

class Transformation ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Unique ;
using library::core::types::String ;

using library::math::obj::Vector3d ;
using library::math::obj::Vector4d ;
using library::math::obj::Matrix4d ;
using library::math::geom::Angle ;
using library::math::geom::d3::Object ;
using library::math::geom::d3::objects::Point ;
using library::math::geom::d3::trf::rot::RotationVector ;
using library::math::geom::d3::trf::rot::RotationMatrix ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Transformation
{

    public:

        enum class Type
        {

            Undefined,
            Identity,
            Translation,
            Rotation,
            Scaling,
            Reflection,
            Shear,
            Affine

        } ;

        /// @brief              Constructor
        ///
        /// @param              [in] aMatrix A transformation matrix

                                Transformation                              (   const   Matrix4d&                   aMatrix                                     ) ;

        bool                    operator ==                                 (   const   Transformation&             aTransformation                             ) const ;

        bool                    operator !=                                 (   const   Transformation&             aTransformation                             ) const ;

        Transformation          operator *                                  (   const   Transformation&             aTransformation                             ) const ;

        Vector4d                operator *                                  (   const   Vector4d&                   aVector                                     ) const ;

        Transformation&         operator *=                                 (   const   Transformation&             aTransformation                             ) ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Transformation&             aTransformation                             ) ;

        bool                    isDefined                                   ( ) const ;

        bool                    isIdentity                                  ( ) const ;

        /// @brief              Returns true if transformation is rigid
        ///
        ///                     A rigid transformation preserves the Euclidean distance between every pair of points.
        ///                     The rigid transformations include rotations, translations, reflections, or their combination.
        ///
        /// @ref                https://en.wikipedia.org/wiki/Rigid_transformation
        ///
        /// @return             True if transformation is rigid

        bool                    isRigid                                     ( ) const ;

        Transformation::Type    getType                                     ( ) const ;

        Matrix4d                getMatrix                                   ( ) const ;

        Transformation          getInverse                                  ( ) const ;

        Point                   applyTo                                     (   const   Point&                      aPoint                                      ) const ;
        
        Vector3d                applyTo                                     (   const   Vector3d&                   aVector                                     ) const ;

        /// @brief              Print transformation
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] (optional) displayDecorators If true, display decorators

        virtual void            print                                       (           std::ostream&               anOutputStream,
                                                                                        bool                        displayDecorators                           =   true ) const ;

        static Transformation   Undefined                                   ( ) ;
        
        static Transformation   Identity                                    ( ) ;
        
        static Transformation   Translation                                 (   const   Vector3d&                   aTranslationVector                          ) ;
        
        static Transformation   Rotation                                    (   const   RotationVector&             aRotationVector                             ) ;

        static Transformation   Rotation                                    (   const   RotationMatrix&             aRotationMatrix                             ) ;

        static Transformation   RotationAround                              (   const   Point&                      aPoint,
                                                                                const   RotationVector&             aRotationVector                             ) ;

        static String           StringFromType                              (   const   Transformation::Type&       aType                                       ) ;

        static Transformation::Type TypeOfMatrix                            (   const   Matrix4d&                   aMatrix                                     ) ;

        static bool             IsRigid                                     (   const   Matrix4d&                   aMatrix                                     ) ;

    private:

        Transformation::Type    type_ ;
        Matrix4d                matrix_ ;
        
        bool                    isRigid_ ;

                                Transformation                              (   const   Transformation::Type&       aType,
                                                                                const   Matrix4d&                   aMatrix,
                                                                                const   bool                        isRigid                                     ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////