////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           LibraryMathematicsPy/Geometry/2D/Objects/PointSet.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/2D/Objects/PointSet.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryMathematicsPy_Geometry_2D_Objects_PointSet ( )
{

    using namespace boost::python ;

    using library::core::ctnr::Array ;
    
    using library::math::geom::d2::Object ;
    using library::math::geom::d2::objects::Point ;
    using library::math::geom::d2::objects::PointSet ;

    scope in_PointSet = class_<PointSet, bases<Object>>("PointSet", init<const Array<Point>&>())

        .def(self == self)
        .def(self != self)

        .def(self_ns::str(self_ns::self))
        .def(self_ns::repr(self_ns::self))

        .def("isDefined", &PointSet::isDefined)
        .def("isEmpty", &PointSet::isEmpty)
        .def("isNear", &PointSet::isNear)

        .def("getSize", &PointSet::getSize)
        .def("getPointClosestTo", &PointSet::getPointClosestTo)
        .def("toString", &PointSet::toString)
        .def("translate", &PointSet::translate)
        
        .def("Empty", &PointSet::Empty).staticmethod("Empty")

        .def("__iter__", boost::python::range(static_cast<PointSet::ConstIterator (PointSet::*)() const> (&PointSet::begin), static_cast<PointSet::ConstIterator (PointSet::*)() const> (&PointSet::end)))

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////