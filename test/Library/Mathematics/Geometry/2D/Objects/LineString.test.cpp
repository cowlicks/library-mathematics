////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/2D/Objects/LineString.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/2D/Transformation.hpp>
#include <Library/Mathematics/Geometry/2D/Objects/LineString.hpp>
#include <Library/Mathematics/Geometry/2D/Objects/Segment.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, Constructor)
{

    using library::math::geom::d2::objects::Point ;
    using library::math::geom::d2::objects::LineString ;

    {

        EXPECT_NO_THROW(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } })) ;

    }

    {

        EXPECT_NO_THROW(LineString({ { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 } })) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, Clone)
{

    using library::math::geom::d2::objects::LineString ;

    {

        EXPECT_NO_THROW(const LineString* lineStringPtr = LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).clone() ; delete lineStringPtr ;) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, EqualToOperator)
{

    using library::math::geom::d2::objects::LineString ;
    
    {

        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } })) ;

        EXPECT_TRUE(LineString::Empty() == LineString::Empty()) ;

    }

    {

        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 0.0 }, { 0.0, 2.0 }, { 0.0, 1.0 } })) ;
        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 1.0 }, { 0.0, 0.0 }, { 0.0, 2.0 } })) ;
        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 1.0 }, { 0.0, 2.0 }, { 0.0, 0.0 } })) ;
        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 2.0 }, { 0.0, 0.0 }, { 0.0, 1.0 } })) ;
        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 2.0 }, { 0.0, 1.0 }, { 0.0, 0.0 } })) ;
        
        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } })) ;

        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 0.0, 3.0 } })) ;

    }

    {

        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) == LineString::Empty()) ;
        EXPECT_FALSE(LineString::Empty() == LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } })) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, NotEqualToOperator)
{

    using library::math::geom::d2::objects::LineString ;

    {

        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } })) ;

        EXPECT_FALSE(LineString::Empty() != LineString::Empty()) ;

    }

    {

        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 0.0 }, { 0.0, 2.0 }, { 0.0, 1.0 } })) ;
        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 1.0 }, { 0.0, 0.0 }, { 0.0, 2.0 } })) ;
        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 1.0 }, { 0.0, 2.0 }, { 0.0, 0.0 } })) ;
        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 2.0 }, { 0.0, 0.0 }, { 0.0, 1.0 } })) ;
        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 2.0 }, { 0.0, 1.0 }, { 0.0, 0.0 } })) ;
        
        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } })) ;

        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 0.0, 3.0 } })) ;

    }

    {

        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) != LineString::Empty()) ;
        EXPECT_TRUE(LineString::Empty() != LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } })) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, StreamOperator)
{

    using library::math::geom::d2::objects::LineString ;
    
    {

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }) << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, IsDefined)
{

    using library::math::geom::d2::objects::LineString ;
    
    {

        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).isDefined()) ;
        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 } }).isDefined()) ;

    }

    {

        EXPECT_FALSE(LineString::Empty().isDefined()) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, IsEmpty)
{

    using library::math::geom::d2::objects::LineString ;
    
    {

        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).isEmpty()) ;
        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 0.0 }, { 0.0, 0.0 } }).isEmpty()) ;

    }

    {

        EXPECT_TRUE(LineString::Empty().isEmpty()) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, IsNear)
{

    using library::core::types::Real ;
    
    using library::math::geom::d2::objects::LineString ;
    
    {

        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).isNear(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }), Real::Epsilon())) ;
        
        EXPECT_TRUE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).isNear(LineString({ { 0.0, Real::Epsilon() }, { Real::Epsilon(), 1.0 }, { 1.0, 0.0 } }), Real::Epsilon())) ;

    }

    {

        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).isNear(LineString({ { 0.0, 2.0 * Real::Epsilon() }, { Real::Epsilon(), 1.0 }, { 1.0, 0.0 } }), Real::Epsilon())) ;

    }

    {

        EXPECT_FALSE(LineString::Empty().isNear(LineString::Empty(), Real::Epsilon())) ;
        EXPECT_FALSE(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).isNear(LineString::Empty(), Real::Epsilon())) ;
        EXPECT_FALSE(LineString::Empty().isNear(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }), Real::Epsilon())) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, AccessPointAt)
{

    using library::math::geom::d2::objects::Point ;
    using library::math::geom::d2::objects::LineString ;

    {

        EXPECT_EQ(Point(0.0, 0.0), LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, 0.0 } }).accessPointAt(0)) ;
        EXPECT_EQ(Point(0.0, 1.0), LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, 0.0 } }).accessPointAt(1)) ;
        EXPECT_EQ(Point(1.0, 0.0), LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, 0.0 } }).accessPointAt(2)) ;
        EXPECT_EQ(Point(0.0, 0.0), LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, 0.0 } }).accessPointAt(3)) ;
        
        EXPECT_ANY_THROW(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, 0.0 } }).accessPointAt(5)) ;

    }

    {

        EXPECT_ANY_THROW(LineString::Empty().accessPointAt(0)) ;
        EXPECT_ANY_THROW(LineString::Empty().accessPointAt(1)) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, GetPointCount)
{

    using library::math::geom::d2::objects::LineString ;

    {

        EXPECT_EQ(4, LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, 0.0 } }).getPointCount()) ;

    }

    {

        EXPECT_EQ(0, LineString::Empty().getPointCount()) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, ToString)
{

    using library::math::geom::d2::objects::Point ;
    using library::math::geom::d2::objects::LineString ;

    {

        EXPECT_EQ("[[0.0, 0.0] -> [0.0, 1.0] -> [1.0, 0.0]]", LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).toString()) ;
        EXPECT_EQ("[[0.0, 0.0] -> [0.0, 1.0] -> [1.0, 0.0]]", LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).toString(Point::Format::Standard)) ;
        EXPECT_EQ("LINESTRING(0.0 0.0, 0.0 1.0, 1.0 0.0)", LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).toString(Point::Format::WKT)) ;

    }

    {

        EXPECT_EQ("[[0.0000000000, 0.0000000000] -> [0.0000000000, 1.0000000000] -> [1.0000000000, 0.0000000000]]", LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).toString(Point::Format::Standard, 10)) ;
        EXPECT_EQ("LINESTRING(0.0000000000 0.0000000000, 0.0000000000 1.0000000000, 1.0000000000 0.0000000000)", LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).toString(Point::Format::WKT, 10)) ;

    }

    {

        EXPECT_EQ("[]", LineString::Empty().toString()) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, ConstIterator)
{

    using library::core::types::Index ;

    using library::math::geom::d2::objects::LineString ;

    {

        const LineString lineString = { { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } } } ;

        Index count = 0 ;

        for (const auto& point : lineString)
        {

            EXPECT_TRUE(point.isDefined()) ;

            count++ ;

        }

        EXPECT_EQ(3, count) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, ApplyTransformation)
{

    using library::math::obj::Vector2d ;
    using library::math::geom::d2::objects::Point ;
    using library::math::geom::d2::objects::LineString ;
    using library::math::geom::d2::Transformation ;

    // Translation

    {

        LineString lineString = { { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } } } ;

        lineString.applyTransformation(Transformation::Translation({ 4.0, 5.0 })) ;

        EXPECT_EQ(LineString({ { 4.0, 5.0 }, { 4.0, 6.0 }, { 5.0, 5.0 } }), lineString) << lineString ;

    }

    {

        EXPECT_ANY_THROW(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 } }).applyTransformation(Transformation::Undefined())) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, Empty)
{

    using library::math::geom::d2::objects::LineString ;
    
    {

        EXPECT_NO_THROW(LineString::Empty()) ;
        EXPECT_FALSE(LineString::Empty().isDefined()) ;

    }

}

TEST (Library_Mathematics_Geometry_2D_Objects_LineString, Segment)
{

    using library::math::geom::d2::objects::Segment ;
    using library::math::geom::d2::objects::LineString ;
    
    {

        EXPECT_EQ(LineString({ { 0.0, 0.0 }, { 0.0, 1.0 } }), LineString::Segment(Segment({ 0.0, 0.0 }, { 0.0, 1.0 }))) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////