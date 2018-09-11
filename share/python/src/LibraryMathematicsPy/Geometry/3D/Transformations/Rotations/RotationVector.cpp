////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           LibraryMathematicsPy/Geometry/3D/Transformations/Rotations/RotationVector.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/3D/Transformations/Rotations/RotationVector.hpp>
#include <Library/Mathematics/Geometry/3D/Transformations/Rotations/Quaternion.hpp>
#include <Library/Mathematics/Geometry/3D/Transformations/Rotations/RotationMatrix.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryMathematicsPy_Geometry_3D_Transformations_Rotations_RotationVector ( )
{

    using namespace boost::python ;

    using library::core::types::Real ;
    using library::core::types::String ;
    
    using library::math::obj::Vector3d ;
    using library::math::geom::Angle ;
    using library::math::geom::d3::trf::rot::RotationVector ;

    scope in_RotationVector = class_<RotationVector>("RotationVector", init<Vector3d, Angle>())

        .def(self == self)
        .def(self != self)

        .def(self_ns::str(self_ns::self))
        .def(self_ns::repr(self_ns::self))

        .def("isDefined", &RotationVector::isDefined)
        
        .def("getAxis", &RotationVector::getAxis)
        .def("getAngle", &RotationVector::getAngle)
        .def("toString", &RotationVector::toString)

        .def("Undefined", &RotationVector::Undefined)
        .def("Unit", &RotationVector::Unit).staticmethod("Unit")
        .def("Quaternion", &RotationVector::Quaternion).staticmethod("Quaternion")
        .def("RotationMatrix", &RotationVector::RotationMatrix).staticmethod("RotationMatrix")

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////