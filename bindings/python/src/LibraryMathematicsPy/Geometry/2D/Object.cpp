////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           LibraryMathematicsPy/Geometry/2D/Object.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/2D/Object.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryMathematicsPy_Geometry_2D_Object     ( )
{

    using namespace boost::python ;

    using library::math::geom::d2::Object ;

    scope in_Object = class_<Object, boost::noncopyable>("Object", no_init)

        .def(self == self)
        .def(self != self)

        .def(self_ns::str(self_ns::self))
        .def(self_ns::repr(self_ns::self))

        .def("isDefined", &Object::isDefined)
        .def("intersects", &Object::intersects)
        .def("contains", &Object::contains)
        
        .def("toString", &Object::toString)
        .def("applyTransformation", &Object::applyTransformation)

    ;

    enum_<Object::Format>("Format")
    
        .value("Undefined", Object::Format::Undefined)
        .value("Standard", Object::Format::Standard)
        .value("WKT", Object::Format::WKT)
    
    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////