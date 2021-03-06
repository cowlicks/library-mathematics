////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/2D/Objects/Polygon.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Mathematics_Geometry_2D_Objects_Polygon__
#define __Library_Mathematics_Geometry_2D_Objects_Polygon__

#include <Library/Mathematics/Geometry/2D/Objects/LineString.hpp>
#include <Library/Mathematics/Geometry/2D/Objects/Segment.hpp>
#include <Library/Mathematics/Geometry/2D/Objects/PointSet.hpp>
#include <Library/Mathematics/Geometry/2D/Objects/Point.hpp>
#include <Library/Mathematics/Geometry/2D/Object.hpp>

#include <Library/Core/Containers/Array.hpp>
#include <Library/Core/Types/Size.hpp>
#include <Library/Core/Types/Index.hpp>
#include <Library/Core/Types/Unique.hpp>

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

class MultiPolygon ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Unique ;
using library::core::ctnr::Index ;
using library::core::ctnr::Size ;
using library::core::ctnr::Array ;

using library::math::geom::d2::Object ;
using library::math::geom::d2::objects::Point ;
using library::math::geom::d2::objects::Segment ;
using library::math::geom::d2::objects::LineString ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Polygon
///
///                             A plane figure that is bounded by a finite chain of straight line segments closing in a loop
///                             to form a closed polygonal chain or circuit.
///                             These segments are called its edges, and the points where two edges meet are the polygon's vertices.
///
/// @ref                        https://en.wikipedia.org/wiki/Polygon

class Polygon : public Object
{

    public:

        typedef                 Point                                           Vertex ;
        typedef                 Segment                                         Edge ;
        typedef                 LineString                                      Ring ;

        /// @brief              Constructor
        ///
        /// @param              [in] anOuterRing An outer ring
        /// @param              [in] anInnerRingArray An array of inner rings

                                Polygon                                     (   const   Array<Point>&               anOuterRing,
                                                                                const   Array<Array<Point>>&        anInnerRingArray                            =   Array<Array<Point>>::Empty() ) ;

        /// @brief              Constructor
        ///
        /// @param              [in] anOuterRing An outer ring
        /// @param              [in] anInnerRingArray An array of inner rings

                                Polygon                                     (   const   Polygon::Ring&              anOuterRing,
                                                                                const   Array<Polygon::Ring>&       anInnerRingArray                            =   Array<Polygon::Ring>::Empty() ) ;

        /// @brief              Copy constructor
        ///
        /// @param              [in] aPolygon A polygon

                                Polygon                                     (   const   Polygon&                    aPolygon                                    ) ;

        /// @brief              Destructor (virtual)

        virtual                 ~Polygon                                    ( ) override ;

        /// @brief              Copy assignment operator
        ///
        /// @param              [in] aPolygon A polygon
        /// @return             Reference to polygon

        Polygon&                operator =                                  (   const   Polygon&                    aPolygon                                    ) ;

        /// @brief              Clone polygon
        ///
        /// @return             Pointer to cloned polygon

        virtual Polygon*        clone                                       ( ) const override ;

        /// @brief              Equal to operator
        ///
        /// @param              [in] aPolygon A polygon
        /// @return             True if polygons are equal

        bool                    operator ==                                 (   const   Polygon&                    aPolygon                                    ) const ;

        /// @brief              Not equal to operator
        ///
        /// @param              [in] aPolygon A polygon
        /// @return             True if polygons are not equal

        bool                    operator !=                                 (   const   Polygon&                    aPolygon                                    ) const ;

        /// @brief              Check if polygon is defined
        ///
        /// @return             True if polygon is defined

        virtual bool            isDefined                                   ( ) const override ;

        /// @brief              Check if polygon intersects polygon
        ///
        /// @code
        ///                     Polygon polygon = ... ;
        ///                     Polygon anotherPolygon = ... ;
        ///                     polygon.intersects(anotherPolygon) ;
        /// @endcode
        ///
        /// @param              [in] aPolygon A polygon
        /// @return             True if polygon intersects polygon

        bool                    intersects                                  (   const   Polygon&                    aPolygon                                    ) const ;

        /// @brief              Check if polygon contains point
        ///
        /// @code
        ///                     Polygon polygon = ... ;
        ///                     Point point = ... ;
        ///                     polygon.contains(point) ;
        /// @endcode
        ///
        /// @param              [in] aPoint A point
        /// @return             True if polygon contains point

        bool                    contains                                    (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Check if polygon contains point set
        ///
        /// @code
        ///                     Polygon polygon = ... ;
        ///                     PointSet pointSet = ... ;
        ///                     polygon.contains(pointSet) ;
        /// @endcode
        ///
        /// @param              [in] aPointSet A point set
        /// @return             True if polygon contains point set

        bool                    contains                                    (   const   PointSet&                   aPointSet                                   ) const ;

        /// @brief              Get number of inner rings
        ///
        /// @return             Number of inner rings

        Size                    getInnerRingCount                           ( ) const ;

        /// @brief              Get edge count
        ///
        /// @return             Edge count

        Size                    getEdgeCount                                ( ) const ;

        /// @brief              Get vertex count
        ///
        /// @return             Vertex count

        Size                    getVertexCount                              ( ) const ;

        /// @brief              Get outer ring
        ///
        /// @return             Outer ring

        Polygon::Ring           getOuterRing                                ( ) const ;

        /// @brief              Get inner ring at index
        ///
        /// @return             Inner ring at index

        Polygon::Ring           getInnerRingAt                              (   const   Index&                      anInnerRingIndex                            ) const ;

        /// @brief              Get edge at index
        ///
        /// @param              [in] anEdgeIndex An edge index
        /// @return             Edge (segment)

        Polygon::Edge           getEdgeAt                                   (   const   Index                       anEdgeIndex                                 ) const ;

        /// @brief              Get vertex at index
        ///
        /// @param              [in] aVertexIndex A vertex index
        /// @return             Vertex

        Polygon::Vertex         getVertexAt                                 (   const   Index                       aVertexIndex                                ) const ;

        /// @brief              Get polygon edges
        ///
        /// @return             Polygon edges

        Array<Polygon::Edge>    getEdges                                    ( ) const ;

        /// @brief              Get polygon vertices
        ///
        /// @return             Polygon vertices

        Array<Polygon::Vertex>  getVertices                                 ( ) const ;

        /// @brief              Compute intersection of polygon with polygon
        ///
        /// @param              [in] aPolygon A polygon
        /// @return             Intersection of polygon with polygon

        // Intersection            intersectionWith                            (   const   Polygon&                    aPolygon                                    ) const ;

        /// @brief              Compute union of polygon with polygon
        ///
        /// @param              [in] aPolygon A polygon
        /// @return             A multi-polygon

        // MultiPolygon            unionWith                                   (   const   Polygon&                    aPolygon                                    ) const ;

        /// @brief              Get string representation
        ///
        /// @param              [in] aFormat A format
        /// @return             String representation

        virtual String          toString                                    (   const   Object::Format&             aFormat                                     =   Object::Format::Standard,
                                                                                const   Integer&                    aPrecision                                  =   Integer::Undefined() ) const override ;

        /// @brief              Print polygon
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] (optional) displayDecorators If true, display decorators

        virtual void            print                                       (           std::ostream&               anOutputStream,
                                                                                        bool                        displayDecorators                           =   true ) const override ;

        /// @brief              Apply transformation to polygon
        ///
        /// @param              [in] aTransformation A transformation

        virtual void            applyTransformation                         (   const   Transformation&             aTransformation                             ) override ;

        /// @brief              Constructs an undefined polygon
        ///
        /// @code
        ///                     Polygon polygon = Polygon::Undefined() ; // Undefined
        /// @endcode
        ///
        /// @return             Undefined polygon

        static Polygon          Undefined                                   ( ) ;

    private:

        class Impl ;

        Unique<Polygon::Impl>   implUPtr_ ;

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